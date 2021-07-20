# Topological Sort

Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed edge u v, vertex u comes before v in the ordering. Topological Sorting for a graph is not possible if the graph is not a DAG.

## Alogrithm

![](https://media.geeksforgeeks.org/wp-content/uploads/20200818211917/Topological-Sorting-1.png)

* Pick any unvisited node
* Do DFS with the univisited node, exploring only unvisited node.
* On the recursive callback of the DFS, add the current node to the topological ordering(stack) in reverse order.


