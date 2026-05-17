import heapq
graph = {
    'A': {'B': 4, 'C': 2},
    'B': {'A': 4, 'C': 1, 'D': 5},
    'C': {'A': 2, 'B': 1, 'D': 8, 'E': 10},
    'D': {'B': 5, 'C': 8, 'E': 2, 'F': 6},
    'E': {'C': 10, 'D': 2, 'F': 3},
    'F': {'D': 6, 'E': 3}
}


def dijkstra(start,goal):
    distance={}
    parent = {}
     
    for node in graph:
        distance[node] = float('inf')
        parent[node] = None
        
    distance[start]=0
    
    
        
    priority_queue=[(0,start)]
    
    while len(priority_queue)>0:
        curr_dist, node = heapq.heappop(priority_queue)
        if curr_dist > distance[node]:
            continue
        for neighbour, weight in graph[node].items():
            dist_traveled = curr_dist + weight
            if(dist_traveled < distance[neighbour]):
                distance[neighbour] = dist_traveled
                parent[neighbour] = node
                
                heapq.heappush(
                    priority_queue,
                    (dist_traveled, neighbour)
                )
    
    path = []

    current = goal

    while current is not None:

        path.append(current)

        current = parent[current]

    path.reverse()

    print("Shortest Distance:", distance[goal])
    print("Shortest Path:", path)
    return distance[goal]

dijkstra("A","B")