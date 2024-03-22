class Node:
    def __init__(self,val):
        self.left = None
        self.val = val
        self.right = None

class Tree:
    def __init__(self,size = None) -> None:
        self.root = None
        self.size = size

    def create(self):
        print("Enter the values:")
        for i in range(self.size):
            n = int(input())
            self.root = self.insert(self.root,n)

    def insert(self,root,val):
        if root == None:
            root = Node(val)
            return root

        if root.val == val:
            return root
        if val > root.val:
            root.right = self.insert(root.right,val)
        else:
            root.left = self.insert(root.left,val)

        return root

    # Ignore it...
    def delete(self,root,val):
        if root == None:
            return root
        if val > root.val:
            root.right = self.delete(root.right,val)
        elif val < root.val:
            root.left = self.delete(root.left,val)
        else:
            # case 1 both child empty
            if root.left == None and root.right == None:
                root = None
            # case 2: one of the child is empty
            elif root.left == None:
                root = root.right
            elif root.right == None:
                root = root.left
            # case 3: both child not empty
            else:
                temp = self.findMin(root.right)
                print(temp.val)
                root.val = temp.val
                root.right = self.delete(root.right,temp.val)
        return root
    # Ignore it too...
    def findMin(self,root):
        if root.left == None:
            return root
        return self.findMin(root.left)
    
    def search(self,root,val):
        if root == None or val == root.val:
            return root
        if val > root.val:
            return self.search(root.right,val)
        else:
            return self.search(root.left,val)

    def display(self,root):
        if root:
            self.display(root.left)
            print(f"{root.val} ",end=" ")
            self.display(root.right)


# calculating union
def union(set1,set2,union_set):
    def get_union(set1,union_set):
        if set1:
            get_union(set1.left,union_set)
            union_set.root = union_set.insert(union_set.root,set1.val)
            get_union(set1.right,union_set)

    get_union(set1.root,union_set)
    get_union(set2.root,union_set)

# calculation intersection
def intersction(set1,set2,intersection_set):

    def get_s(root,set2,intersection_set):
        if root:
            get_s(root.left,set2,intersection_set)
            if set2.search(set2.root,root.val):
                intersection_set.root = intersection_set.insert(intersection_set.root,root.val)
            get_s(root.right,set2,intersection_set)

    get_s(set1.root,set2,intersection_set)

n = int(input("Enter the size of the 1st set: "))
set1 = Tree(n)
set1.create()

n = int(input("Enter the size of the 2nd set: "))
set2 = Tree(n)
set2.create()

union_set = Tree()
union(set1,set2,union_set)
print("The union of the two set is: ")
union_set.display(union_set.root)
print()

intersection_set = Tree()
intersction(set1,set2,intersection_set)
print("Intersection of the two set is: ")
intersection_set.display(intersection_set.root)