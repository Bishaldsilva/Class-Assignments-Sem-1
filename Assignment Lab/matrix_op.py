from math import floor
import random

def display(A,n):
    for i in range(n):
        for j in range(n):
            print(A[i][j],end=" ")
        print()

def get_minor(A,row,col,n):
    B = []
    for i in range(n):
        temp = []
        for j in range(n):
            if row == i or col == j:
                continue
            temp.append(A[i][j])
        if temp != []:
            B.append(temp)
    return B

def mat_mul(A,B):
    M = []
    if len(A[0]) != len(B):
        print("Multiplication is not possible")
        return
    rows = len(A)
    cols = len(B[0])
    c = len(B)
    for i in range(rows):
        r = []
        for j in range(cols):
            temp = 0
            for k in range(c):
                temp += A[i][k] * B[k][j]
            r.append(round(temp,2))
        M.append(r)

    return M

def largest_eigen_value(A,n):
    values = []
    X = [[1] for i in range(n)]
    while True:
        eigen_vector = mat_mul(A,X)
        eigen_value = round(max(eigen_vector)[0],2)

        if eigen_value in values:
            return eigen_value

        values.append(eigen_value)
        for i in range(n):
            X[i][0] = round(eigen_vector[i][0] / eigen_value,2)

        
def transpose(A,n):
    B = []
    for i in A:
        B.append(i[::])
    
    for i in range(n):
        for j in range(i,n):
            B[i][j],B[j][i] = B[j][i],B[i][j]

    return B

def cofactor(A,n):
    B = []
    for i in range(n):
        temp = []
        for j in range(n):
            x = determinant(get_minor(A,i,j,n),n-1)
            sign = pow(-1,i+j+2)
            temp.append(sign*x)

        B.append(temp)

    return B

def inverse(A,n):
    det = determinant(A,n)
    if det == 0:
        print("Inverse not possible")
        return
    B = transpose(cofactor(A,n),n)
    for i in range(n):
        for j in range(n):
            B[i][j] = round(B[i][j] / det,4)

    return B

def determinant(A,cols):
    if cols == 1:
        return A[0][0]
    if cols == 2:
        return A[0][0] * A[1][1] - A[0][1] * A[1][0]
    else:
        ans = 0
        sign = "+"
        for i in range(cols):
            if sign == "+":
                ans += A[0][i] * determinant(get_minor(A,0,i,cols),cols - 1)
                sign = "-"
            else:
                ans -= A[0][i] * determinant(get_minor(A,0,i,cols),cols - 1)
                sign = "+"
        return ans

def rank(A,n):
    B = []
    for i in A:
        B.append(i[::])
    c = n
    for i in range(n):
        if B[i][i] != 0:
            for j in range(i+1,n):
                ratio = B[j][i] / B[i][i]
                for k in range(n):
                    B[j][k] -= floor(ratio * B[i][k])
        else:
            for j in range(i+1,n):
                if B[j][i] != 0:
                    for k in range(n):
                        B[i][k],B[j][k] = B[j][k],B[i][k]

            for j in range(i+1,n):
                ratio = B[j][i] / B[i][i]
                for k in range(n):
                    B[j][k] -= floor(ratio * B[i][k])

    # display(B,n)
    for i in range(n):
        flag = 0
        for j in range(n):
            if B[i][j] != 0:
                flag = 1
        if flag == 0:
            c -= 1
    return c

n = int(input())
A = [[random.randint(1,9) for i in range(n)] for j in range(n)]
# A = [[1,2,3],[4,8,6],[7,8,9]]
display(A,n)
r = rank(A,n)
print("rank of the matrix is: ",r)
print(f"determinant of the matrix is {determinant(A,n)}")
print(f"largest eigen value is {largest_eigen_value(A,n)}")
print("Inverse of the matrix is: ")
display(mat_mul(A,inverse(A,n)),n)
# print(mat_mul([[1,4,8],[3,2,3],[1,7,3]],[[1.0], [0.61], [0.84]]))