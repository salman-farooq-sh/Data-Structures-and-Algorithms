import java.util.Random;

public class Utils {
	
	public static Integer[] randomIntArray( int size, boolean enableNegatives ) {
		Integer[] array = new Integer[size];
		
		Random rand = new Random( System.nanoTime() );
		for( int i = 0; i < array.length; i++ )
			array[i] = rand.nextInt(1000) - (enableNegatives ? 500 : 0);
		
		return array;
	}
	public static <T> void printArray( T[] array ) {
		printArray( array, " " );
	}
	public static <T> void printArray( T[] array, String spaceChar ) {
		for( T item: array )
			System.out.print( item.toString() + spaceChar );
		
		System.out.println();
	}
	public static <T extends Comparable > T max( T a, T b ) { return a.compareTo(b) < 0 ? b : a; }
	public static int twoTo( int exponent ) {
		if( exponent == 0 )
			return 1;
		
		return 2 * twoTo( exponent - 1 );
	}
	public static boolean isSorted( Integer[] array ) {
		return isSorted( array, i -> (Integer)i );
	}
	public static int max( Integer[] input ) {
		return maxKey( input, i -> (Integer)i );
	}
 	public static int min( Integer[] input ) {
		return minKey( input, i -> (Integer)i );
	}
	
	public static boolean isSorted( Object[] array, KeyGenerator k ) {
		boolean flag = true;
		
		for( int i = 1; i < array.length; i++ ) {
			if( k.getKey( array[i - 1] ) > k.getKey( array[i] ) ) {
				flag = false;
				break;
			}
		}
		
		return flag;
	}
	public static int maxKey( Object[] input, KeyGenerator k ) {
		int max = k.getKey( input[0] );
		
		for( int i = 1; i < input.length; i++ ) {
			int keyOfInputI = k.getKey( input[i] );
			max = max < keyOfInputI ? keyOfInputI : max;
		}
		
		return max;
	}
	public static int minKey( Object[] input, KeyGenerator k ) {
		int min = k.getKey( input[0] );
		
		for( int i = 1; i < input.length; i++ ) {
			int keyOfInputI = k.getKey( input[i] );
			min = min > keyOfInputI ? keyOfInputI : min;
		}
		
		return min;
	}
	
	public static class Timer {
		private long startTime;
		
		public void start() {
			startTime = System.nanoTime();
		}
		
		public double secondsElapsed() {
			return ( System.nanoTime() - startTime ) / (double)1_000_000_000;
		}
	}
}

interface KeyGenerator {
	Integer getKey( Object obj );
}