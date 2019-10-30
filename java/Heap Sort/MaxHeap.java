import java.util.Arrays;
import java.util.Random;

public class MaxHeap {
	public static void main( String[] args ) {
		for( int i = 0; i < 4; ++i ) {
			for( int n = 100_000; n <= 100_000_000; n *= 10 ) {
				int[] array = randomArray(n);
				
				Timer timer = new Timer();
				timer.start();
				
				heapSort( array ); // implemented by me
//				quicksort( array ); // quicksort from GeeksForGeeks.com
//				Arrays.sort( array ); // quicksort from java api
//				Arrays.parallelSort( array ); // multi-threaded sort from java api
				
				double t = timer.secondsElapsed();
				
				double nlgn = n * binlog(n);
				
				System.out.printf( "t = %8.4fs | n = %-10d | nlgn/t = %.2f \n",
										t,          n,               nlgn/t  );
			}
		}
	}
	
	private static void    heapSort( int[] array ) {
		transformIntoMaxHeap( array );
		
		int lastIndex = array.length - 1;
		
		while( lastIndex != 0 ) {
			// swap first element and lastIndex element so that the lastIndex element is sorted
			int temp = array[0];
			array[0] = array[lastIndex];
			array[lastIndex] = temp;
			
			// decrement last index because element at lastIndex is sorted now
			lastIndex--;
			
			// run maxHeapify() till "lastIndex" because maxHeap property maybe broken
			maxHeapify( array, lastIndex );
		}
	}
	private static void    maxHeapify( int[] array, final int root, final int lastIndex ) {
		Integer leftChild = left(root) <= lastIndex ? left(root) : null;
		Integer rightChild = right(root) <= lastIndex ? right(root) : null;
		
		if( leftChild != null && rightChild != null ) {
			int bigger = array[leftChild] < array[rightChild] ? rightChild : leftChild;
			
			if( array[root] < array[bigger] ) {
				// swap array[root] and array[bigger]
				int temp = array[root];
				array[root] = array[bigger];
				array[bigger] = temp;
				
				maxHeapify( array, bigger, lastIndex );
			}
		}
		
		if( leftChild != null ) {
			if( array[root] < array[leftChild] ) {
				// swap array[root] and array[leftChild]
				int temp = array[root];
				array[root] = array[leftChild];
				array[leftChild] = temp;
			}
		}
	}
	private static void    transformIntoMaxHeap( int[] array, final int root ) {
		for( int i = array.length/2 - 1; i >= 0; --i )
			maxHeapify( array, i, array.length - 1 );
	}
	private static void    maxHeapify( int[] array, final int lastIndex ) { maxHeapify( array, 0, lastIndex ); }
	private static void    transformIntoMaxHeap( int[] array ) { transformIntoMaxHeap( array, 0 ); }
	private static int[]   randomArray( int size ) {
		int[] array = new int[size];
		
		Random rand = new Random( System.nanoTime() );
		for( int i = 0; i < array.length; i++ )
			array[i] = rand.nextInt(1000);
		
		return array;
	}
	private static double  binlog( int x ) {
		return Math.log(x) / Math.log(2);
	}
	private static int     left( int i ) { return 2 * i + 1; }
	private static int     right( int i ) { return 2 * i + 2; }
	private static int     parent( int i ) { return (i + 1)/2 - 1; }
	private static void    printArray( int[] array ) {
		for( int item: array )
			System.out.print( item + " " );
	}
	private static boolean isSorted( int[] array ) {
		boolean flag = true;
		
		for( int i = 1; i < array.length; i++ ) {
			if( array[i - 1] > array[i] ) {
				flag = false;
				break;
			}
		}
		
		return flag;
	}
	private static int     partition(int arr[], int low, int high) {
		int pivot = arr[high];
		int i = (low-1);
		for (int j=low; j<high; j++)
		{
			if (arr[j] <= pivot)
			{
				i++;
				
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
		
		int temp = arr[i+1];
		arr[i+1] = arr[high];
		arr[high] = temp;
		
		return i+1;
	}
	private static void    quicksort( int arr[], int low, int high ) {
		if (low < high)
		{
			int pi = partition(arr, low, high);
			
			quicksort( arr, low, pi-1 );
			quicksort( arr, pi+1, high );
		}
	}
	private static void    quicksort( int arr[] ) { quicksort( arr, 0, arr.length - 1 );}
}

class Timer {
	private long startTime;
	
	public void start() {
		 startTime = System.nanoTime();
	}
	
	public double secondsElapsed() {
		return ( System.nanoTime() - startTime ) / (double)1_000_000_000;
	}
}


