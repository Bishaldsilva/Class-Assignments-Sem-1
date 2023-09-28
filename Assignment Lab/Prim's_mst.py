import math

def solve_mst():
    key[0] = 0

    for i in range(no_of_nodes):
        u = -1
        min_val = INT_MAX
        for i in range(no_of_nodes):
            if mst[i]==False and key[i] < min_val:
                min_val = key[i]
                u = i
        mst[u] = True

        for ind,val in enumerate(graph[u]):
            if mst[ind] == False and key[ind] > val:
                key[ind] = val
                parent[ind] = u

    return sum(key)
        

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
    for j in range(i+1,no_of_nodes):
        # if j <= i:
        #     continue
        xd = nodes[i][1] - nodes[j][1]
        yd = nodes[i][2] - nodes[j][2]

        d = nint(math.sqrt(xd**2 + yd**2))
        graph[i][j] = graph[j][i] = d

INT_MAX = 10**9
key = [INT_MAX] * no_of_nodes
mst = [False] * no_of_nodes
parent = [-1] * no_of_nodes

count = 0
for i in range(no_of_nodes):
    for j in range(no_of_nodes):
        if graph[i][j] == 0:
            if i!=j:
                print(i,j)
            count +=1

print(solve_mst())
# print(parent)
# print(key)