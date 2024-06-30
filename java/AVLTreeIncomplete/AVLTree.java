import java.util.LinkedList;
import java.util.Queue;

public class AVLTree {
	private Node root;
	
	// a new node which is less than k away from ANY other node cannot be added
	// k == 0 means that duplicate nodes can be added
	private int k;
	
	public AVLTree() {
		setRoot( null );
		this.k = 5;
	}
	public AVLTree( final int k ) {
		if( k < 0 )
			throw new IllegalArgumentException( "k cannot be negative" );
		
		this.k = k;
	}
	
	// returns true on successful insertion
	public boolean insert( final int data ) {
		if( root == null ) {
			setRoot( new Node(data) );
			return true;
		}
		
		return insert( root, data );
	}
	
	// returns true on successful insertion
	private boolean insert( final Node n, final int data ) {
		n.incrementNumOfChildren();
		
		if( !kCheck( data, n.getData() ) ) {
			return false;
		}
		
		if( n.getLeft() == null && data <= n.getData() ) {
			Node child = new Node( data );
			child.setParent( n );
			n.setLeft( child );
			
			updateHeights( child );
			
			balance( child );
			
			return true;
		}
		
		if( n.getRight() == null && data > n.getData() ) {
			Node child = new Node( data );
			child.setParent( n );
			n.setRight( child );
			
			updateHeights( child );
			
			balance( child );
			
			return true;
		}
		
		if( data <= n.getData() ) {
			return insert( n.getLeft(), data );
		} else {
			return insert( n.getRight(), data );
		}
	}
	
	// returns true if "toTest" is "k" or more away from "against" and false otherwise
	private boolean kCheck( final int toTest, final int against ) {
		return (toTest <= against - this.k) || (toTest >= against + this.k);
	}
	
	// updates the heights of only those nodes which
	// are affected by the addition of the lastAddedNode
	private void updateHeights( final Node lastAddedNode ) {
		Node probe = lastAddedNode;
		
		while( probe != null ) {
			int leftHeight  = probe.getLeft()  == null ? -1 : probe.getLeft().getHeight();
			int rightHeight = probe.getRight() == null ? -1 : probe.getRight().getHeight();
			
			probe.setHeight( 1 + Utils.max(leftHeight, rightHeight) );
			
			probe = probe.getParent();
		}
	}
	
	// applies appropriate rotations to all the nodes which need them
	private void balance( final Node lastAddedNode ) {
		Node probe = lastAddedNode;
		
		while( probe != null ) {
			int balanceFactor = probe.balanceFactor();
			
			// determine and apply needed rotations
			if( balanceFactor == -2 ) {
				int bf2 = probe.getLeft().balanceFactor();
				
				if( bf2 == -1 || bf2 == 0 ) {
					rotateRight( probe );
					probe = probe.getParent();
				}
				else if( bf2 == 1 ) {
					rotateLeft( probe.getLeft() );
					rotateRight( probe );
					probe = probe.getParent();
				}
			}
			else if( balanceFactor == 2 ) {
				int bf2 = probe.getRight().balanceFactor();
				
				if( bf2 == 1 || bf2 == 0 ) {
					rotateLeft( probe );
					probe = probe.getParent();
				}
				else if( bf2 == -1 ) {
					rotateRight( probe.getRight() );
					rotateLeft( probe );
					probe = probe.getParent();
				}
			}
			
			if( probe.getParent() == null )
				setRoot( probe );
			
			probe = probe.getParent();
		}
	}
	
	// TODO: rotate methods do not correctly modify the numOfChildren of the affected nodes yet, fix it
	private void rotateRight( final Node n ) {
		assert n != null && n.getLeft() != null : "invalid right rotation attempted";
		
		final Node parent = n.getParent();
		final Node temp1  = n;
		final Node temp2 = n.getLeft();
		
		temp1.setLeft( temp2.getRight() );
		if( temp2.getRight() != null )
			temp2.getRight().setParent( temp1 );
		
		temp2.setRight( temp1 );
		temp1.setParent( temp2 );
		
		temp2.setParent( parent );
		if( parent != null ) {
			if( temp1.getData() <= parent.getData() )
				parent.setLeft( temp2 );
			else
				parent.setRight( temp2 );
		}
		
		updateHeights( n );
	}
	private void rotateLeft( final Node n ) {
		assert n != null && n.getRight() != null : "invalid left rotation attempted";
		
		final Node parent = n.getParent();
		final Node temp1  = n;
		final Node temp2  = n.getRight();
		
		temp1.setRight( temp2.getLeft() );
		if( temp2.getLeft() != null )
			temp2.getLeft().setParent( temp1 );
		
		temp2.setLeft( temp1 );
		temp1.setParent( temp2 );
		
		temp2.setParent( parent );
		if( parent != null ) {
			if( temp1.getData() <= parent.getData() )
				parent.setLeft( temp2 );
			else
				parent.setRight( temp2 );
		}
		
		updateHeights( n );
	}
	
