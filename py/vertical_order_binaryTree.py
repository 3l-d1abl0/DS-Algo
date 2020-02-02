class Node:
    def __init__(self, key):
        self.left = None
        self.right = None
        self.data = key

def verticalOrder(root, m, hd):

    if root is None:
        return

    if hd in m:
        m[hd].append(root.data)
    else:
        m[hd]= [root.data]


    verticalOrder(root.left, m, hd-1)
    verticalOrder(root.right, m, hd+1)


def vOrder(root):

    m = dict()
    hd =0
    verticalOrder(root, m, hd)

    for idx,val in enumerate(sorted(m)):

        for i in m[val]:
            print i,

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
#                /      \
#            8(-1)      24(+1)
#          /     \      /
#       3(-2)    5(0)  12(0)
#              /
#             2(-1)

    vOrder(root)
