class Node:
    def __init__(self, key):
        self.left = None
        self.right = None
        self.data = key
        self.hd =None

def printLeft(root):

    if root.left:
        print(root.data)
        printLeft(root.left)

    elif root.right:
        print(root.data)
        printLeft(root.right)

def printRight(root):

    if root.right:
        printRight(root.right)
        print(root.data)

    elif root.left:
        printRight(root.left)
        print(root.data)

def printBottomBoundary(root):

    if root is None:
        return

    if root.left is None and root.right is None:
        print(root.data)
        return

    printBottomBoundary(root.left)
    printBottomBoundary(root.right)


def boundaryTraversal(root):

    if root is None:
        return

    print(root.data)

    printLeft(root.left)

    printBottomBoundary(root.left)
    printBottomBoundary(root.right)

    printRight(root.right)

if __name__ == "__main__":

    root = Node(10)
    root.left = Node(8)
    root.right = Node(24)
    root.right.left = Node(12)
    root.right.left.right = Node(22)
    root.left.right = Node(5)
    root.left.left = Node(3)
    root.left.right.left = Node(2)

    #                   10(0)
    #                /        \
    #            8(-1)        24(+1)
    #          /     \      /
    #       3(-2)    5(0)  12(0)
    #              /        \
    #             2(-1)     22

    boundaryTraversal(root)
