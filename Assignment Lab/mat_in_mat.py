import random

def is_equal(mat1,mat2,sr,sc):
    flag = 1

    for i in range(m):
        for j in range(m):
            if mat1[sr + i][sc + j] != mat2[i][j]:
                flag = 0
                break
    
    return True if flag == 1 else False

def is_subset(mat1,mat2):
    flag = 0

    for i in range(n):
        for j in range(n):
            start_row = i
            end_row = i + m
            start_col = j
            end_col = j + m

            if end_row <= n and end_col <= n and mat1[start_row][start_col] == mat2[0][0]:
                if is_equal(mat1,mat2,start_row,start_col):
                    flag = 1
                    break

    return True if flag == 1 else False

def display(mat,size):
    for i in range(size):
        for j in range(size):
            print(mat[i][j],end=' ')
        print()

n = int(input("Enter the dimension of 1st matrix: "))
m = int(input("Enter the dimension of 2nd matrix: "))
mat1 = [[random.randint(1,9) for _ in range(n)] for _ in range(n)]
mat2 = [[random.randint(1,9) for _ in range(m)] for _ in range(m)]
# display(mat1,n)
# print()
# display(mat2,m)
print(is_subset(mat1,mat2))