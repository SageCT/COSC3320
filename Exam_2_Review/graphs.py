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


# Topological Sorting Algo!
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


# n = 8
# graph = [[] for _ in range(n)]

# graph[1].append([1, 2])
# graph[2].append([3, 3, 4, 5])
# graph[3].append([1, 1])
# graph[4].append([3, 1, 6, 8])
# graph[5].append([1, 6])
# graph[6].append([1, 7])
# graph[7].append([1, 5])
# graph[8].append([1, 6])
