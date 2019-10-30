public class NodeAbsentException extends RuntimeException {
	public NodeAbsentException( String whichNode ) {
		super( "\"" + whichNode + "\"" + " not present in graph" );
	}
}