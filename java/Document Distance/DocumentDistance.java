// An implementation of the cosine document distance algorithm

import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.HashMap;

class DocumentDistance {
    public static void main( String[] args ) throws IOException // bad practice, design flaw, do not do this
    {
        // paths to each document
        String doc1 = "./demoDocuments/1.txt";
        String doc2 = "./demoDocuments/2.txt";
        String doc3 = "./demoDocuments/3.txt";
        String doc4 = "./demoDocuments/4.txt";
        String doc5 = "./demoDocuments/5.txt";
        String doc6 = "./demoDocuments/6.txt";
        String doc7 = "./demoDocuments/7.txt";
        String doc8 = "./demoDocuments/8.txt";
        
        String[] docs = { doc1, doc2, doc3, doc4, doc5, doc6, doc7, doc8 };

        // Compare every document with itself and every other document
        for( int i = 0; i < docs.length; ++i ) {
            for( int j = i; j < docs.length; ++j ) {
                System.out.printf( "Similarity between doc%d and doc%d is %.3f\n",
                                                       (i+1),    (j+1),   similarity( docs[i], docs[j] ) );
                
                // Note the results when comparing with doc5(size = 9.5mb), they indicate
                // that files over a certain limit will cause integer overflows
                // which is going to give wrong results
            }
        }
    }
    
    // compute the similarity between the two documents
    // the output is not a percentage of the shared words
    // but rather a "score" or "rating" of how much words
    // they share. Comparing the output of this algorithm
    // only makes sense with some other output of this same
    // algorithm (kinda like IMDB ratings)
    static double similarity( String doc1Path, String doc2Path ) throws IOException {
        HashMap< String, Integer > doc1Vector = constructDocumentVector( doc1Path );
        HashMap< String, Integer > doc2Vector = constructDocumentVector( doc2Path );

        double innerProduct     = dotProduct(doc1Vector, doc2Vector);
        double magnitudeProduct = magnitude(doc1Vector) * magnitude(doc2Vector);
        double scaledDotProduct = innerProduct / magnitudeProduct;
        
        return scaledDotProduct;
    }
    
    // compute the magnitude of the vector
    static double magnitude( HashMap< String, Integer > docVector ) {
        long sum = 0;
        
        for( String word: docVector.keySet() ) {
            int temp = docVector.get( word );
            sum +=  temp * temp;
        }
        
        return Math.sqrt( sum );
    }
    
    // compute the dot product of the vectors
    static long dotProduct( HashMap< String, Integer > doc1Vector, HashMap< String, Integer > doc2Vector ) {
        long sum = 0;
        
        for( String word: doc1Vector.keySet() ) {
            sum += doc1Vector.get( word ) * doc2Vector.getOrDefault( word, 0 );
        }
        
        return sum;
    }
    
    // split the document into individual words where a word
    // is defined as a sequence of characters delimited by any
    // non-alphanumeric character. Each array element is a token
    static String[] tokenizeDocument( String path ) throws IOException {
        String regex = "[^a-zA-Z0-9]+"; 
        String[] tokens = readFile( path ).split( regex );
        return tokens;
    }
    
    // compute the frequency of each word
    static HashMap< String, Integer > constructDocumentVector( String path ) throws IOException {
        String[] tokenizedDocument = tokenizeDocument( path );
        
        HashMap< String, Integer > documentVector = new HashMap<>( 1000 );
        
        for( String word: tokenizedDocument ) {
                documentVector.put( word, documentVector.getOrDefault( word, 0 ) + 1 );
        }
        
        return documentVector;
    }
    
    // convert the file to a java String
    static String readFile( String path ) throws IOException {
        byte[] encoded = Files.readAllBytes( Paths.get( path ) );
        return new String( encoded, StandardCharsets.US_ASCII );
    }
}


