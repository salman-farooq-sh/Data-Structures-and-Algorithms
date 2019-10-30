public class Main {
	public static void main( String[] args ) {
		Graph<String> g = new Graph<>( "A", "B", "C", "D", "E" );
		g.addEdges( "A", new Edge("B",4), new Edge("C",2) );
		g.addEdges( "B", new Edge("D",2), new Edge("E",3), new Edge("C",3) );
		g.addEdges( "C", new Edge("B",1), new Edge("D",4), new Edge("E",5) );
		g.addEdges( "D" );
		g.addEdges( "E", new Edge("D",1) );
		
		for( String source: g.allNodes() ) {
			Graph.ShortestPaths<String> shortestPaths = g.findShortestPaths( source );
		
			for( String destination: g.allNodes() ) {
				shortestPaths.printPathTo( destination );
				System.out.println( "Path length: " + shortestPaths.distanceTo( destination ) + "\n" );
			}
		}
		
	}
}