	public int[] levelTraversal() {
		LinkedList<Integer> a = new LinkedList<>();
		Queue<Node> queue = new LinkedList<>();
		
		queue.add( root );
		
		while( !queue.isEmpty() ) {
			Node n = queue.remove();
			a.add( n.getData() );
			
			if( n.getLeft() != null )
				queue.add( n.getLeft() );
			
			if( n.getRight() != null )
				queue.add( n.getRight() );
		}
		
		// convert linked list to array and return
		return a.stream().mapToInt(i -> i).toArray();
	}
	public int[] inOrderTraversal() {
		LinkedList<Integer> list = new LinkedList<>();
		inOrderTraversal( this.root, list );
		
		return list.stream().mapToInt(i -> i).toArray();
	}
	private void inOrderTraversal( Node r, LinkedList<Integer> list ) {
		if( r == null )
			return;
		
		inOrderTraversal( r.getLeft(), list );
		list.add( r.getData() );
		inOrderTraversal( r.getRight(), list );
	}
	
	public int height() {
		return root.getHeight();
	}
	public int totalNodes() {
		if( root == null )
			return 0;
			
		return 1 + root.getNumOfChildren();
	}
	
	public void print2D() {
		print2D( root, 0 );
	}
	private void print2D( Node root, int space ) {
		int count = 8;
		
		if( root == null )
			return;

		space += count;

		print2D( root.right, space );

//		System.out.print("\n");
		
		for (int i = count; i < space; i++)
			System.out.print(" ");
		
		System.out.print(root.data + "\n");

		print2D( root.left, space );
	}
	
	//getters and setters start
	public Node getRoot() {
		return root;
	}
	
	public AVLTree setRoot( Node root ) {
		this.root = root;
		return this;
	}
	
	public int getK() {
		return k;
	}
	
	public AVLTree setK( int k ) {
		this.k = k;
		return this;
	}
	//getters and setters end
	
	public class Node {
		private int data;
		private int numOfChildren;
		private int height; // == length of the path to the most distant downward leaf
		
		private Node parent;
		private Node left;
		private Node right;
		
		public Node( int data ) {
			this.data = data;
		}
		
		//    return value explanation:
		// -2 means left subtree is 2 higher than the right subtree
		// -1 means left subtree is 1 higher than the right subtree
		//  0 means left subtree is equal in height to right subtree
		// +1 means right subtree is 2 higher than the left subtree
		// +2 means right subtree is 2 higher than the left subtree
		public int balanceFactor() {
			int leftHeight  = this.getLeft()  == null ? -1 : this.getLeft().getHeight();
			int rightHeight = this.getRight() == null ? -1 : this.getRight().getHeight();
			int balanceFactor = rightHeight - leftHeight;
			
			// should never get out of this range because we are
			// rebalancing the tree on each insertion/deletion
			assert balanceFactor <= 2 && balanceFactor >= -2;
			
			return balanceFactor;
		}
		
		void incrementHeight() {
			height++;
		}
		
		void decrementHeight() {
			height--;
		}
		
		void incrementNumOfChildren() {
			numOfChildren++;
		}
		
		void decrementNumOfChildren() {
			numOfChildren--;
		}
		
		public String toString() {
			return Integer.toString( this.getData() );
		}
		
		//getters and setters start
		public int getData() {
			return data;
		}
		
		public Node setData( int data ) {
			this.data = data;
			return this;
		}
		
		public int getHeight() {
			return height;
		}
		
		public Node setHeight( int height ) {
			this.height = height;
			return this;
		}
		
		public Node getLeft() {
			return left;
		}
		
		public Node setLeft( Node left ) {
			this.left = left;
			return this;
		}
		
		public Node getRight() {
			return right;
		}
		
		public Node setRight( Node right ) {
			this.right = right;
			return this;
		}
		
		public int getNumOfChildren() {
			return numOfChildren;
		}
		
		public Node setNumOfChildren( int numOfChildren ) {
			this.numOfChildren = numOfChildren;
			return this;
		}
		
		public Node getParent() {
			return parent;
		}
		
		public Node setParent( Node parent ) {
			this.parent = parent;
			return this;
		}
		//getters and setters end
	}
}







