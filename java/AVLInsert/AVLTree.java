public class AVLTree {
	public AVLTreeNode root = null;
	
	public void insert( int data ) {
		if( root == null )
			root = new AVLTreeNode( data, null );
		else
			insert( root, data );
	}
	private void insert( AVLTreeNode subTree, int data ) {
		if( subTree.left == null && data <= subTree.data ) {
			subTree.left = new AVLTreeNode( data, subTree );
			updateHeight( subTree );
			return;
		}
		
		if( subTree.right == null && data > subTree.data ) {
			subTree.right = new AVLTreeNode( data, subTree );
			updateHeight( subTree );
			return;
		}
		
		if( data <= subTree.data ) {
			insert( subTree.left, data );
			updateHeight( subTree );
			applyAppropriateRotations( subTree );
		} else {
			insert( subTree.right, data );
			updateHeight( subTree );
			applyAppropriateRotations( subTree );
		}
	}
	
	private void updateHeight( AVLTreeNode node ) {
		node.height = 1 + Math.max( node.leftChildHeight(), node.rightChildHeight() );
	}
	
	private void applyAppropriateRotations( AVLTreeNode node ) {
		if( node.balanceFactor() == 2 && (node.right.balanceFactor() == 0 || node.right.balanceFactor() == 1) ) {
			leftRotate( node );
		} else if( node.balanceFactor() == 2 && node.right.balanceFactor() == -1 ) {
			rightRotate( node.right );
			leftRotate( node );
		} else if( node.balanceFactor() == -2 && (node.left.balanceFactor() == 0 || node.left.balanceFactor() == -1) ) {
			rightRotate( node );
		} else if( node.balanceFactor() == -2 && node.left.balanceFactor() == 1 ) {
			leftRotate( node.left );
			rightRotate( node );
		}
	}
	
	private void rightRotate( AVLTreeNode node ) {
		AVLTreeNode parent = node.parent;
		AVLTreeNode nodeLeft = node.left;
		
		node.left = nodeLeft.right;
		if( nodeLeft.right != null )
			nodeLeft.right.parent = node;
		
		nodeLeft.right = node;
		node.parent = nodeLeft;
	
		nodeLeft.parent = parent;
		if( parent != null )
			if( nodeLeft.data <= parent.data )
				parent.left = nodeLeft;
			else
				parent.right = nodeLeft;
		else
			this.root = nodeLeft;
		
		updateHeight( node );
		updateHeight( node.parent );
	}
	private void leftRotate( AVLTreeNode node ) {
		AVLTreeNode parent = node.parent;
		AVLTreeNode nodeRight = node.right;
		
		node.right = nodeRight.left;
		if( nodeRight.left != null )
			nodeRight.left.parent = node;
		
		nodeRight.left = node;
		node.parent = nodeRight;
		
		nodeRight.parent = parent;
		if( parent != null )
			if( nodeRight.data <= parent.data )
				parent.left = nodeRight;
			else
				parent.right = nodeRight;
		else
			this.root = nodeRight;
		
		updateHeight( node );
		updateHeight( node.parent );
	}
}