import pygame
import math
import random

pygame.init()
rows = 60
cols = 60
size = 10
screen = pygame.display.set_mode((cols * size,rows*size))
pygame.display.set_caption("Rat in the Maze")
clock = pygame.time.Clock()

class Node:
    def __init__(self,row,col) -> None:
        self.row = row
        self.col = col
        self.center = (col * size + size /2,row * size + size/2)
        self.f = self.h = 0
        self.g = 10**9
        self.previous = None
        self.neighbors = []
        self.wall = False

    def get_h(self,end):
        xd = end.row - self.row
        yd = end.col - self.col
        # d = (xd +yd) +(math.sqrt(2) -2)*min(xd,yd )
        d = math.sqrt(xd**2 + yd**2)
        self.h = d

    def is_wall(self):
        flag = 0
        for i in random_paths:
            if [self.row,self.col] in i:
                flag = 1
                break
        
        if flag == 0 and random.random() < 0.3:
            self.wall = True

    def get_neighbors(self,graph):
        row = self.row
        col = self.col

        if row > 0:
            self.neighbors.append(graph[row-1][col])

        if row < rows - 1:
            self.neighbors.append(graph[row+1][col])

        if col > 0:
            self.neighbors.append(graph[row][col - 1])

        if col < cols - 1:
            self.neighbors.append(graph[row][col + 1])

        # if row > 0 and col > 0:
        #     self.neighbors.append(graph[row-1][col-1])
        # if row < rows - 1 and col > 0:
        #     self.neighbors.append(graph[row+1][col-1])
        # if row > 0 and col < cols -1:
        #     self.neighbors.append(graph[row-1][col+1])
        # if row < rows - 1 and col < cols - 1:
        #     self.neighbors.append(graph[row+1][col+ 1])

def get_path(current):
    path = [current]
    while current.previous != None:
        current = current.previous
        path.insert(0,current)

    return path

def min_f(nodes):
    curr_node = nodes[0]
    for i in nodes:
        if i.f < curr_node.f:
            curr_node = i
    
    return curr_node

def draw(path):
    for i in range(len(path)-1):
    # for i in path:
        # pygame.draw.rect(screen,(255,0,0),(i.col * size,i.row * size,size,size))
        pygame.draw.line(screen,(255,0,0),path[i].center,path[i+1].center,3)

graph = [[Node(i,j) for j in range(cols)] for i in range(rows)]
graph[0][0].g = 0
end = graph[rows - 1][cols-1]
graph[0][0].wall = False
graph[rows-1][cols-1].wall = False

def draw_maze():
    for i in range(rows):
        for j in range(cols):
            if graph[i][j].wall:
                pygame.draw.rect(screen,(0,0,0),(j * size,i * size,size,size))
                # pygame.draw.circle(screen,(0,0,0),graph[i][j].center,4)

def get_random_path(start, end):
    
    random_path = [start]
    current_node = random_path[0]

    while current_node != end:
        if current_node[1] != end[1] and current_node[0] != end[0]:
            val = random.choice([0] * 20 + [1] * 80)
            if val:
                random_path.append([current_node[0],current_node[1] + 1])
            else:
                random_path.append([current_node[0] + 1,current_node[1]])

        else:
            if current_node[1] == end[1]:
                random_path.append([current_node[0] + 1,current_node[1]])
            else:
                random_path.append([current_node[0],current_node[1] + 1])
        
        current_node = random_path[-1]

    return random_path

def getStartAndEndPoints():
    count = 0
    points = []
    coordinates = []
    prev_start = prev_end = -1

    while count < 6:
        start_point = random.randint(prev_start + 1, rows - 2)
        end_point = random.randint(max(start_point, prev_end + 1), rows - 2)

        points.append([graph[start_point][0], graph[end_point][cols - 1]])
        coordinates.append([[start_point, 0], [end_point, cols - 1]])

        if start_point == rows - 2 or end_point == rows - 2:
            break

        prev_start = start_point
        prev_end = end_point

        count+=1
    
    return points, coordinates

def astar_path():
    paths = []
    prev_path = []

    for point in points:
        reset_params()
        point[0].g = 0
        set_all_h(point[1])
        openSet = [point[0]]

        while openSet != []:
            current = min_f(openSet)
            if(current == point[1]):
                openSet = []
            else:
                openSet.remove(current)
                for n in current.neighbors:
                    if not n.wall and n not in prev_path:
                        tempg = current.g + 1
                        if tempg < n.g:
                            n.g = tempg
                            n.previous = current
                            n.f = n.g + n.h
                            if n not in openSet:
                                openSet.append(n)


            curr_path = get_path(current)
        
        prev_path = curr_path[::]
        paths.append(curr_path)

    return paths

def set_all_h(end):
    for i in range(rows):
        for j in range(cols):
            graph[i][j].get_h(end)

def reset_params():
    for i in range(rows):
        for j in range(cols):
            graph[i][j].f = 0
            graph[i][j].h = 0
            graph[i][j].g = 10**9
            graph[i][j].previous = None
    
points, coordinates = getStartAndEndPoints()

random_paths = []
print(coordinates)
for i in coordinates:
    path = get_random_path(i[0], i[1])
    random_paths.append(path)

for i in range(rows):
    for j in range(cols):
        graph[i][j].get_neighbors(graph)
        # graph[i][j].get_h(end)
        graph[i][j].is_wall()

set_all_h(end)
# openSet = [graph[0][0]]
paths = astar_path()
# for i in points:
#     print(len(i))

while True:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
            exit()

    screen.fill((255,255,255))
    # if openSet != []:
    #     current = min_f(openSet)
    #     if(current == end):
    #         print("In the end...")
    #         openSet = []
    #     else:
    #         openSet.remove(current)
    #         for n in current.neighbors:
    #             if not n.wall:
    #                 tempg = current.g + 1
    #                 if tempg < n.g:
    #                     n.g = tempg
    #                     n.previous = current
    #                     n.f = n.g + n.h
    #                     if n not in openSet:
    #                         openSet.append(n)

    #     curr_path = get_path(current)

    # if openSet == [] and current != end:
    #     print("solution not possible...")

    draw_maze()
    for path in paths:
        draw(path)

    pygame.display.update()
    clock.tick(120)
