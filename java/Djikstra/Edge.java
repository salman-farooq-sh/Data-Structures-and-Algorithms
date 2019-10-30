public class Edge<T> {
	private T destination;
	private int weight;
	
	public Edge( T destination, int weight ) {
		this.destination = destination;
		this.weight = weight;
	}
	
	//getters and setters start
	public T destination() {
		return destination;
	}
	
	public int weight() {
		return weight;
	}
	//getters and setters end
}