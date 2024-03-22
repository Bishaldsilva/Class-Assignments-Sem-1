import random

def calcArray(row):
    arr = [0] * len(row)
    i,j = 1,0
    while i < len(row):
        if row[j] == row[i]:
            arr[i] = j + 1
            j+=1
            i+=1
        else:
            if j != 0:
                j = arr[j - 1]
            else:
                i+=1
    
    return arr

def kmpAlgo(main_row,sub_row):
    arr = calcArray(sub_row)
    list_of_indices = []
    i,j = 0,0
    while i < len(main_row) and j < len(sub_row):
        if main_row[i] == sub_row[j]:
            if j == m - 1:
                list_of_indices.append(i - j)
                j = 0
            else:
                j+=1
                i+=1
        else:
            if j != 0:
                j = arr[j - 1]
            else:
                i+=1

    return list_of_indices

def intersection_list(list1,list2):
    final_list = []
    for i in list1:
        if i in list2:
            final_list.append(i)
    
    return final_list
            
def is_subset(mat1,mat2):
    for i,v in enumerate(mat1):
        list_of_indices = kmpAlgo(v,mat2[0])
        if list_of_indices != []:
            c = 1
            for j in range(1,m):
                list2 = kmpAlgo(mat1[i + j],mat2[j])
                i_list = intersection_list(list_of_indices,list2)
                if i_list != []:
                    list_of_indices = i_list
                    c+=1
                else:
                    break
            if c == m:
                return True

    return False
    

n = int(input("Enter the dimension of 1st matrix: "))
m = int(input("Enter the dimension of 2nd matrix: "))
mat1 = [[random.randint(1,9) for _ in range(n)] for _ in range(n)]
mat2 = [[random.randint(1,9) for _ in range(m)] for _ in range(m)]
# display(mat1,n)
# print()
# display(mat2,m)
print(is_subset(mat1,mat2))