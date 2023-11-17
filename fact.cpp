def dfs(graph, start, visited, first_visited):
    visited[start] = True
    first_visited.append(start)  # Mark the current vertex as first visited (colored gray)
    
    for neighbor in graph[start]:
        if not visited[neighbor]:
            dfs(graph, neighbor, visited, first_visited)

#For the first adjacency list:
graph1 = {1: [2, 4], 2: [3, 5], 3: [], 4: [], 5: [4, 6], 6: [3]}
visited1 = [False] * (max(graph1.keys()) + 1)
first_visited1 = []

for vertex in graph1:
    if not visited1[vertex]:
        dfs(graph1, vertex, visited1, first_visited1)

#For the second adjacency list:
graph2 = {5: [4, 6], 6: [3], 4: [], 3: [], 1: [2, 4], 2: [3, 5]}
visited2 = [False] * (max(graph2.keys()) + 1)
first_visited2 = []

for vertex in graph2:
    if not visited2[vertex]:
        dfs(graph2, vertex, visited2, first_visited2)

print("First Visited Order for Graph 1:", first_visited1)
print("First Visited Order for Graph 2:", first_visited2)
