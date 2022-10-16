class Node:
    def __init__(self, key):
        self.left = None
        self.right = None
        self.val = key
 
def insert(root, key):
    if root is None:
        return Node(key)
    else:
        if root.val == key:
            return root
        elif root.val < key:
            root.right = insert(root.right, key)
        else:
            root.left = insert(root.left, key)
    return root
 
def preorder(root):
    if root:
        print(root.val, end = " ")
        preorder(root.left)
        preorder(root.right)
        
def postorder(root):
    if root:
        postorder(root.left)
        postorder(root.right)
        print(root.val, end = " ")
    
a = input()
temp = a.split(" ")
r = Node(int(temp[-1]))

while (a != "#"):
    a = input();
    temp = a.split(" ")
    
    if (temp[0] == "insert"):
        r = insert(r, int(temp[1]))
    if (temp[0] == "postorder"):
        postorder(r)
    if (temp[0] == "preorder"):
        preorder(r)

