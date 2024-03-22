from math import floor
import random

def display(A,n):
    for i in range(n):
        for j in range(n):
            print(A[i][j],end=" ")
        print()

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
            r.append(int(round(temp,2)))
        M.append(r)

    return M

# def L(A,n):
    B = []
    for i in A:
        B.append(i[::])

    for i in range(n):
        if B[i][i] != 0:
            for j in range(i+1,n):
                ratio = B[i][j] / B[i][i]
                for k in range(n):
                    B[k][j] -= floor(ratio * B[k][i])

        else:
            for j in range(i+1,n):
                if B[i][j] != 0:
                    for k in range(n):
                        B[k][i],B[k][j] = B[k][j],B[k][i]

            for j in range(i+1,n):
                ratio = B[i][j] / B[i][i]
                for k in range(n):
                    B[k][j] -= floor(ratio * B[k][i])

    for i in range(n):
        x = B[i][i]
        for j in range(i,n):
            B[j][i] = round(B[j][i] / x,3)
    return B

def LU(A,n):
    B = []
    for i in A:
        B.append(i[::])
    L = [[1 if i==j else 0 for i in range(n)] for j in range(n)]

    for i in range(n):
        if B[i][i] != 0:
            for j in range(i+1,n):
                ratio = B[j][i] / B[i][i]
                for k in range(n):
                    B[j][k] = round(B[j][k] - ratio * B[i][k],3)
                L[j][i]=round(ratio,3)

        else:
            for j in range(i+1,n):
                if B[j][i] != 0:
                    for k in range(n):
                        B[i][k],B[j][k] = B[j][k],B[i][k]
                    L[j][0],L[i][0] = L[i][0],L[j][0]

            for j in range(i+1,n):
                ratio = B[j][i] / B[i][i]
                for k in range(n):
                    B[j][k] -= floor(ratio * B[i][k])
    return L,B     


n = int(input("Enter the size of the square matrix: "))
A = [[random.randint(1,9) for _ in range(n)] for _ in range(n)]
# A = [[1,2,3],[4,8,6],[7,8,9]]
L,U = LU(A,n)
display(A,n)
print(".......")
print("Lower Triangular matrix is: ")
display(L,n)
print(".......")
print("Upper Triangular matrix is: ")
display(U,n)
print(".......")
print("Multiply of the two matrices is: ")
display(mat_mul(L,U),n)