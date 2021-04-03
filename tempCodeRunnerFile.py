graph = {'A': [['B', 4], ['C', 2], ['D',3]],
         'B': [['E', 4],['F',2], ['G',3]],
         'C': [['H',4], ['I',2], ['J',3]],
         'D': [['K',1], ["L",2], ["M",3]],
         'E': [['N',1],['O',2], ['P',3]],
         'F': [['Q',3]],
         'G': [['R',3]],
         'H': [["S",2]]}

visited = set()

def dfs(visited, graph, node):
    
    if node not in visited:
        print (node, end=' ')
        visited.add(node)
        neighbours = graph.get(node, [])
        for neighbour in neighbours:
            dfs(visited, graph, neighbour)

#dfs(visited, graph, 'A')
#print()

print(graph)