from collections import deque

# change according to input
graph = {
    'A':['D','C'],
    'B':['A','D','E'],
    'C':['A','F'],
    'D':['B'],
    'E':['B','F'],
    'F':['C','E'],
}

visited = set()

def bfs(start):
    visited = set()
    queue = deque([start])
    visited.add(start)
    while queue:
        node = queue.popleft()
        print(node,end=" ")
        
        for i in graph[node]:
            if i not in visited:
                queue.append(i)
                visited.add(i)
                
def dfs(start):
    if start not in visited:
        visited.add(start)
        print(start,end=" ")
        for neighbours in graph[start]:
            dfs(neighbours)
            

print('bfs:  ',end=" ")
bfs('A')
print()
print('dfs:  ',end=" ")
dfs('A')
                
