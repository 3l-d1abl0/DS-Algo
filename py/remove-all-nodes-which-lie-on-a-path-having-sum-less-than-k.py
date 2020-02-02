class Node(object):
    """docstring for Node."""
    def __init__(self, data):
        #super(Node, self).__init__()
        self.key = data
        self.left = None
        self.right = None

def inOrder(root):
    if root is None:
        return

    inOrder(root.left)
    print root.key,
    inOrder(root.right)

def prune(root, K):

    if root is None:
        return None

    root.left = prune(root.left, K-root.key)
    root.right = prune(root.right, K-root.key)

    if root.left is None and root.right is None:
        if root.key< K:
            return None

    return root

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


    print 'Before Pruning :'
    inOrder(root)

    K = 45
    prune(root, K)

    print '\n After Pruning : '
    inOrder(root)
