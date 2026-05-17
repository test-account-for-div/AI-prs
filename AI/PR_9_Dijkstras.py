# Dijkstra Algorithm with Source and Destination

graph = {
    'A': {'B': 4, 'C': 2},
    'B': {'A': 4, 'C': 1, 'D': 5},
    'C': {'A': 2, 'B': 1, 'D': 8, 'E': 10},
    'D': {'B': 5, 'C': 8, 'E': 2, 'F': 6},
    'E': {'C': 10, 'D': 2, 'F': 3},
    'F': {'D': 6, 'E': 3}
}


def dijkstra(graph, start, goal):

    # Store shortest distance
    distance = {}

    # Store previous node
    parent = {}

    visited = []

    # Initialize
    for node in graph:
        distance[node] = float('inf')
        parent[node] = None

    distance[start] = 0

    while len(visited) < len(graph):

        # Find minimum distance node
        min_node = None

        for node in graph:

            if node not in visited:

                if min_node is None:
                    min_node = node

                elif distance[node] < distance[min_node]:
                    min_node = node

        visited.append(min_node)

        # Update neighbors
        for neighbor, weight in graph[min_node].items():

            if neighbor not in visited:

                new_distance = distance[min_node] + weight

                if new_distance < distance[neighbor]:

                    distance[neighbor] = new_distance
                    parent[neighbor] = min_node

    # Build shortest path
    path = []

    current = goal

    while current is not None:

        path.append(current)
        current = parent[current]

    path.reverse()

    print("Shortest Distance =", distance[goal])
    print("Shortest Path =", path)


# Source and Destination
src = 'A'
dest = 'F'

dijkstra(graph, src, dest)