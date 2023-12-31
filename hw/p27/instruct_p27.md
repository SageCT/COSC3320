Cyclic Dependency Removal
Graph

Suppose we have a directed graph G, consisting of n nodes and m edges. Edges on this graph constitute chains of dependent relationships: for example, (u, v) in the graph signifies that u directly depends on v. Directed paths in this graph define chains of indirect dependency, where some node is dependent on nodes which are in turn dependent on other nodes (they are indirectly dependent on these other nodes)

An example of such a graph: the graph that determines the prerequisite relationships of college classes. A suitable schedule where every class is taken after its prerequisites would be found through topological sorting.

A cyclic dependency in such a graph is a cycle, and these prevent topological sorting.

An example of cyclic dependency: Chicken depends on Egg. Egg depends on Chicken. A topological sorting would put them in order from first to last, and this is not possible because of the cycle.

Nodes in the graph which are satisfiable have no indirect or direct dependencies that part of a cyclic dependency, and thus by removing all unsatisfiable nodes (nodes which have a cycle in their indirect dependencies), the graph can be topologically ordered.

Given an input graph G, use DFS to detect and remove unsatisfiable nodes, and provide the number of satisfiable nodes remaining.

Expected runtime: O(n+m)

Note on input:

All graphs will be given with nodes numbered from 0 to n-1, and edges will be provided in a list. For the above: n - number of nodes m - number of edges

Input Format:

n
m
[ list of edges, one per line, each line having the form SRC DST ]
Output Format:

The number of satisfiable nodes
Example:

Input:
10
11
0 1
1 2
2 0
2 3
3 4
3 5
2 5
5 6
7 8
8 6
9 3
Output:
7
Explanation The graph is depicted in this image:

The only cycle in the graph is the one formed by 0, 1, and 2. Thus none of these are satisfiable. No other nodes have this cycle in their indirect dependencies, therefore there are 7 nodes remaining.
