package project0;

// BST

class Node {

	int key;
	Node left;
	Node right;

	Node(int key) {
		this.key = key;
		left = null;
		right = null;
	}

	public void insert(int value) {
		if (value == key) {
			return; // No duplicates are allowed
		}

		if (value > key) {
			// explore right
			if (this.right == null) {
				this.right = new Node(value);
				return;
			} else {
				this.right.insert(value);
			}
		} else {
			// explore left
			if (this.left == null) {
				this.left = new Node(value);
				return;
			} else {
				this.left.insert(value);
			}
		}
	}

	public void traverseInOrder() {
		if (this.left != null) {
			this.left.traverseInOrder();
		}

		System.out.print(this.key + " ");

		if (this.right != null) {
			this.right.traverseInOrder();
		}

	}

	public void traversePostOrder() {
		if (this.left != null) {
			this.left.traverseInOrder();
		}

		if (this.right != null) {
			this.right.traverseInOrder();
		}

		System.out.print(this.key + " ");

	}

	public void traversePreOrder() {

		System.out.print(this.key + " ");

		if (this.left != null) {
			this.left.traverseInOrder();
		}

		if (this.right != null) {
			this.right.traverseInOrder();
		}

	}

	public Node getNode(int value) {
		if (this.key == value) {
			return this;
		}

		if (this.key > value) {
			if (this.left != null) {
				return this.left.getNode(value);
			} else {
				// not found.
				return null;
			}
		} else {
			if (this.right != null) {
				return this.right.getNode(value);
			} else {
				// not found.
				return null;
			}
		}

	}

}

class Tree {
	Node root;

	Tree(int key) {
		root = new Node(key);
	}

	Tree() {
		root = null;
	}

	// insertion
	public void insertNode(int value) {
		if (root == null) {
			root = new Node(value);
			return;
		} else {
			root.insert(value);
		}
	}

	// traversal
	public void levelOrder() {
		int height = height(this.root);
		for (int i = 1; i <= height; i++) {
			printCurrentLevel(root, i);
			System.out.println();
		}

	}

	// VLR
	public void preOrder() {
		root.traversePreOrder();

	}

	// LVR - gives the sorted output.
	public void inOrder() {
		root.traverseInOrder();
	}

	// LRV
	public void postOrder() {
		root.traversePostOrder();
	}

	public int height(Node root) {
		if (root == null) {
			return 0;
		}

		int leftHeight = height(root.left);
		int rightHeight = height(root.right);

		if (leftHeight > rightHeight) {
			return leftHeight + 1;
		} else {
			return rightHeight + 1;
		}
	}

	public void printCurrentLevel(Node root, int level) {
		if (root == null) {
			return;
		}
		if (level == 1) {
			System.out.print(root.key + " ");
		} else if (level > 1) {
			printCurrentLevel(root.left, level - 1);
			printCurrentLevel(root.right, level - 1);
		}
	}

	// search
	public Node get(int value) {
		if (root != null) {
			return root.getNode(value);
		} else {
			return null;
		}

	}

	// node with min key
	public Node getMin() {
		Node tmp = root;
		if (tmp != null) {
			while (tmp.left != null) {
				tmp = tmp.left;
			}
			return tmp;
		} else {
			return null;
		}
	}

	// node with max key
	public Node getMax() {
		Node tmp = root;
		if (tmp != null) {
			while (tmp.right != null) {
				tmp = tmp.right;
			}
			return tmp;
		} else {
			return null;
		}
	}
	
	
	//delete
	public Node delete(int value) {
		if(root == null) {
			return null; // bst is empty
		}
		
		Node currNode = root;
		Node parentNode = root;
		
		while(currNode != null) {
			if(value == currNode.key) {
				break;
			}
			if(value > currNode.key) {
				parentNode = currNode;
				currNode = currNode.right;
			}
			else {
				parentNode = currNode;
				currNode = currNode.left;
			}
		}
		
		if(currNode == null) {
			//element does not exist in the tree
			return null;
		}
		
		Node tmp;
		
		if(currNode.left == null && currNode.right == null) {
			// node to be deleted is a leaf
			if(parentNode.right == currNode) {
				parentNode.right = null;
			}
			else {
				parentNode.left = null;
			}
			tmp = currNode;
			currNode = null;
			System.gc();
			return tmp;
		}
		
		else if((currNode.left == null & currNode.right != null) || (currNode.right == null && currNode.left != null)) {
			// currNode has only one child.
			if(parentNode.left == currNode) {
				if(currNode.left != null) {
					parentNode.left = currNode.left;
				}
				else {
					parentNode.left = currNode.right;
				}
			}
			else {
				if(currNode.left != null) {
					parentNode.right = currNode.left;
				}
				else {
					parentNode.right = currNode.right;
				}
			}
			
			tmp = currNode;
			currNode = null;
			System.gc();
			return tmp;
		}
		
		else {
			tmp = currNode.left;
			Node tmp2 = currNode;
			Node parentTmp = currNode;
			// we will do by finding the inorder successor i.e. right most element of left subtree.
			while(tmp.right != null) {
				parentTmp = tmp;
				tmp = tmp.right;
			}
			
			if(parentTmp == currNode) {
				currNode.left = null;
			}
			else {
				parentTmp.right = null;
			}
			
			
			tmp2 = currNode;
			
			currNode.key = tmp.key;
			tmp = null;
			System.gc();
			
			return tmp2;
			
			
			
		}
		
	}

}

public class Main {
	public static void main(String args[]) {
		Tree tree = new Tree(25);

		tree.insertNode(20);
		tree.insertNode(15);
		tree.insertNode(22);
		tree.insertNode(17);
		tree.insertNode(27);
		tree.insertNode(26);
		tree.insertNode(30);
		tree.insertNode(29);
		tree.insertNode(32);

		tree.preOrder();
		System.out.println();

		tree.inOrder();
		System.out.println();

		tree.postOrder();
		System.out.println();

		tree.levelOrder();
		System.out.println();

		System.out.println(tree.get(26));
		System.out.println();

		System.out.println(tree.getMin().key);
		System.out.println();

		System.out.println(tree.getMax().key);
		System.out.println();
		
		
		System.out.println(tree.delete(25));
		System.out.println();
		
		tree.inOrder();
		System.out.println();

	}
}
