class Node:

    def __init__(self, key):
        self.right = None
        self.left = None
        self.val = key

def morris_in(root):

    curr = root

    while curr is not None:

        if curr.left is None:
            print curr.val,
            curr = curr.right

        else:

            #Look for inorder Predescessor
            pre = curr.left
            while(pre.right is not None and pre.right is not curr):
                pre = pre.right

            if pre.right is None:   #Linking
                pre.right = curr
                curr= curr.left
            else:
                pre.right = None    #Un-link
                print curr.val,
                curr= curr.right

def morris_pre(root):

    curr = root

    while curr is not None:

        if curr.left is None:
            print curr.val,
            curr = curr.right

        else:

            #Looking for InOrder Predescessor
            pre = curr.left
            while(pre.right is not None and pre.right is not curr):
                pre = pre.right

            if pre.right is None : #Linking
                pre.right = curr
                print curr.val,
                curr = curr.left
            else:
                pre.right = None
                curr = curr.right


if __name__ == "__main__":

    root = Node(10)
    root.left = Node(8)
    root.right = Node(2)
    root.right.left = Node(12)
    root.left.right = Node(5)
    root.left.left = Node(3)
    root.left.right.left = Node(2)

#                   10
#                /      \
#            8            2
#          /     \      /
#       3        5    12
#              /
#             2

# 3 8 2 5 10 12 2
    print '\n Morris Inorder : '
    morris_in(root)

# 10 8 3 5 2 2 12
    print '\n Morris Preorder : '
    morris_pre(root)
