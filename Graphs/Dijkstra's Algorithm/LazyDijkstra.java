package project0;

import java.util.Arrays;
import java.util.Comparator;
import java.util.LinkedList;
import java.util.PriorityQueue;


// class to represent (vertex,distance from source) -> it will later be put into the priority queue. 
class Pair {
	int vertex;
	int shortestDist;

	Pair(int vertex, int shortestDist) {
		this.vertex = vertex;
		this.shortestDist = shortestDist;
	}
}

/*since this is a lazy implementation, we will simply add all pairs in the queue for eg (1,3) and (1,7) {but only (1,3) should be there since it's distance is small.} 
Custom comparator will sort the priority queue on the basis of distance from source. So that each time, the vertex with min. distance is selected ( greedy approach)/
*/

class CustComparator implements Comparator<Pair> {

	@Override
	public int compare(Pair o1, Pair o2) {
		return o1.shortestDist - o2.shortestDist;
	}

}

// edge -> it represents des, weight for any node. For edge from 2->3 with weight 6 adj[2] = new Edge(3,6) or adj[3] = new Edge(2,6).
class Edge {
	int destination;
	int weight;

	Edge(int destination, int weight) {
		this.destination = destination;
		this.weight = weight;
	}
}


// Adjacency List representation.
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

  
  // it returns an array with shortest distance from source for each vertex.
	public int[] dijkstra(int source) {

		int[] dist = new int[this.v];
		boolean[] vis = new boolean[this.v];

		for(int i=0;i<this.v;i++) {
			dist[i] = Integer.MAX_VALUE;
			vis[i] = false;
		}
		
		

		PriorityQueue<Pair> pq = new PriorityQueue<Pair>(new CustComparator()); // priority queue which stores pairs of
																				// vertex with their shortest dist.
		pq.add(new Pair(source, 0));
		dist[source] = 0;

		while (!pq.isEmpty()) {
			Pair currPair = pq.poll();
			int currVertex = currPair.vertex;
			vis[currVertex] = true;
			// for each neighbor : update distance if shortest path is possible and add
			// them to queue.

			for (Edge edge : adj[currVertex]) {
				
				int next = edge.destination;
				int weight = edge.weight;
				//if already visited continue
				if(vis[next]) {
					continue;
				}
				
				int newDist = weight+dist[currVertex];
				
				if (dist[next] > newDist ) {
					// update if the node dis is infinity or we found that new distance is smaller.
					dist[next] = newDist;
					pq.add(new Pair(next,newDist));
				}
			}

		}

		return dist;
	}

}

public class LazyDijktra {
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
		
		System.out.println(Arrays.toString(g.dijkstra(0)));

	}

}
