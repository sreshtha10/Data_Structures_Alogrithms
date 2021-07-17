
//Checking for number of isolated components.

package project0;

import java.util.Arrays;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.Queue;

class Graph{
	private int v ; //total number of vertices
	private LinkedList<Integer> adj[]; //adjacency list
	private boolean visited[]; //to keep track of the node which are visited.
	int connected[];
	int count = 0;
	
	Graph(int v){
		this.v = v;
		this.adj = new LinkedList[v];
		this.visited = new boolean[v];
		this.connected = new int[v];
		for(int i=0;i<this.v;i++) {
			adj[i] = new LinkedList<Integer>();
			this.visited[i] = false;
		}
	
	}
	
	
	public void addEdge(int u,int v) { // edge from u -> v
		this.adj[u].add(v);
	}
	
	
	public void DFS(int source) {
		//if the node is already visited, then backtrack.
		if(this.visited[source] == true) {
			return;
		}
		//mark the source vertex as visited
		this.visited[source] = true;
		this.connected[source] = count;
		LinkedList<Integer> neighbours = this.adj[source];
		
		for(int next : neighbours) {
			DFS(next);
		}
		
	}
	
	
	public void connectedComponents() {
		for(int i=0;i<v;i++) {
			if(!this.visited[i]) {
				count++;
				DFS(i);
			}
		}
		
		System.out.println(Arrays.toString(this.connected));
	}
	
}

public class ConnectedComponents {
	public static void main(String args[]){
		
		Graph g = new Graph(4);
		
		g.addEdge(0, 1);
        g.addEdge(0, 2);
        g.addEdge(1, 2);
        g.addEdge(2, 0);
        g.addEdge(2, 3);
        g.addEdge(3, 3);
        
		g.connectedComponents();
	}
	

}
