import math

f = open("./Assignment Lab/a280.tsp","r")
lines = f.readlines()
nodes = []

for i in range(10):
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


def algo():
    node = 0
    for i in range(no_of_nodes):
        if not visited[i] and key[i] < key[node]:
            node = i

    visited[node] = True

    for i in range(no_of_nodes):
        if key[node] + graph[node][i] < key[i]:
            key[i] = key[node] + graph[node][i]

INT_MAX = 10**9
key = [INT_MAX for _ in range(no_of_nodes)]
key[0] = 0
visited = [False for _ in range(no_of_nodes)]
algo()
print(key)