# Graph based bfs algorithm
def bfs(graph):
    # Create a queue for bfs
    queue = []
    # Create a visited list
    visited = [False] * len(graph)
    # Create a list to store the bfs traversal
    bfs_traversal = []
    # Add the starting vertex to the queue
    queue.append(0)
    # Mark the starting vertex as visited
    visited[0] = True
    # While the queue is not empty
    while queue:
        # Remove the first vertex from the queue
        vertex = queue.pop(0)
        # Add the vertex to the bfs traversal
        bfs_traversal.append(vertex)
        # For each vertex adjacent to the current vertex
        for adjacent_vertex in graph[vertex]:
            # If the adjacent vertex has not been visited
            if not visited[adjacent_vertex]:
                # Mark the adjacent vertex as visited
                visited[adjacent_vertex] = True
                # Add the adjacent vertex to the queue
                queue.append(adjacent_vertex)
    # Return the bfs traversal
    return bfs_traversal


# Graph based dfs algorithm
def dfs(graph):
    # Create a stack for dfs
    stack = []
    # Create a visited list
    visited = [False] * len(graph)
    # Create a list to store the dfs traversal
    dfs_traversal = []
    # Add the starting vertex to the stack
    stack.append(0)
    # Mark the starting vertex as visited
    visited[0] = True
    # While the stack is not empty
    while stack:
        # Remove the first vertex from the stack
        vertex = stack.pop()
        # Add the vertex to the dfs traversal
        dfs_traversal.append(vertex)
        # For each vertex adjacent to the current vertex
        for adjacent_vertex in graph[vertex]:
            # If the adjacent vertex has not been visited
            if not visited[adjacent_vertex]:
                # Mark the adjacent vertex as visited
                visited[adjacent_vertex] = True
                # Add the adjacent vertex to the stack
                stack.append(adjacent_vertex)
    # Return the dfs traversal
    return dfs_traversal


# ? Topological Sorting Algorithm
# ? This algorithm is used to find the topological sorting of a directed acyclic graph


def topological_sorting(graph):
    def topSortHelper(graph, vertex, visited, topSort):
        # Mark the current vertex as visited
        visited[vertex] = True
        # For each vertex adjacent to the current vertex
        for next_vertex in graph[vertex]:
            # If the adjacent vertex has not been visited
            if not visited[next_vertex]:
                # Call the helper function
                topSortHelper(graph, next_vertex, visited, topSort)
        # Add the current vertex to the topological sorting
        topSort.append(vertex)

    # Create a visited list
    visited = [False for _ in range(len(graph))]
    # Create a list to store the topological sorting
    topSort = []
    # For each vertex in the graph
    for vertex in range(len(graph)):
        # If the vertex has not been visited
        if not visited[vertex]:
            # Call the helper function
            topSortHelper(graph, vertex, visited, topSort)
    # Return the topological sorting
    return topSort


# ! Strongly Connected Components Algorithms
# ? Kosaraju's Algorithm
# ? Algorithm to find the strongly connected components in a graph
# ? Works by doing a dfs traversal on the graph and then doing a dfs traversal on the transpose of the graph
# ? Finds a strongly connected component when the reverse dfs is done on a vertex that was visited in the first dfs
def kosaraju(graph):
    # Create a list to store the dfs traversal
    # Create a stack for dfs
    stack, dfs_traversal = [], []
    # Create a visited list
    visited = [False] * len(graph)

    # Add the starting vertex to the stack
    stack.append(0)
    # Mark the starting vertex as visited
    visited[0] = True
    # While the stack is not empty
    while stack:
        # Remove the first vertex from the stack
        vertex = stack.pop()
        # Add the vertex to the dfs traversal
        dfs_traversal.append(vertex)
        # For each vertex adjacent to the current vertex
        for adjacent_vertex in graph[vertex]:
            # If the adjacent vertex has not been visited
            if not visited[adjacent_vertex]:
                # Mark the adjacent vertex as visited
                visited[adjacent_vertex] = True
                # Add the adjacent vertex to the stack
                stack.append(adjacent_vertex)
    # Return the dfs traversal
    return dfs_traversal


# ! Minimum Spanning Tree Algorithms
# ? Kruskal's Algorithm
# ? Kruskal's Algorithm is a greedy algorithm that finds a minimum spanning tree for a connected weighted graph
# ? It works by sorting the edges of the graph in ascending order and then adding the edges to the minimum spanning tree if they do not create a cycle
def kruskal(graph):
    # Create a list to store the minimum spanning tree
    mst = []
    # Sort the edges of the graph in ascending order
    edges = sorted(graph, key=lambda x: x[2])
    # Create a list to store the parents of each vertex
    parents = [i for i in range(len(graph))]
    # For each edge in the graph
    for edge in edges:
        # Get the vertices of the edge
        vertex1, vertex2 = edge[0], edge[1]
        # Find the parent of the first vertex
        while vertex1 != parents[vertex1]:
            vertex1 = parents[vertex1]
        # Find the parent of the second vertex
        while vertex2 != parents[vertex2]:
            vertex2 = parents[vertex2]
        # If the vertices are not in the same set
        if vertex1 != vertex2:
            # Add the edge to the minimum spanning tree
            mst.append(edge)
            # Set the parent of the first vertex to the parent of the second vertex
            parents[vertex1] = vertex2
    # Return the minimum spanning tree
    return mst


