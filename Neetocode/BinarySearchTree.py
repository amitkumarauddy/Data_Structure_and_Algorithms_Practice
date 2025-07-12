#Inorder Traversal
class Node:
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None

def insert(root, key):
    if root is None:
        return Node(key)
    if key < root.key:
        root.left = insert(root.left, key)
    else:
        root.right = insert(root.right, key)
    return root

def inorder(root):
    if root:
        inorder(root.left)
        print(root.key, end=' ')
        inorder(root.right)

# User input section
def build_bst():
    root = None
    print("Enter numbers to insert into BST (type 'done' to finish):")
    while True:
        val = input("Enter value: ")
        if val.lower() == 'done':
            break
        try:
            num = int(val)
            root = insert(root, num)
        except ValueError:
            print("Please enter a valid integer.")
    return root

# Main execution
if __name__ == "__main__":
    bst_root = build_bst()
    print("\nInorder traversal of the BST:")
    inorder(bst_root)