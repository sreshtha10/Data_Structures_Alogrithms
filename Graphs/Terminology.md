# Graph Theory - Terminology

* The pair of nodes that are connected by an edge are called **adjacent nodes**.

* A node which is not adjacent to any other node is called an **isolated node**.

* In a graph G = (V,E), each edge e belongs to E with an *ordered* pair of vertices, then G is called a **directed graph or digraph**.

* In a graph G = (V,E), each edge e belongs to E with an *unordered* pair of vertices, then G is called a **undirected graph**.

* An edge of a graph that joins a vertex to itself is called a **loop**.

* If a graph, has certain pair of vertices that are joined by more than one edge, such edges are called **parallel edges**.

* The **degree** of a vertex in an unidirected graph is the number of edges incident with it, with the exception that a loop at a vertex contributes twice to the degree of that vertex.


## Handshaking Theorem
    If G = (V,E) is an undirected graph with e edges then,

        sum of degrees of all vertices  = 2e


* The number of edges with v as their initial vertex is called the **out degree** of v.

* The number of edges with v as their terminal vertex is called the **in-degree** of v.

* A vertex with 0 in-degree is called a **source** and vertex with 0 out-degree is called a **sink**.

## Complete Graph

A simple graph in which there are exactly on edge between each pair of distinct vertices is called a complete graph.

Note : Since, two nodes together give on edge, therefore for a n-node complete graph K<sub>n</sub>, the total number of edges = <sup>n</sup>C<sub>2</sub>.

## Regular Graph

If every vertex of a simple graph has same degree, the the graph is called regular graph.


## Bipartite Graph

If the vertex of set V of a simple graph G = (V,E) can be *partitioned* into two subsets V1 and V2
such that every edge of G connects a vertex from V1 to V2, then G is called a bipartite graph.

Note - If each vertex of V1 is connected with each vertex of V2 then it is called **complete bipartite graph**.