# ? Boruvka's Algorithm
# ? Boruvka's Algorithm is a greedy algorithm that finds a minimum spanning tree for a connected weighted graph
# ? Works by finding the cheapest edge for each component and then merging the components
def boruvka(graph):
    # Create a list to store the minimum spanning tree
    mst = []
    # Create a list to store the parents of each vertex
    parents = [i for i in range(len(graph))]
    # While the number of components is greater than 1
    while len(parents) > 1:
        # Create a list to store the cheapest edge for each component
        cheapest = [None] * len(graph)
        # For each edge in the graph
        for edge in graph:
            # Get the vertices of the edge
            vertex1, vertex2 = edge[0], edge[1]
            # Find the parent of the first vertex
            while vertex1 != parents[vertex1]:
                vertex1 = parents[vertex1]
            # Find the parent of the second vertex
            while vertex2 != parents[vertex2]:
                vertex2 = parents[vertex2]
            # If the vertices are not in the same set
            if vertex1 != vertex2:
                # If the cheapest edge for the first vertex has not been set
                if cheapest[vertex1] is None:
                    # Set the cheapest edge for the first vertex
                    cheapest[vertex1] = edge
                # If the cheapest edge for the second vertex has not been set
                elif cheapest[vertex2] is None:
                    # Set the cheapest edge for the second vertex
                    cheapest[vertex2] = edge
                # If the weight of the edge is less than the weight of the cheapest edge for the first vertex
                elif edge[2] < cheapest[vertex1][2]:
                    # Set the cheapest edge for the first vertex
                    cheapest[vertex1] = edge
                # If the weight of the edge is less than the weight of the cheapest edge for the second vertex
                elif edge[2] < cheapest[vertex2][2]:
                    # Set the cheapest edge for the second vertex
                    cheapest[vertex2] = edge
        # For each edge in the cheapest list
        for edge in cheapest:
            # If the edge is not None
            if edge is not None:
                # Get the vertices of the edge
                vertex1, vertex2 = edge[0], edge[1]
                # Find the parent of the first vertex
                while vertex1 != parents[vertex1]:
                    vertex1 = parents[vertex1]
                # Find the parent of the second vertex
                while vertex2 != parents[vertex2]:
                    vertex2 = parents[vertex2]
                # If the vertices are not in the same set
                if vertex1 != vertex2:
                    # Add the edge to the minimum spanning tree
                    mst.append(edge)
                    # Merge the components by setting the parent of the second vertex to the first vertex
                    parents[vertex2] = vertex1
    return mst


# ? Jarnik's Algorithm
# ? Jarnik's Algorithm is a greedy algorithm that finds a minimum spanning tree for a connected weighted graph
# ? Works by finding the cheapest edge for each component and then merging the components
def jarnik(graph):
    # Create a list to store the minimum spanning tree
    minimum_spanning_tree = []

    # Create a set to keep track of visited vertices
    visited = set()

    # Start with the first vertex in the graph
    start_vertex = list(graph.keys())[0]
    visited.add(start_vertex)

    # Iterate until all vertices are visited
    while len(visited) < len(graph):
        min_edge = None
        min_weight = float("inf")

        # Find the minimum weight edge connecting a visited vertex to an unvisited vertex
        for vertex in visited:
            for neighbor, weight in graph[vertex]:
                if neighbor not in visited and weight < min_weight:
                    min_edge = (vertex, neighbor)
                    min_weight = weight

        # Add the minimum weight edge to the minimum spanning tree
        minimum_spanning_tree.append(min_edge)

        # Mark the newly visited vertex as visited
        visited.add(min_edge[1])

    return minimum_spanning_tree


