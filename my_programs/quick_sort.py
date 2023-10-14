import random

def random_partition(arr,l,r):
    q = random.randint(l,r)
    arr[q],arr[r] = arr[r],arr[q]
    i = l-1

    for j in range(l,r):
        if arr[j] <= arr[r]:
            i += 1
            arr[j],arr[i] = arr[i],arr[j]

    arr[i + 1],arr[r] = arr[r],arr[i + 1]

    return i + 1

def quickSort(arr,l,r):
    if l < r:
        q = random_partition(arr,l,r)
        quickSort(arr,l,q-1)
        quickSort(arr,q + 1,r)

a = [4,1,3,7,6,9]
print(a)
quickSort(a,0,len(a) - 1)
print(a)