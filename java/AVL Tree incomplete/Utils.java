import java.util.Random;

public class Utils {
	
	public static int[] randomArray( int size ) {
		int[] array = new int[size];
		
		Random rand = new Random( System.nanoTime() );
		for( int i = 0; i < array.length; i++ )
			array[i] = rand.nextInt(1000);
		
		return array;
	}
	public static void printArray( int[] array ) {
		for( int item: array )
			System.out.print( item + " " );
		
		System.out.println();
	}
	public static boolean isSorted( int[] array ) {
		boolean flag = true;
		
		for( int i = 1; i < array.length; i++ ) {
			if( array[i - 1] > array[i] ) {
				flag = false;
				break;
			}
		}
		
		return flag;
	}
	public static int max( int a, int b ) { return a < b ? b : a; }
	public static int twoTo( int exponent ) {
		if( exponent == 0 )
			return 1;
		
		return 2 * twoTo( exponent - 1 );
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
