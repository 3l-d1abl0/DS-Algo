class Node:

    def __init__(self, data):
        self.key = data
        self.left = None
        self.right = None

def leftView(root, level, max_level):

    if root is None:
        return

    if max_level[0] < level :
        print root.key
        max_level[0] = level

    leftView(root.left, level+1, max_level)
    leftView(root.right, level+1, max_level)


def left_view(root):
    max_level = [0]
    leftView(root, 1, max_level)

def rightView(root, level, max_level):

    if root is None:
        return

    if max_level[0] < level:
        print root.key
        max_level[0] = level

    rightView(root.right, level+1, max_level)
    rightView(root.left, level+1, max_level)

def right_view(root):
    max_level = [0]
    rightView(root, 1, max_level)

if __name__ == "__main__":

    root = Node(10)
    root.left = Node(8)
    root.right = Node(24)
    root.right.left = Node(12)
    root.left.right = Node(5)
    root.left.left = Node(3)
    root.left.right.left = Node(2)

#                   10(0)
#                /        \
#            8(-1)        24(+1)
#          /     \      /
#       3(-2)    5(0)  12(0)
#              /
#             2(-1)

    print 'Left View : '
    left_view(root)

    print 'Right View : '
    right_view(root)
