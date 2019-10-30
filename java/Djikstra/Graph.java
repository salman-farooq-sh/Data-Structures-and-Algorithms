import java.io.File;
import java.util.*;

public class Graph<Node> {
	public static final int INFINITY = Integer.MAX_VALUE / 2;
	
	private HashMap<Node, ArrayList< Edge<Node> >> nodes = new HashMap();
	
	public Graph( Node ... nodes ) {
		for( Node node: nodes )
			this.addNode( node );
	}
	
	public void addNode( Node node ) {
		nodes.put( node, new ArrayList() );
	}
	
	public void addEdges( Node nodeValue, Edge<Node> ... edges ) {
		if( !contains( nodeValue ) )
			throw new NodeAbsentException( nodeValue.toString() );
		
		ArrayList edgeList = nodes.get( nodeValue );
		for( Edge<Node> edge: edges ) {
			if( !contains( edge.destination() ) )
				throw new NodeAbsentException( edge.destination().toString() );
			
			edgeList.add( edge );
		}
	}
	
	public boolean contains( Node nodeValue ) {
		return nodes.containsKey( nodeValue );
	}
	
	public ArrayList< Edge<Node> > outgoingEdges( Node nodeValue ) {
		if( !contains( nodeValue ) )
			throw new NodeAbsentException( nodeValue.toString() );
		
		return nodes.get( nodeValue );
	}
	
	public ShortestPaths<Node> findShortestPaths( Node startingNode ) {
		if( !contains(startingNode) )
			throw new NodeAbsentException( startingNode.toString() );
		
		HashMap<Node, Node>    parents        = new HashMap<>();
		HashMap<Node, Integer> distances      = new HashMap<>();
		PriorityQueue<Node>    unvisitedNodes = new PriorityQueue<>( Comparator.comparing( distances::get ) );
		
//		set all parents to null
		for( Node node: nodes.keySet() )
			parents.put( node, null );
		
//		set all distances to INFININodeY
		for( Node node: nodes.keySet() )
			distances.put( node, INFINITY );
//		 ... except for the startingNode
		distances.put( startingNode, 0 );

//		add all nodes to unvisited
		for( Node node: nodes.keySet() )
			unvisitedNodes.add( node );

		while( !unvisitedNodes.isEmpty() ) {
			Node n = unvisitedNodes.poll(); // nearest unvisited node
			
			updateNeighbourDistancesAndParents( n, distances, parents );
		}
		
		return new ShortestPaths<>( parents, distances, startingNode );
	}
	
	private void updateNeighbourDistancesAndParents( Node sourceNode,
													 HashMap<Node, Integer> distances,
													 HashMap<Node, Node> parents ) {
		if( !contains( sourceNode ) )
			throw new NodeAbsentException( sourceNode.toString() );
		
		for( Edge<Node> outEdge: outgoingEdges(sourceNode) ) {
			Integer oldDistance			 = distances.get( outEdge.destination() );
			Integer newDistance = distances.get(sourceNode) + outEdge.weight();
			
			// relax
			if( newDistance < oldDistance ) {
				parents.put( outEdge.destination(), sourceNode );
				distances.put( outEdge.destination(), newDistance );
			}
		}
	}
	
	public Set<Node> allNodes() {
		return nodes.keySet();
	}
	
	static public class ShortestPaths<Node> {
		private HashMap<Node, Node> parents;
		private HashMap<Node, Integer> distances;
		private Node fromWhichNode;
		
		private ShortestPaths( HashMap<Node, Node> parents, HashMap<Node, Integer> distances, Node fromWhichNode ) {
			this.parents = parents;
			this.distances = distances;
			this.fromWhichNode = fromWhichNode;
		}
		
		public void printPathTo( Node toNode ) {
			if( !isPresent(toNode) )
				throw new NodeAbsentException( toNode.toString() );
			
			System.out.print( sourceNode() + " -> " + toNode + ": " );
			if( distances.get(toNode) == Graph.INFINITY ) {
				System.out.println( "NO PATH" );
				return;
			}
			
			ArrayList<Node> reversePath = new ArrayList();
			
			Node probe = toNode;
			while( parents.get(probe) != null ) {
				reversePath.add( probe );
				
				probe = parents.get( probe );
			}
			
			System.out.print( sourceNode() );
			for( int i = reversePath.size() - 1; i >= 0; i-- )
				System.out.print(  " -> " + reversePath.get(i) );
			System.out.println();
		}
		
		public String distanceTo( Node destination ) {
			if( !isPresent(destination) )
				throw new NodeAbsentException( destination.toString() );
			
			if( distances.get( destination ) == Graph.INFINITY ) {
				return "INFINITE";
			}
			
			return distances.get( destination ).toString();
		}
		
		public Node sourceNode() {
			return fromWhichNode;
		}
		
		private boolean isPresent( Node node ) {
			return parents.containsKey( node );
		}
	}
}