import pygame
import math

pygame.init()
screen = pygame.display.set_mode((600,600))
clock = pygame.time.Clock()
points = []
cors = set()
gameActive = False

def drawPoints():
    for i,j in points:
        pygame.draw.circle(screen,(255,255,255),(i,600-j),5)

def angle(p1,p2):
    return math.atan2((p2[1] - p1[1]),(p2[0] - p1[0]))

def dist(p1,p2):
    xd = p2[0] - p1[0]
    yd = p2[1] - p1[1]
    return math.sqrt(xd**2+yd**2)

# Calculates the slope difference between two lines in 2d plane. if > 0 then counter clockwise
def is_counterClockwise(p1,p2,p3):
    left = (p3[1] - p2[1]) * (p2[0] - p1[0])
    right = (p2[1] - p1[1]) * (p3[0] - p2[0])

    # if left > right:
    #     return True
    # return False
    return left - right

def get_hull():
    # calculates the min point wrt of its y coordinate
    po = min(points,key=lambda p:(p[1],p[0]))
    #sorting every point wrt to their angle with po
    points.sort(key=lambda p:(angle(po,p),dist(po,p)))

    hull = []
    for i in range(len(points)):

        # this condition checks if a point is counter clockwise wrt to the last two point in hull.
        # if not then remove the last point in hull
        while len(hull) >= 2 and not is_counterClockwise(hull[-2],hull[-1],points[i]) > 0:
            hull.pop()
        hull.append(points[i])

    return hull

def closest_pair(X,Y):
    n = len(X)
    p1,p2 = [],[]
    if n==2: 
        return X[0],X[1],dist(X[0],X[1])
    if n==3: 
        d1 = dist(X[0],X[1])
        d2 = dist(X[1],X[2])
        d3 = dist(X[0],X[2])
        d =  min(d1,d2,d3)
        if d1 == d:
            return X[0],X[1],d1
        elif d2 == d:
            return X[1],X[2],d2
        else:
            return X[0],X[2],d3

    mid = n//2
    mid_element = X[mid]
    pl1,pl2,dl = closest_pair(X[:mid],Y)
    pr1,pr2,dr = closest_pair(X[mid:],Y)
    
    if dr <= dl:
        p1 = pr1
        p2 = pr2
        d = dr
    else:
        p1 = pl1
        p2 = pl2
        d = dl

    s = [i for i in Y if i[0] >= mid_element[0] - d and i[0] <= mid_element[0] + d]
    for i in range(len(s)):
        for j in range(i + 1,i + 8):
            if j < len(s):
                if d > dist(s[i],s[j]):
                    d = dist(s[i],s[j])
                    p1 = s[i]
                    p2 = s[j]

    return p1,p2,d

# returns the cross product of three points in 2d plane(not required here).
def crossProduct(p,q,r):
    return ((q[0]-p[0])*(r[1]-p[1])-(r[0]-p[0])*(q[1]-p[1]))

def rotating_caliper(points):
    n = len(points)

    if n==1: return 0
    if n==2: return dist(points[0],points[1])

    k = 1
    # getting the farthest point from hull[0] and hull[n-1]
    while is_counterClockwise(points[n-1],points[0],points[(k+1) % n]) > is_counterClockwise(points[n-1],points[0],points[k]):
        k +=1

    res = 0
    p1=[]
    p2=[]

    # checking the farthest point for each i = 0 to k and recording the points of max distance and the distance
    for i in range(k + 1):
        j = (i + 1) % n
        while is_counterClockwise(points[i],points[(i+1) % n],points[(j+1) % n]) > is_counterClockwise(points[i],points[(i + 1) % n],points[j]):
            if res < dist(points[i],points[(j+1) % n]):
                res = dist(points[i],points[(j+1) % n])
                p1 = points[i]
                p2 = points[(j+1) % n]
            j = (j+1) % n

    return p1,p2,res

def max_dist(points):
    n = len(points)

    res = 0
    for i in range(n):
        for j in range(i + 1,n):
            res = max(res,dist(points[i],points[j]))

    return res

while True:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
            exit()
        if event.type == pygame.KEYDOWN:
            if event.key == pygame.K_SPACE and not gameActive:
                X = sorted(points,key=lambda p:p[0])
                Y = sorted(points,key=lambda p:p[1])
                p1,p2,d = closest_pair(X,Y)
                print(f"Closest distance between two points is {d}")
                hull = get_hull()
                p3,p4,d1 = rotating_caliper(hull)
                d2 = max_dist(hull)
                print(f"largest distance between two points is {d1},{d2}")
                gameActive = True

    screen.fill(0)

    drawPoints()
    if not gameActive:
        if pygame.mouse.get_pressed()[0]:
            x,y = pygame.mouse.get_pos()
            if (x,y) not in cors:
                points.append([x,600-y])
                cors.add((x,y))

    else:
        for i in range(len(hull) - 1):
            pygame.draw.line(screen,(255,0,0),(hull[i][0],600 - hull[i][1]),(hull[i + 1][0],600 - hull[i + 1][1]))
        pygame.draw.line(screen,(255,0,0),(hull[-1][0],600 - hull[-1][1]),(hull[0][0],600 - hull[0][1]))
        
        pygame.draw.circle(screen,(0,255,0),(p1[0],600-p1[1]),5)
        pygame.draw.circle(screen,(0,255,0),(p2[0],600-p2[1]),5)
        pygame.draw.line(screen,(0,255,0),(p1[0],600-p1[1]),(p2[0],600-p2[1]))

        pygame.draw.circle(screen,(232, 82, 23),(p3[0],600-p3[1]),5)
        pygame.draw.circle(screen,(232, 82, 23),(p4[0],600-p4[1]),5)
        pygame.draw.line(screen,(232, 82, 23),(p3[0],600-p3[1]),(p4[0],600-p4[1]))


    pygame.display.update()
    clock.tick(60)