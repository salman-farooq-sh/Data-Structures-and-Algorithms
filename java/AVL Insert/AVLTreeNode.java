public class AVLTreeNode implements TreePrinter.PrintableNode {
	private int height;
	private int data;
	private AVLTreeNode parent;
	private AVLTreeNode left;
	private AVLTreeNode right;
	
	public AVLTreeNode( int data, AVLTreeNode parent ) {
		this.data      = data;
		this.parent	   = parent;
		this.left      = null;
		this.right     = null;
		this.height    = 1;
	}
	
	public int balanceFactor() {
		return rightChildHeight() - leftChildHeight();
	}
	
	public int rightChildHeight() {
		return right == null ? 0 : right.height;
	}
	
	public int leftChildHeight() {
		return left == null ? 0 : left.height;
	}
	
	@Override
	public AVLTreeNode getLeft() {
		return left;
	}
	
	@Override
	public AVLTreeNode getRight() {
		return right;
	}
	
	@Override
	public String getText() {
		return Integer.toString( data );
	}
}