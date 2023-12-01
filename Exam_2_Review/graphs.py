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
