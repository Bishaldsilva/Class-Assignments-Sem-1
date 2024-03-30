

file = open("./Sem 2/OS_Lab/Assignment 1/all_data.txt","r")
lines = file.readlines()

f2 = open("./Sem 2/OS_Lab/Assignment 1/List25.txt","w")
f3 = open("./Sem 2/OS_Lab/Assignment 1/List50.txt","w")

f2.writelines(lines[1:26])
f3.writelines(lines[26:76])

f2 = open("./Sem 2/OS_Lab/Assignment 1/List25.txt","r")
f3 = open("./Sem 2/OS_Lab/Assignment 1/List50.txt","r")

print("The number of entries in the List25 file is: ", len(f2.readlines()))
print("The number of entries in the List50 file is: ", len(f3.readlines()))