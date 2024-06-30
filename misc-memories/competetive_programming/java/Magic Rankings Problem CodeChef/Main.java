class B
{
	public static void main( String[] args )
	{
		int n = 1234;
		
		int[][] grid2 = new int[n][n];
		
		for( int i = 0; i < n; i++ )
			for( int j = 0; j < n; j++ )
				grid2[i][j] = 1;
		
		grid2[n-1][n-1] = 0;
		grid2[0][0] = 0;
		
		int[][] grid = grid2;
		
		long startTime = System.nanoTime();
		getBestMemoized( grid );
		long endTime = System.nanoTime();
		System.out.println( "Memoized took: " + (endTime-startTime)/1000 );
		
		startTime = System.nanoTime();
		getBest( grid );
		endTime = System.nanoTime();
		System.out.println( "Non-memoized took: " + (endTime-startTime)/1000 );
	}
	
	private static int getBestMemoized( int[][] grid )
	{
		Integer[][] gridMemo = new Integer[grid.length][grid.length];
		
		return getBestMemoized( grid, grid.length-1, grid.length-1, gridMemo );
	}
	
	private static int getBestMemoized( int[][] grid, int i, int j, Integer[][] gridMemo )
	{
		if( gridMemo[i][j] == null )
		{
			int up = 0;
			int left = 0;
			
			if( i == 0 && j - 1 >= 0 )
				return gridMemo[i][j] = getBestMemoized( grid, 0 , j-1, gridMemo ) + grid[i][j];
			
			if( i - 1 >= 0 && j == 0 )
				return gridMemo[i][j] = getBestMemoized( grid, i-1, 0, gridMemo ) + grid[i][j];
			
			if( i == 0 && j == 0 )
				return gridMemo[i][j] = 0;
			
			
			left = getBestMemoized( grid, i-1, j, gridMemo );
			
			up = getBestMemoized( grid, i, j-1, gridMemo );
			
			return gridMemo[i][j] = grid[i][j] + (up > left ? up : left);
		}
		
		return gridMemo[i][j];
	}
	
	private static int getBest( int[][] grid )
	{
		return getBest( grid, grid.length-1, grid.length-1 );
	}
	
	private static int getBest( int[][] grid, int i, int j )
	{
		int up = 0;
		int left = 0;
		
		if( i == 0 && j - 1 >= 0 )
			return getBest( grid, 0 , j-1 ) + grid[i][j];
		
		if( i - 1 >= 0 && j == 0 )
			return getBest( grid, i-1, 0 ) + grid[i][j];
		
		if( i == 0 && j == 0 )
			return 0;
		
		
		left = getBest( grid, i-1, j );
		
		up = getBest( grid, i, j-1 );
		
		return grid[i][j] + (up > left ? up : left);	}
	
}
