class Node:

    def __init__(self, data):
        self.data = data
        self.left = self.right = None

def getLca(root, a1, a2):

    if root == None:
        return None

    if root.data == a1 or root.data == a2 :
        return root

    left = getLca(root.left, a1,a2)
    right = getLca(root.right, a1, a2)

    if left is not None and right is not None:
        return root
    if left is not None:
        return left
    else:
        return right

def getDist(root, n,lvl):

    if root is None:
        return None

    if root.data == n:
        return lvl

    left = getDist(root.left, n, lvl+1)
    if left is not None:
        return left

    right = getDist(root.right, n, lvl+1)
    if right is not None:
        return right



def findDistance(root, a1,a2):

    lca = getLca(root, a1, a2)
    print 'LCA : {}'.format(lca.data)
    leftD = getDist(lca.left, a1,1)
    rightD = getDist(lca.right, a2,1)
    print 'Left : {} Right : {}'.format(leftD,rightD)
    return leftD+rightD

if __name__ == '__main__':
    #main()
    root = Node(1)
    root.left = Node(2)
    root.right = Node(3)
    root.left.left = Node(4)
    root.left.right = Node(5)
    root.right.left = Node(6)
    root.right.right = Node(7)
    root.right.left.right = Node(8)

    print 'Distance between {} and {} : {}'.format(8,7,findDistance(root, 8, 7))
