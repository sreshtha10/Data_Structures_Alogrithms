package project0;

// BST

class Node{
	
	int key;
	Node left;
	Node right;
	
	Node(int key){
		this.key = key;
		left = null;
		right = null;
	}
	
	
	public void insert(int value) {
		if(value == key) {
			return; // No duplicates are allowed
		}
		
		if(value > key) {
			//explore right
			if(this.right == null) {
				this.right = new Node(value);
				return;
			}
			else {
				this.right.insert(value);
			}
		}
		else {
			// explore left
			if(this.left == null) {
				this.left = new Node(value);
				return;
			}
			else {
				this.left.insert(value);
			}
		}
	}
	
	
	
	public void traverseInOrder() {
		if(this.left != null) {
			this.left.traverseInOrder();
		}
		
		System.out.print(this.key+" ");
		
		if(this.right != null) {
			this.right.traverseInOrder();
		}
		
	}
	
	
	public void traversePostOrder() {
		if(this.left != null) {
			this.left.traverseInOrder();
		}
		
		
		if(this.right != null) {
			this.right.traverseInOrder();
		}
		
		System.out.print(this.key+" ");
		
	}
	
	public void traversePreOrder() {
		
		System.out.print(this.key+" ");
		
		if(this.left != null) {
			this.left.traverseInOrder();
		}
		
		
		if(this.right != null) {
			this.right.traverseInOrder();
		}
		
	}
	
	
	public Node getNode(int value) {
		if(this.key == value) {
			return this;
		}
		
		if(this.key > value) {
			if(this.left != null) {
				return this.left.getNode(value);
			}
			else {
				//not found.
				return null;
			}
		}
		else {
			if(this.right != null) {
				return this.right.getNode(value);
			}
			else {
				//not found.
				return null;
			}
		}
		
	}
	
	

	
}


class Tree{
	Node root;
	
	Tree(int key){
		root = new Node(key);
	}
	
	Tree(){
		root = null;
	}
	  
	
	// insertion
	public void insertNode(int value) {
		if(root == null) {
			root = new Node(value);
			return;
		}
		else {
			root.insert(value);
		}
	}
	
	
	
	// traversal
	public void levelOrder() {
		 int height = height(this.root);
		 for(int i=1;i<=height;i++) {
			 printCurrentLevel(root, i);
			 System.out.println();
		 }
		 
	}
	
	// VLR
	public void preOrder() {
		root.traversePreOrder();
		
	}
	
	
	//LVR - gives the sorted output.
	public void inOrder() {
		root.traverseInOrder();	
	}
	
	
	//LRV
	public void postOrder() {
		root.traversePostOrder();	
	}
	
	
	
	public int height(Node root) {
		if(root == null) {
			return 0;
		}
		
		int leftHeight = height(root.left);
		int rightHeight = height(root.right);
		
		if(leftHeight > rightHeight) {
			return leftHeight+1;
		}
		else {
			return rightHeight+1;
		}
	}
	
	
	public void printCurrentLevel(Node root,int level) {
		if(root == null) {
			return;
		}
		if(level == 1) {
			System.out.print(root.key+" ");
		}
		else if(level > 1) {
			printCurrentLevel(root.left, level-1);
			printCurrentLevel(root.right,level-1);
		}
	}
	
	
	
	//search
	public Node get(int value) {
		if(root != null) {
			return root.getNode(value);
		}
		else {
			return null;
		}
		
	}
	
	
	//node with min key
	public Node getMin() {
		Node tmp = root;
		if(tmp != null) {
			while(tmp.left != null) {
				tmp = tmp.left;
			}
			return tmp;
		}
		else {
			return null;
		}
	}
	
	//node with max key
	public Node getMax() {
		Node tmp = root;
		if(tmp != null) {
			while(tmp.right != null) {
				tmp = tmp.right;
			}
			return tmp;
		}
		else {
			return null;
		}
	}
	
	
	
	
}




public class Main{
	public static void main(String args[]) {
		Tree tree = new Tree(5);
		
		tree.insertNode(1);
		tree.insertNode(2);
		tree.insertNode(6);
		tree.insertNode(9);
		
		tree.preOrder();
		System.out.println();
		
		tree.inOrder();
		System.out.println();
		
		tree.postOrder();
		System.out.println();
		
		tree.levelOrder();
		System.out.println();
		
		System.out.println(tree.get(2));
		System.out.println();
		
		System.out.println(tree.getMin().key);
		System.out.println();
		
		System.out.println(tree.getMax().key);
		System.out.println();
		
			
		
	}
}