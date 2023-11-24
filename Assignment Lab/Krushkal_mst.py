import math

# finding parent of a particular node
def findParent(parent,node):
    if parent[node] == node:
        return node
    parent[node] = findParent(parent,parent[node])
    return parent[node]

# union of two node into a particular tree
def union(x,y):
    x = findParent(parent,x)
    y = findParent(parent,y)

    if rank[x] < rank[y]:
        parent[x] = y
    elif rank[x] > rank[y]:
        parent[y] = x
    else:
        parent[x] = y
        rank[y]+=1

def mst():
    edges = []
    for i in range(no_of_nodes):
        for j in range(i+1,no_of_nodes):
            edges.append([i,j,graph[i][j]])

    # sorting the edges of the graph in ascending order
    edges.sort(key= lambda x:x[2])
    
    wt = 0
    for i in edges:
        u = findParent(parent,i[0])
        v = findParent(parent,i[1])

        # check if parent of two node is same, if not then union
        if u !=v:
            union(i[0],i[1])
            wt += i[2]

    return wt

f = open("./Assignment Lab/a280.tsp","r")
lines = f.readlines()
nodes = []

for i in range(len(lines)):
    l = lines[i].split(" ")
    temp = []
    for j in l:
        if j == '':
            continue
        temp.append(int(j))
    nodes.append(temp)

no_of_nodes = len(nodes)
graph = [[0 for _ in range(no_of_nodes)] for _ in range(no_of_nodes)]

def nint(x):
    return int(x + 0.5)

for i in range(no_of_nodes):
    for j in range(no_of_nodes):
        if j <= i:
            continue
        xd = nodes[i][1] - nodes[j][1]
        yd = nodes[i][2] - nodes[j][2]

        d = nint(math.sqrt(xd**2 + yd**2))
        graph[i][j] = graph[j][i] = d

parent = [i for i in range(no_of_nodes)]
rank = [0 for _ in range(no_of_nodes)]

print(mst())