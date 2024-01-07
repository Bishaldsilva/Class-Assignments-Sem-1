INT_MAX = 10**9

def prims_algo():
    for loop in range(n):
        u = -1
        max_val = INT_MAX
        for i in range(n):
            if mst[i] == False and key[i] < max_val:
                max_val = key[i]
                u = i
        
        mst[u] = True

        for i in range(n):
            if mst[i] == False and graph[u][i] < key[i]:
                key[i] = graph[u][i]
                parent[i] = u

n = int(input("Enter the number of nodes: "))
graph = [[0 for _ in range(n)] for _ in range(n)]
for i in range(n):
    for j in range(i,n):
        val = int(input(f"Enter the value for edge {i}<-->{j}: "))
        if val == -1:
            val = INT_MAX
        graph[i][j] = val
        graph[j][i] = val

key = [INT_MAX] * n
mst = [False] * n
parent = [-1] * n
key[0] = 0

prims_algo()
print(sum(key))