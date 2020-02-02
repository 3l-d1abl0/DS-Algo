class Node(object):
    """docstring for ."""
    def __init__(self, data):
        #super(, self).__init__()
        self.data = data
        self.left = None
        self.right = None

def inOrder(root):
    if root is None:
        return

    inOrder(root.left)
    print root.data
    inOrder(root.data)

def printNodeAtK(root, target, K):

    if root is None:
        return -1

    if root == target:
        printKDown(root,K)
        return 0

    leftD = printNodeAtK(root.left, target, K)
    if leftD is not -1:

        if leftD+1 == K:
            print root.data
        else:
            printKDown(root.right, K-(leftD+2))

        return 1+leftD

    rightD = printNodeAtK(root.right, target, K)
    if rightD is not -1:

        if rightD+1 == K:
            print root.data
        else:
            printKDown(right.left, K-(rightD+2))

        return 1+rightD

    return -1

if __name__ == '__main__':
    root = Node(1)
    root.left = Node(2)
    root.right = Node(3)
    root.left.left = Node(4)
    root.left.right = Node(5)
    root.right.left = Node(6)
    root.right.right = Node(7)
    root.left.left.left = Node(8)
    root.left.left.right = Node(9)
    root.left.right.left = Node(12)
    root.right.right.left = Node(10)
    root.right.right.left.right = Node(11)
    root.left.left.right.left = Node(13)
    root.left.left.right.right = Node(14)
    root.left.left.right.right.left = Node(15)

    '''
          1
      /      \
     2        3
   /   \     /  \
  4     5   6    7
 / \    /       /
8   9  12      10
   / \           \
  13  14         11
      /
     15
    '''

    K =5
    target = root.left.right
    printNodeAtK(root, target, K)
