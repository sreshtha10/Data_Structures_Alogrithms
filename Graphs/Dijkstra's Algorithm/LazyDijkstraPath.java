package project0;

import java.util.Comparator;
import java.util.LinkedList;
import java.util.PriorityQueue;

class Pair {
	int vertex;
	int shortestDist;

	Pair(int vertex, int shortestDist) {
		this.vertex = vertex;
		this.shortestDist = shortestDist;
	}
}

class CustComparator implements Comparator<Pair> {

	@Override
	public int compare(Pair o1, Pair o2) {
		return o1.shortestDist - o2.shortestDist;
	}

}

class Edge {
	int destination;
	int weight;

	Edge(int destination, int weight) {
		this.destination = destination;
		this.weight = weight;
	}
}

class Graph {

	private int v; // total number of vertices

	private LinkedList<Edge> adj[]; // adj list

	Graph(int v) {
		this.v = v;
		this.adj = new LinkedList[v];
		for (int i = 0; i < v; i++) {
			this.adj[i] = new LinkedList<Edge>();
		}
	}

	public void addEdge(int source, int des, int wg) {
		this.adj[source].add(new Edge(des, wg));
	}

	public void dijkstra(int source,int end) {

		int[] dist = new int[this.v];
		boolean[] vis = new boolean[this.v];
		int[] prev = new int[this.v];

		for(int i=0;i<this.v;i++) {
			dist[i] = Integer.MAX_VALUE;
			vis[i] = false;
		}
		
		

		PriorityQueue<Pair> pq = new PriorityQueue<Pair>(new CustComparator()); // priority queue which stores pairs of
	        // vertex with their shortest distance.
		pq.add(new Pair(source, 0));
		dist[source] = 0;

		while (!pq.isEmpty()) {
			Pair currPair = pq.poll();
			int currVertex = currPair.vertex;
			vis[currVertex] = true;
			// for each neighbor : update distance if shortest path is possible and add
			// them to queue.
			
			
			if(dist[currVertex] < currPair.shortestDist) {
				continue;
			}
			
			for (Edge edge : adj[currVertex]) {
				
				int next = edge.destination;
				int weight = edge.weight;
				//if already visited continue
				if(vis[next]) {
					continue;
				}
				
				int newDist = weight+dist[currVertex];
				
				if (dist[next] > newDist ) {
					// update if the node distance is infinity
					dist[next] = newDist;
					pq.add(new Pair(next,newDist));
					prev[next]= currVertex;
				}
			}
			
			//once we reacher end node, no need to find min distances for other nodes.
			if(currVertex == end) {
				break;
			}

		}

		for(int i=end;;i = prev[i]) {
			System.out.println(i);
			if(i== source) {
				break;
			}
		}
	}
	
	


}

public class LazyDijkstraPath {
	public static void main(String args[]) {

		Graph g = new Graph(6);

		g.addEdge(0, 1, 2);
		g.addEdge(0, 2, 3);

		g.addEdge(1, 3, 5);
		g.addEdge(1, 4, 2);
		g.addEdge(1, 0, 2);

		g.addEdge(2, 4, 5);
		g.addEdge(2, 0, 3);

		g.addEdge(3, 5, 2);
		g.addEdge(3, 4, 1);
		g.addEdge(3, 1, 5);

		g.addEdge(4, 3, 1);
		g.addEdge(4, 5, 4);
		g.addEdge(4, 2, 5);
		g.addEdge(4, 1, 2);

		g.addEdge(5, 3, 2);
		g.addEdge(5, 4, 4);
		
		g.dijkstra(0, 5);

	}

}
