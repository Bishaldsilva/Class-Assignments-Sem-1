import math
import random
from ga import *

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

# Dynamic approch

# visited_all = (1<<no_of_nodes) - 1
# dp = [[-1 for _ in range(no_of_nodes)] for _ in range(1<<no_of_nodes)]

# def tsp(mask,pos):
#     cost = 10**9

#     if mask == visited_all:
#         return graph[pos][0]

#     if dp[mask][pos] != -1:
#         return dp[mask][pos]
    
#     for city in range(no_of_nodes):
#         if mask & (1<<city) == 0:
#             ans = graph[pos][city] + tsp(mask|(1<<city),city)
#             cost = min(ans,cost)

#     dp[mask][pos] = cost
#     return dp[mask][pos]

# print(len(dp))

# genetic algorithm

def calcDist(order,graph):
    d = 0
    for i in range(1,len(order)):
        a = order[i-1]
        b = order[i]
        d += graph[a][b]

    return d

population = []
best_res = 10**9
best_path = []
count = 0

for i in range(450):
    order = list(range(1,no_of_nodes))
    random.shuffle(order)
    order = [0] + order + [0]
    population.append(order)
    
while True:
    fitness,new_res,best_path = calculateFitness(population,graph,best_res,best_path)
    fitness = normalizeFitness(fitness)
    population = nextGen(population,fitness)

    if new_res == best_res:
        count+=1
    else:
        count = 0
        best_res = new_res

    if count == 3000:
        break

    print(best_res)

# print(best_res)
print(best_path)
print(calcDist(best_path,graph))