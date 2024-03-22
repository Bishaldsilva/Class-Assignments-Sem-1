n = 4
graph = [[0,16,11,6],
         [16,0,13,16],
         [11,13,0,9],
         [6,16,9,0]]

visited_all = (1<<n) - 1
dp = [[-1 for _ in range(n)] for _ in range(1<<n)]

def tsp(mask,pos):
    cost = 10**9

    if mask == visited_all:
        return graph[pos][0]

    if dp[mask][pos] != -1:
        return dp[mask][pos]
    
    for city in range(n):
        if mask & (1<<city) == 0:
            ans = graph[pos][city] + tsp(mask|(1<<city),city)
            cost = min(ans,cost)

    dp[mask][pos] = cost
    return dp[mask][pos]

print(tsp(1,0))