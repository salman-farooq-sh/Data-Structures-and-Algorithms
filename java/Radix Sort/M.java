import java.util.ArrayList;
import java.util.LinkedList;

public class M {
	public static void main( String[] args ) {
		for( int i = 0; i < 200; i++ ) {
			testSortingAlgo( M::radixSort, i, 1000, false );
		}
	}
	
	private static void testSortingAlgo( SortingAlgorithm algorithm,
										 int inputSize,
										 int numOfTests,
										 boolean enableNegatives ) {
		boolean isStillSorted = true;
		
		for( int i = 0; i < numOfTests; ++i ) {
			Integer[] array = Utils.randomIntArray( inputSize, enableNegatives );
			KeyGenerator keyGenerator = obj -> (int)obj;
			
			algorithm.apply( array, keyGenerator );
			
			isStillSorted = isStillSorted && Utils.isSorted( array, keyGenerator );
			
			if( !isStillSorted ) {
				System.out.print( "Failure on " );
				Utils.printArray( array );
				break;
			}
		}
		
		if( isStillSorted ) {
			System.out.println( "This sorting algorithm rocks!" );
		}
	}
	
	// works on both positive and negative keys
	private static void countingSort( Object[] input, KeyGenerator k, int range, int translationFactor ) {
		if( input.length <= 1 )
			return;
		
		ArrayList< LinkedList<Object> > buckets = new ArrayList<>( range + 1 );
		for( int i = 0; i < range + 1; i++ ) // initialize buckets
			buckets.add( i, new LinkedList<>() );
		
		for( int i = 0; i < input.length; i++ ) // fill buckets
			buckets.get( k.getKey( input[i] ) + translationFactor ).add( input[i] );
		
		LinkedList<Object> outputList = buckets.get( 0 );
		for( int i = 1; i < buckets.size(); i++ ) // collect buckets' contents
			outputList.addAll( buckets.get(i) );
		
		outputList.toArray( input );
	}
	private static void countingSort( Object[] input, KeyGenerator k ) {
		int min = Utils.minKey( input, k );
		int max = Utils.maxKey( input, k );
		int range = max - min;
		int translationFactor = 0 - min;
		
		countingSort( input, k, range, translationFactor );
	}
	
	// works only for positive keys
	private static void radixSort( Object[] input, KeyGenerator k ) {
		if( input.length <= 1 )
			return;
		
		int max = Utils.maxKey( input, k );
		int radix = input.length;
		
		for( int i = 1; i <= numOfDigits( max, radix ); i++ ) {
			final int n = i;
			KeyGenerator k2 = obj->nthDigit( k.getKey( obj ), radix, n ); // gives the "n"-th digit of the key of object
			countingSort( input, k2 );
		}
	}
	
	private static int numOfDigits( int number, int base ) {
		int count = 0;
		
		while( number != 0 ) {
			number /= base;
			count++;
		}
		
		return count == 0 ? 1 : count; // zero has 1 digit
	}
	
	// 1st digit is the LSD and last digit is the MSD
	private static int nthDigit( int number, int base, int n ) {
		if( n <= 0 )
			throw new IllegalArgumentException( "Digit numbering starts from 1" );
		
		return ( number / (int)Math.pow( base, n - 1 ) ) % base;
	}
}

interface KeyGenerator {
	// returns the getKey of the object on the basis of which
	// it can be compared to other objects of the same type
	Integer getKey( Object obj );
}
interface SortingAlgorithm {
	void apply( Object[] array, KeyGenerator keyGenerator );
}

