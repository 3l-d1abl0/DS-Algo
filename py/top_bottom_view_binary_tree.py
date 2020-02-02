from collections import deque

class Node:
    def __init__(self, key):
        self.left = None
        self.right = None
        self.data = key
        self.hd =None

def topView(root):

    q = deque()
    m = dict()

    root.hd =0
    q.append(root)
    m[root.hd]= root.data

    while q:

        tmp = q.popleft()

        if tmp.left is not None:
            q.append(tmp.left)
            tmp.left.hd = tmp.hd-1
            if tmp.left.hd in m:
                pass
            else:
                m[tmp.left.hd]= tmp.left.data


        if tmp.right is not None:
            q.append(tmp.right)
            tmp.right.hd = tmp.hd+1
            if tmp.right.hd in m:
                pass
            else:
                m[tmp.right.hd] = tmp.right.data

    #print m
    for idx,val in enumerate(sorted(m)):
        print m[val],

    print

def bottomView(root):

    q = deque()
    m = dict()

    root.hd =0
    q.append(root)
    m[root.hd]= root.data

    while q:

        tmp = q.popleft()

        if tmp.left is not None:
            q.append(tmp.left)
            tmp.left.hd = tmp.hd-1
            if tmp.left.hd in m:
                m[tmp.left.hd] = tmp.left.data
            else:
                m[tmp.left.hd]= tmp.left.data


        if tmp.right is not None:
            q.append(tmp.right)
            tmp.right.hd = tmp.hd+1
            if tmp.right.hd in m:
                m[tmp.right.hd] = tmp.right.data
            else:
                m[tmp.right.hd] = tmp.right.data

    #print m
    for idx,val in enumerate(sorted(m)):
        print m[val],

    print


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

    print 'Top View : '
    topView(root)

    print 'Bottom View : '
    bottomView(root)
