
def calTempArray():
    arr = [0] * len(str2)
    j=0
    i=1
    while(i < len(str2)):
        if str2[j] == str2[i]:
            arr[i] = j + 1
            i+=1
            j+=1
        else:
            if j!=0:
                j = arr[j-1]
            else:
                i+=1
    
    return arr

def KMPAlgo():
    arr = calTempArray()
    i,j = 0,0
    while i < len(str1) and j < len(str2):
        if str1[i] == str2[j]:
            if j==len(str2) - 1:
                return i - j
            i+=1
            j+=1
        else:
            if j!=0:
                j = arr[j-1]
            else:
                i+=1

    return -1

str1 = input("Enter the main string: ")
str2 = input("Enter the pattern string: ")
print("Pattern exist at index:",KMPAlgo()) if KMPAlgo() >= 0 else print("Pattern doesn't exist...")
