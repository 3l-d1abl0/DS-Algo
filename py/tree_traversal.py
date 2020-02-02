class Node:

    def __init__(self, key):
        self.left= None
        self.right= None
        self.val = key

def printPre(root):
    if root:
        #print '{}'.format(root.val)
        print (root.val),

        printPre(root.left)
        printPre(root.right)

def printIn(root):
    if root:

        printIn(root.left)
        #print '{}'.format(root.val)
        print (root.val),
        printIn(root.right)


def printPost(root):
    if root:

        printPost(root.left)
        printPost(root.right)
        print (root.val),



if __name__ == '__main__':

    root = Node(1)
    root.left = Node(2)
    root.right = Node(3)
    root.left.left = Node(4)
    root.left.right = Node(5)

    print 'PreOrder : '
    printPre(root)

    print '\nInOrder : '
    printIn(root)

    print '\nPostOrder : '
    printPost(root)

    print '\nPreOrder : '
    printPost(root)
