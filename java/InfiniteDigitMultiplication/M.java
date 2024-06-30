import java.util.Arrays;
import java.util.Random;

public class M {
	public static void main( String[] args ) {
		test();
	}
	
	private static void test() {
		Random random = new Random();
		boolean flag = true;
		
		for( int i = 0; i < 5; i++ ) {
			// test two (i+1)-digit numbers j times
			for( int j = 0; j < 1000; j++ ) {
				long x = Math.abs( random.nextLong() ) % (long)Math.pow( 10, i );
				long y = Math.abs( random.nextLong() ) % (long)Math.pow( 10, i );
				
				if( toLong( multiply( digits( x ), digits( y ) ) ) != x * y ) {
					System.out.println( "Failure:");
					Utils.printArray( digits( x*y ), "" );
					Utils.printArray( multiply( digits(x), digits(y) ), "" );
					System.out.println();
					
					flag = false;
					break;
				}
			}
		}
		
		if( flag )
			System.out.println( "success!" );
	}
	private static Integer[] digits( Long x ) {
		String xStr = Long.toString( x );
		
		Integer[] xArray = new Integer[ xStr.length() ];
		for( int i = 0; i < xStr.length(); i++ ) {
			xArray[i] = Integer.parseInt( Character.toString( xStr.charAt(i) ) );
		}
		
		return xArray;
	}
	private static long toLong( Integer[] x ) {
		long result = 0;
		
		for( int i = 0; i < x.length; i++ ) {
			result += x[i] * (int)Math.pow( 10, x.length - i - 1 );
		}
		
		return result;
	}
	
	private static Integer[] padLeft( Integer[] x, int numOfZeros ) {
		Integer[] newArray = new Integer[ numOfZeros + x.length ];
		
		for( int i = 0; i < numOfZeros; i++ )
			newArray[i] = 0;
		
		for( int i = 0; i < x.length; i++ )
			newArray[ numOfZeros + i ] = x[i];
		
		return newArray;
	}
	private static Integer[] padRight( Integer[] x, int numOfZeros ) {
		Integer[] newArray = new Integer[ numOfZeros + x.length ];
		
		for( int i = 0; i < x.length; i++ )
			newArray[i] = x[i];
		
		for( int i = x.length; i < newArray.length; i++ )
			newArray[i] = 0;
		
		return newArray;
	}
	private static Integer[] add( Integer[] x, Integer[] y ) {
		if( x.length < 1 )
			return y;
		
		if( y.length < 1 )
			return x;
		
		// pad smaller with zeros on the left
		if( x.length > y.length )
			y = padLeft( y, x.length - y.length );
		else if( y.length > x.length )
			x = padLeft( x, y.length - x.length );
		
		assert x.length == y.length;
		
		Integer[] result = new Integer[ x.length + 1 ];
		
		int carry = 0;
		for( int j = 1; j <= x.length; j++ ) {
			int sum = x[ x.length - j ] + y[ y.length - j ] + carry;
			result[ result.length - j ] = sum % 10;
			carry = sum / 10;
		}
		
		if( carry == 0 )
			return Arrays.copyOfRange( result, 1, result.length );
		
		assert carry == 1 : "final carry is not 0 or 1";
		
		result[0] = carry;
		return result;
	}
	private static Integer[] multiply( Integer[] x, Integer[] y ) {
		// pad smaller with zeros on the left
		if( x.length > y.length )
			y = padLeft( y, x.length - y.length );
		else if( y.length > x.length )
			x = padLeft( x, y.length - x.length );
		
		assert x.length == y.length : "multiplyHelper() requires arrays of equal lengths";
		
		int n = x.length;
		int m = n / 2;
		
		if( x.length == 0 ) {
			return new Integer[] { 0 };
		}
		
		if( n == 1 ) {
			int product = x[0] * y[0];
			Integer[] result;
			if( product / 10 == 0 ) {
				result = new Integer[1];
				result[0] = product;
			} else {
				result = new Integer[2];
				result[0] = product / 10;
				result[1] = product % 10;
			}
			
			return result;
		}
		
		
		Integer[] xL = Arrays.copyOfRange( x, 0, m );
		Integer[] xR = Arrays.copyOfRange( x, m, n );
		Integer[] yL = Arrays.copyOfRange( y, 0, m );
		Integer[] yR = Arrays.copyOfRange( y, m, n );
		
		Integer[] xLyL = multiply( xL, yL );
		Integer[] xLyR = multiply( xL, yR );
		Integer[] xRyL = multiply( xR, yL );
		Integer[] xRyR = multiply( xR, yR );
		
		xLyL = padRight( xLyL, 2 * xR.length );
		Integer[] s = add( xLyR, xRyL );
		s = padRight( s, xR.length /* == yR.length */ );
		
		Integer[] result = add( add(xLyL, s), xRyR );
		return result;
	}
}


