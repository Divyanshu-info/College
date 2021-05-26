graph = {'A': ['B', 'C', 'D'],
         'B': ['E','F', 'G'],
         'C': ['H', 'I', 'J'],
         'D': ['K', "L", "M"],
         'E': ['N','O', 'P'],
         'F': ['Q'],
         'G': ['R'],
         'H': ["S"]}

visited = set()

def dfs(visited, graph, node):
    if node not in visited:
        print (node, end=' ')
        visited.add(node)
        neighbours = graph.get(node, [])
        for neighbour in neighbours:
            dfs(visited, graph, neighbour)

dfs(visited, graph, 'A')
print()
