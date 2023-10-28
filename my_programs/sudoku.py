board = []
n = 9

for i in range(n):
    x = list(map(int,input().split(' ')))
    board.append(x)

def isSafe(board,row,col,val):
    for i in range(n):
        if board[row][i] == val:
            return False
        if board[i][col] == val:
            return False
        
        if board[3 * (row // 3) + i // 3][3 * (col // 3) + i % 3] == val:
            return False

    return True

def solve(board):
    for i in range(n):
        for j in range(n):
            if board[i][j] == 0:
                for v in range(1,n + 1):
                    if isSafe(board,i,j,v):
                        board[i][j] = v
                        if solve(board):
                            return True
                        else:
                            board[i][j] = 0

                return False
    
    return True

def display():
    for i in range(n):
        for j in range(n):
            print(board[i][j],end=' ')
        print()

solve(board)
for _ in range(50):
    print("_",end='')
print()
display()