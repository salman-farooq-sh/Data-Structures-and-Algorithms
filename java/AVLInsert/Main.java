public class Main {
	public static void main( String[] args ) {
		AVLTree tree = new AVLTree();
		
		for( Integer i : Utils.randomIntArray(20) ) {
			tree.insert(i);
		}

		TreePrinter.print( tree.root );
	}
}
