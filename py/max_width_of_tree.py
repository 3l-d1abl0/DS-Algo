class Node:

    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

def getMaxWidth(root):

    if root is None:
        return 0

    #queue
    q =[]
    maxW = 0
    q.append(root)

    while q!=[]:

        noe = len(q)
        maxW = max(noe, maxW)

        while noe is not 0:
            temp = q.pop(0)
            noe-=1
            if temp.left is not None:
                q.append(temp.left)

            if temp.right is not None:
                q.append(temp.right)
    return maxW



if __name__ == '__main__':

    root = Node(1)
    root.left = Node(2)
    root.right = Node(3)
    root.left.left = Node(4)
    root.left.right = Node(5)

    root.right.right = Node(8)
    root.right.right.left = Node(6)
    root.right.right.right = Node(7)

    print 'Max Width {} '.format(getMaxWidth(root))
