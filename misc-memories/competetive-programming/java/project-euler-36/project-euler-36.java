class ProjectEuler_36 {
	public static void main( String[] args ) {
		int sum = 0;
		
		for( int i = 0; i < 1_000_000; ++i ) {
			if( isPalindromeB2( i ) && isPalindromeB10( i ) ) {
				sum += i;
			}
		}
		
		System.out.println( sum );
	}
	
	private static boolean isPalindromeB2( int num ) {
		int numLen = getLengthB2( num );
		
		int[] numDigs = new int[numLen];
		
		for( int i = 0; i < numLen; ++i ) {
			numDigs[i] = num & 1;
			num = num >> 1;
		}
		
		int i = 0;
		int j = numDigs.length - 1;
		
		boolean flag = true;
		while( i < j ) {
			if( numDigs[i] != numDigs[j] ) {
				flag = false;
			}
			
			i++;
			j--;
		}
		
		return flag;
	}
	private static int getLengthB2( int num ) {
		if( num == 0 ) {
			return 1;
		}
		
		int len = 0;
		while( num != 0 ) {
			len++;
			num = num >> 1;
		}
		
		return len;
	}
	private static int pow2( int p ) {
		return 1 << p;
	}
	
	private static boolean isPalindromeB10( int num ) {
		int numLen = getLengthB10( num );
		
		int[] numDigs = new int[numLen];
		
		for( int i = 0; i < numLen; ++i ) {
			numDigs[i] = num % 10;
			num /= 10;
		}
		
		int i = 0;
		int j = numDigs.length - 1;
		
		boolean flag = true;
		while( i < j ) {
			if( numDigs[i] != numDigs[j] ) {
				flag = false;
			}
			
			i++;
			j--;
		}
		
		return flag;
	}
	private static int getLengthB10( int num ) {
		if( num >= 1000000 ) return 7;
		if( num >= 100000 )  return 6;
		if( num >= 10000 )   return 5;
		if( num >= 1000 )    return 4;
		if( num >= 100 )     return 3;
		if( num >= 10 )      return 2;
							 return 1;
	}
	private static int pow10( int p ) {
		int product = 1;
		while( p > 0 ) {
			product *= 10;
			p--;
		}
		
		return product;
	}
	
}
