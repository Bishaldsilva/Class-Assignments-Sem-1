import pygame
import math

pygame.init()
screen = pygame.display.set_mode((600,600))
clock = pygame.time.Clock()

points = []
cors = set()
gameActive = False
INT_MAX = 10**9

def drawPoints():
    for p in points:
        pygame.draw.circle(screen,(255,255,255),(p[0],p[1]),5)

# drawing the whole tree
def drawLine():
    for i,p in enumerate(parent):
        if p == -1:
            continue
        pygame.draw.line(screen,(255,0,0),(points[p][0],points[p][1]),(points[i][0],points[i][1]))

def dist(p1,p2):
    xd = p1[0] - p2[0]
    yd = p1[1] - p2[1]

    return math.sqrt(xd**2 + yd**2)

def getGraph(graph):
    for i in range(len(points)):
        for j in range(i,len(points)):
            graph[i][j] = graph[j][i] = dist(points[i],points[j])

# using prims algo to solve mst
def solve_mst():
    global key,mst,parent

    key = [INT_MAX] * len(graph)
    mst = [False] * len(graph)
    parent = [-1] * len(graph)

    key[0] = 0
    for i in range(len(graph)):
        u = 0
        val = INT_MAX
        for i in range(len(key)):
            if key[i] < val and not mst[i]:
                u = i
                val = key[i]
        mst[u] = True

        for i in range(len(graph)):
            if graph[u][i] < key[i] and not mst[i]:
                key[i] = graph[u][i]
                parent[i] = u

while True:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
            exit(0)
        if event.type == pygame.KEYDOWN:
            if event.key == pygame.K_SPACE and not gameActive:
                graph = [[0 for j in range(len(points))] for i in range(len(points))]
                getGraph(graph)
                solve_mst()
                print(sum(key))
                print(parent)
                gameActive = True

    if not gameActive:
        if pygame.mouse.get_pressed()[0]:
            x,y = pygame.mouse.get_pos()
            if (x,y) not in cors:
                cors.add((x,y))
                points.append([x,y])
    else:
        drawLine()

    drawPoints()

    pygame.display.update()
    clock.tick(60)