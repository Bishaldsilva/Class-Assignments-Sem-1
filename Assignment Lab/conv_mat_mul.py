import random

def make_matrix():
    margin = [0] * (n + (m - 1))
    mat_copy = []
    for i in range((m - 1) // 2):
        mat_copy.append(margin)
    
    for i in range(n):
        mat_copy.append([0] * ((m - 1) // 2) + mat1[i] + [0] * ((m - 1) // 2))
    
    for i in range((m - 1) // 2):
        mat_copy.append(margin)
    
    return mat_copy

def sub_mult(mat, sub_mat, x, y):
    for i in range(m):
        for j in range(m):
            mat[x + i][y + j] = mat[x + i][y + j] * sub_mat[i][j]
    

def mult():
    margin_len = (m - 1) // 2
    mat_copy = make_matrix()
    for i in range(n - 1):
        for j in range(n - 1):
            sub_mult(mat_copy, mat2, i, j)
    
    return mat_copy

n = 9
m = 3
mat1 = [[random.randint(1,9) for _ in range(n)] for _ in range(n)]
mat2 = [[random.randint(1,9) for _ in range(m)] for _ in range(m)]
print(mult())