# ? Prim's Algorithm
# ? Prim's Algorithm is a greedy algorithm that finds a minimum spanning tree for a connected weighted graph
# ? Works by starting with a vertex and adding the cheapest edge to the minimum spanning tree
def prims(graph):
    # Create a list to store the minimum spanning tree
    mst = []
    # Create a list to store the parents of each vertex
    parents = [None] * len(graph)
    # Create a list to store the keys of each vertex
    keys = [float("inf")] * len(graph)
    # Create a list to store whether a vertex has been visited
    visited = [False] * len(graph)
    # Set the key of the first vertex to 0
    keys[0] = 0
    # For each vertex in the graph
    for _ in range(len(graph)):
        # Find the vertex with the smallest key
        min_key = float("inf")
        min_vertex = None
        for vertex in range(len(graph)):
            if not visited[vertex] and keys[vertex] < min_key:
                min_key = keys[vertex]
                min_vertex = vertex
        # Mark the vertex as visited
        visited[min_vertex] = True
        # For each vertex adjacent to the current vertex
        for adjacent_vertex in graph[min_vertex]:
            # Get the vertices of the edge
            vertex1, vertex2 = adjacent_vertex[0], adjacent_vertex[1]
            # If the adjacent vertex has not been visited and the weight of the edge is less than the key of the adjacent vertex
            if not visited[vertex2] and adjacent_vertex[2] < keys[vertex2]:
                # Set the parent of the adjacent vertex to the current vertex
                parents[vertex2] = vertex1
                # Set the key of the adjacent vertex to the weight of the edge
                keys[vertex2] = adjacent_vertex[2]
    # For each vertex in the graph
    for vertex in range(1, len(graph)):
        # Add the edge to the minimum spanning tree
        mst.append([parents[vertex], vertex, keys[vertex]])
    # Return the minimum spanning tree
    return mst


# ! Shortest Path Algorithms
# ? Dijkstra's Algorithm
# ? Dijkstra's Algorithm is a greedy algorithm that finds the shortest path from a source vertex to all other vertices in a graph
# ? Works by starting with the source vertex and adding the cheapest edge to the shortest path
def dijkstra(graph):
    # Create a list to store the shortest path
    shortest_path = []
    # Create a list to store the parents of each vertex
    parents = [None] * len(graph)
    # Create a list to store the keys of each vertex
    keys = [float("inf")] * len(graph)
    # Create a list to store whether a vertex has been visited
    visited = [False] * len(graph)
    # Set the key of the first vertex to 0
    keys[0] = 0
    # For each vertex in the graph
    for _ in range(len(graph)):
        # Find the vertex with the smallest key
        min_key = float("inf")
        min_vertex = None
        for vertex in range(len(graph)):
            if not visited[vertex] and keys[vertex] < min_key:
                min_key = keys[vertex]
                min_vertex = vertex
        # Mark the vertex as visited
        visited[min_vertex] = True
        # For each vertex adjacent to the current vertex
        for adjacent_vertex in graph[min_vertex]:
            # Get the vertices of the edge
            vertex1, vertex2 = adjacent_vertex[0], adjacent_vertex[1]
            # If the adjacent vertex has not been visited and the weight of the edge is less than the key of the adjacent vertex
            if (
                not visited[vertex2]
                and keys[vertex2] > keys[vertex1] + adjacent_vertex[2]
            ):
                # Set the parent of the adjacent vertex to the current vertex
                parents[vertex2] = vertex1
                # Set the key of the adjacent vertex to the weight of the edge
                keys[vertex2] = keys[vertex1] + adjacent_vertex[2]
    # For each vertex in the graph
    for vertex in range(1, len(graph)):
        # Add the edge to the shortest path
        shortest_path.append([parents[vertex], vertex, keys[vertex]])
    # Return the shortest path
    return shortest_path


# ? Bellman-Ford Algorithm
# ? Bellman-Ford Algorithm is a dynamic programming algorithm that finds the shortest path from a source vertex to all other vertices in a graph
# ? Works by relaxing all the edges in the graph n - 1 times where n is the number of vertices in the graph
def bellmanford(graph):
    # Create a list to store the shortest path
    shortest_path = []
    # Create a list to store the parents of each vertex
    parents = [None] * len(graph)
    # Create a list to store the keys of each vertex
    keys = [float("inf")] * len(graph)
    # Set the key of the first vertex to 0
    keys[0] = 0
    # For each vertex in the graph
    for _ in range(len(graph) - 1):
        # For each edge in the graph
        for edge in graph:
            # Get the vertices of the edge
            vertex1, vertex2 = edge[0], edge[1]
            # If the key of the first vertex plus the weight of the edge is less than the key of the second vertex
            if keys[vertex1] + edge[2] < keys[vertex2]:
                # Set the parent of the second vertex to the first vertex
                parents[vertex2] = vertex1
                # Set the key of the second vertex to the key of the first vertex plus the weight of the edge
                keys[vertex2] = keys[vertex1] + edge[2]
    # For each vertex in the graph
    for vertex in range(1, len(graph)):
        # Add the edge to the shortest path
        shortest_path.append([parents[vertex], vertex, keys[vertex]])
    # Return the shortest path
    return shortest_path


# * TEST CODE
# n = 8
# graph = [[] for _ in range(n)]

# Unweighted Graph
# graph[1].append([1, 2])
# graph[2].append([3, 3, 4, 5])
# graph[3].append([1, 1])
# graph[4].append([3, 1, 6, 8])
# graph[5].append([1, 6])
# graph[6].append([1, 7])
# graph[7].append([1, 5])
# graph[8].append([1, 6])
