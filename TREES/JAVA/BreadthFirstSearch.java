class BreadthFirstSearch{
  
  Tree tree;
  
  BreadthFirstSearch(Tree tree){
    this.tree = tree;
  }
  
    public void BFS_traversal() {
		Queue<Node> queue = new LinkedList<Node>(); 
		if(this.tree.root == null) {
			return;
		}
		
		queue.add(this.tree.root);
		
		while(!queue.isEmpty()) {
			Node tmp = queue.peek();
			if(tmp.left != null) {
				queue.add(tmp.left);
			}
			if(tmp.right != null) {
				queue.add(tmp.right);
			}
			
			System.out.print(tmp.key+" ");
			queue.remove();
		}
		
	}
	
	public Node BFS(int key) {
		Queue<Node> queue = new LinkedList<Node>(); 
		if(this.tree.root == null) {
			return null;
		}
		queue.add(this.tree.root);
		
		Node result = null;

		while(!queue.isEmpty()) {
			Node tmp = queue.peek();
			if(tmp.left != null) {
				queue.add(tmp.left);
			}
			if(tmp.right != null) {
				queue.add(tmp.right);
			}
			
			if(tmp.key == key) {
				result = tmp;
				break;
			}
			queue.remove();
		}
		return result;
	}
	
  
}
