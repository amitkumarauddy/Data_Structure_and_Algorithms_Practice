class Node:
    def __init__(self, key):
        self.key = key
        self.right = None
        self.left = None

def insert(root,key):
    if root is None:
        return Node(key)
    
    if key < root.key:
        root.left = insert(root.left,key)
    else:
        root.right = insert(root.right,key) 
    return root
    
def inorder(root):
    if root:
        inorder(root.left)
        print(root.key, end= ' ')
        inorder(root.right)

def build_bst():
    root = None
    print("Enter numbers to Insert into BST (type 'done' to finish): ")
    while True:
        val = input("Enter value: ")
        if val.lower() == 'done':
            break
        try:
            num = int(val)
            root = insert(root,num)
        except ValueError:
            print("Please enter a valid integer.")
    return root

if __name__ == "__main__":
    bst_root = build_bst()
    print("\nInorder Traversal of the BST")
    inorder(bst_root)