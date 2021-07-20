import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;

class Graph {
	private int v; // total number of vertices
	private LinkedList<Integer> adj[]; // adjacency list
	Graph(int v) {
		this.v = v;
		this.adj = new LinkedList[v];
		for (int i = 0; i < this.v; i++) {
			adj[i] = new LinkedList<Integer>();
		}

	}

	public void addEdge(int u, int v) { // edge from u -> v
		this.adj[u].add(v);
	}
	
	
	
	public void topSort() {
		Stack<Integer> stack = new Stack<>();
		boolean visited[] = new boolean[this.v];
		
		for(int i=0;i<v;i++) {
			visited[i] = false;
		}
		
		//traversing through each node
		for(int i=0;i<v;i++) {
			if(visited[i] == true) {
				continue;
			}
			visited[i] = true;
			stack = DFS(i,stack,visited);
		}
		
		
		while(!stack.isEmpty()) {
			System.out.print(stack.pop()+" ");
		}
		
	}
	
	public Stack<Integer> DFS(int i,Stack<Integer> stack,boolean[] visited){
		visited[i] = true;
		for(int next:adj[i]) {
			if(!visited[next]) {
				DFS(next,stack,visited);
			}
		}
		stack.push(i);
		return stack;
	}


}

public class TopologicalSort {
	public static void main(String args[]) {

		Graph g = new Graph(6);

		g.addEdge(2, 3);
		g.addEdge(3, 1);
		g.addEdge(4, 0);
		g.addEdge(4, 1);
		g.addEdge(5, 2);
		g.addEdge(5, 0);
		
		g.topSort();
		
	}

}
