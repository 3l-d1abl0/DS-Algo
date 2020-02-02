from collections import deque

class Node:
    def __init__(self, data):
        self.key = data
        self.left = None
        self.right = None

def levelOrder(root):

    if root is None:
        return

    q = deque()
    q.append(root)

    q.append(None)

    while q:

        tmp = q.popleft()
        if tmp is None:
            if q.__len__() is not 0:
                q.append(None)
                print "\n"
                continue
            else:
                break

        print tmp.key,

        if tmp.left is not None:
            q.append(tmp.left)

        if tmp.right is not None:
            q.append(tmp.right)


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

    print 'Level Order'
    levelOrder(root)
