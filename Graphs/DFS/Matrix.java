class Graph {
	
	private int v; // total number of vertices
	
	private int[][] matrix; //adj matrix
	
	Graph(int v){
		this.v = v;
		this.matrix =new int[v][v];
	}
	
	public void addEdge(int source,int sink) {
		this.matrix[source][sink] = 1;
	}
	
	public void DFS(int source) {
		boolean visited[] = new boolean[v];
		
		for(int i=0;i<v;i++) {
			DFSUtil(visited,i);
		}
		
	}
	
	
	public void DFSUtil(boolean[] visited,int source) {
		if(visited[source] == true) {
			return;
		}
		System.out.print(source+" ");
		visited[source] = true;
		
		for(int j=0;j<v;j++) {
			//if edge exists do DFS.
			if(matrix[source][j] == 1) {
				DFSUtil(visited, j);
			}
		}
	}
	

}

public class Matrix {
	public static void main(String args[]) {

		Graph g = new Graph(5);
		g.addEdge(0, 1);
		g.addEdge(0, 2);
		g.addEdge(1, 3);
		g.addEdge(1, 4);
		
		
		g.DFS(0);
		
	}

}
