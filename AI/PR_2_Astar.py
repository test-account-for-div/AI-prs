# Simple A* Algorithm in Python

graph = {
    'A': [('B', 1), ('C', 3)],
    'B': [('D', 3), ('E', 1)],
    'C': [('F', 5)],
    'D': [],
    'E': [('F', 1)],
    'F': []
}

# Heuristic values (estimated cost to goal F)
heuristic = {
    'A': 6,
    'B': 4,
    'C': 4,
    'D': 3,
    'E': 1,
    'F': 0
}

def a_star(start, goal):
    open_list = [start]
    closed_list = []

    g = {start: 0}
    parent = {start: None}

    while open_list:

        # Find node with lowest f = g + h
        current = open_list[0]
        for node in open_list:
            if g[node] + heuristic[node] < g[current] + heuristic[current]:
                current = node

        # Goal reached
        if current == goal:
            path = []
            while current is not None:
                path.append(current)
                current = parent[current]

            path.reverse()
            print("Path found:", path)
            return

        open_list.remove(current)
        closed_list.append(current)

        # Check neighbors
        for neighbor, cost in graph[current]:

            if neighbor in closed_list:
                continue

            new_cost = g[current] + cost

            if neighbor not in open_list:
                open_list.append(neighbor)

            elif new_cost >= g.get(neighbor, float('inf')):
                continue

            g[neighbor] = new_cost
            parent[neighbor] = current

    print("No path found")


# Run A*
a_star('A', 'F')