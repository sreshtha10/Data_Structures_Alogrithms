//Path using BFS.

package project0;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.LinkedList;
import java.util.Queue;

class Graph {
	private int v; // total number of vertices
	private LinkedList<Integer> adj[]; // adjacency list
	private boolean visited[];

	Graph(int v) {
		this.v = v;
		this.adj = new LinkedList[v];
		this.visited = new boolean[v];
		for (int i = 0; i < this.v; i++) {
			adj[i] = new LinkedList<Integer>();
		}

	}

	public void addEdge(int u, int v) { // edge from u -> v
		this.adj[u].add(v);
	}

	public int[] BFS(int source) {
		Queue<Integer> queue = new LinkedList<Integer>();
		
		int[] prev= new int[this.v]; // this array will contain the prev visited node for each vertex
		// for eg. prev[3] = 5 means we visited 3 just after 5.
		
		//initialize prev to -1
		
		for(int i=0;i<v;i++) {
			prev[i] = -1;
		}
		
		queue.add(source);
		visited[source] = true;
		
		while (!queue.isEmpty()) {
			
			int currNode = queue.poll();
			for (int next : this.adj[currNode]) {
				if (!visited[next]) {
					visited[next] = true;
					prev[next] = currNode;
					queue.add(next);
				}
			}
		}
		
		return prev;
	}

	public ArrayList<Integer> getPathUsingBFS(int source,int end) {
		
		int prev[] = BFS(source);
		
		return reconstructPath(source,end,prev);
	}
	
	public ArrayList<Integer> reconstructPath(int source,int end,int[] prev) {
		ArrayList<Integer> path = new ArrayList<Integer>();
		
		for(int a = end;a!=-1;a = prev[a]) {
			path.add(a);
		}
		
		Collections.reverse(path);
		
		if(path.get(0) ==source) {
			return path;
		}
		else {
			return null;
		}
	}

}

public class FindingPathUsingBFS {
	public static void main(String args[]) {

		Graph g = new Graph(4);

		g.addEdge(0, 1);
		g.addEdge(0, 2);
		g.addEdge(1, 2);
		g.addEdge(2, 0);
		g.addEdge(2, 3);
		g.addEdge(3, 3);

		System.out.println(g.getPathUsingBFS(0, 3).toString());

	}

}
