import random

def calcDist(order,graph):
    d = 0
    for i in range(1,len(order)):
        a = order[i-1]
        b = order[i]
        d += graph[a][b]

    return d

def calculateFitness(population,graph,best_res,best_path):
    fitness = []
    for i in range(len(population)):
        d = calcDist(population[i],graph)
        if d < best_res:
            best_res = d
            best_path = population[i]

        fitness.append(1 / d)

    return fitness,best_res,best_path

def normalizeFitness(fitness):
    s = 0
    for i in range(len(fitness)):
        s += fitness[i]

    for i in range(len(fitness)):
        fitness[i] = fitness[i] / s

    return fitness

def nextGen(population,fitness):
    newgen = []
    for i in range(len(population)):
        child_a = pickOne(population,fitness)
        child_b = pickOne(population,fitness)
        newChild = crossOver(child_a,child_b)
        child = mutate(newChild,0.01)
        newgen.append(child)

    return newgen

def pickOne(population,fitness):
    # ind = 0
    # r = random.random()

    # while r > 0:
    #     r -= fitness[ind]
    #     ind+=1
    # ind-=1
    ind = -1
    max_val = 0
    for i in range(len(fitness)):
        if fitness[i] > max_val:
            max_val = fitness[i]
            ind = i
    return population[ind]

def crossOver(child_a,child_b):
    start = random.randint(1,len(child_a)-3)
    end = random.randint(start + 1,len(child_a)-2)

    newChild = [0] + child_a[start:end+1]

    for i in child_b[1:-1]:
        if i not in newChild:
            newChild.append(i)
    newChild += [0]

    return newChild


def mutate(path,rate):
    for _ in range(len(path)-1):
        if random.random() < rate:
            a = random.randint(1,len(path) - 2)
            b = random.randint(1,len(path) - 2)
            path[a],path[b] = path[b],path[a]

    return path