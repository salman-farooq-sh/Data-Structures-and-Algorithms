class MazeTest {
	
	public static void main( String[] args ) {
		int[][] intMaze = {
				{ 0,1,1,1,1,1,1,1,1,1 },
				{ 0,0,0,0,1,0,0,1,1,1 },
				{ 1,0,1,0,1,0,0,0,1,1 },
				{ 1,0,0,0,1,0,1,0,0,1 },
				{ 1,1,0,1,1,0,1,1,0,1 },
				{ 1,1,0,0,0,0,1,1,0,1 },
				{ 1,1,1,0,1,0,1,1,0,1 },
				{ 1,0,0,0,1,0,1,0,0,1 },
				{ 1,0,0,1,0,0,0,0,0,1 },
				{ 1,1,0,0,0,1,1,1,0,0 },
		};
		
		char[][] charMaze = Maze.toChar( intMaze );
		
		Maze.display( charMaze );
		
		Maze.solve( charMaze, 0,0, 9,9 );
		
		Maze.display( charMaze );
		
	}
}

class Maze {
	private static final char mazeWallChar = '#';
	private static final char mazeFloorChar = ' ';
	private static final char mazePathChar = '.';
	private static boolean mazeSolved;
	int[][] intMaze;
	
	public static char[][] toChar( int[][] intMaze ) {
		char[][] charMaze = new char[intMaze.length][intMaze.length];
		
		for( int i = 0; i < intMaze.length; i++ )
			for( int j = 0; j < intMaze[i].length; j++ )
				charMaze[i][j] = intMaze[i][j] == 1 ? mazeWallChar : mazeFloorChar;
		
		return charMaze;
	}
	
	public static void solve( char[][] maze, int start1, int start2, int end1, int end2 ) {
		
		boolean[][] visited = new boolean[maze.length][maze.length];
		
		mazeSolved = false;
		solve( maze, start1, start2, end1, end2, visited );
		
	}
	
	private static void solve( char[][] maze, int start1, int start2, int end1, int end2, boolean[][] visited ) {
		
		visited[start1][start2] = true;
		
		if( start1 == end1 && start2 == end2 ) {
			mazeSolved = true;
			maze[start1][start2] = mazePathChar;
			return;
		}
		
		//right
		if( start2+1 < maze.length && !visited[start1][start2+1] && maze[start1][start2+1] != mazeWallChar && !mazeSolved ) {
			
			solve( maze, start1, start2+1, end1, end2, visited );
			maze[start1][start2] =  mazeSolved ? mazePathChar : mazeFloorChar;
		}
		
		//down
		if( start1+1 < maze.length && !visited[start1+1][start2] && maze[start1+1][start2] != mazeWallChar && !mazeSolved ) {
			
			solve( maze, start1+1, start2, end1, end2, visited );
			maze[start1][start2] =  mazeSolved ? mazePathChar : mazeFloorChar;
		}
		
		//left
		if( start2-1 >= 0 && !visited[start1][start2-1] && maze[start1][start2-1] != mazeWallChar && !mazeSolved ) {
			
			solve( maze, start1, start2-1, end1, end2, visited );
			maze[start1][start2] =  mazeSolved ? mazePathChar : mazeFloorChar;
		}
		
		//up
		if( start1-1 >= 0 && !visited[start1-1][start2] && maze[start1-1][start2] != mazeWallChar && !mazeSolved ) {
			
			solve( maze, start1-1, start2, end1, end2, visited );
			maze[start1][start2] =  mazeSolved ? mazePathChar : mazeFloorChar;
		}
		
	}
	
	public static void display( char[][] maze ) {
		for( char[] row: maze ) {
			for( char el: row )
				System.out.print(el + " ");
			
			System.out.println("");
		}
		
		System.out.println("");
	}
}


