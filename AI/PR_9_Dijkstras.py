# Simple Dijkstra's Algorithm

graph = {
    'A': {'B': 4, 'C': 2},
    'B': {'A': 4, 'C': 1, 'D': 5},
    'C': {'A': 2, 'B': 1, 'D': 8, 'E': 10},
    'D': {'B': 5, 'C': 8, 'E': 2, 'F': 6},
    'E': {'C': 10, 'D': 2, 'F': 3},
    'F': {'D': 6, 'E': 3}
}


def dijkstra(graph, start):

    # Store shortest distances
    distance = {}

    # Mark visited nodes
    visited = []

    # Initialize distances
    for node in graph:
        distance[node] = float('inf')

    distance[start] = 0

    while len(visited) < len(graph):

        # Find node with minimum distance
        min_node = None

        for node in graph:

            if node not in visited:

                if min_node is None:
                    min_node = node

                elif distance[node] < distance[min_node]:
                    min_node = node

        # Visit node
        visited.append(min_node)

        # Update neighbors
        for neighbor, weight in graph[min_node].items():

            if neighbor not in visited:

                new_distance = distance[min_node] + weight

                if new_distance < distance[neighbor]:
                    distance[neighbor] = new_distance

    return distance


# Run algorithm
result = dijkstra(graph, 'A')

print("Shortest Distances from A:\n")

for node, dist in result.items():
    print(node, "=", dist)