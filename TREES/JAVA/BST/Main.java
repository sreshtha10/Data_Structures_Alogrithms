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
		
	}
}
