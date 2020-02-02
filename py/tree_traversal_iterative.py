class Node:

    def __init__(self, key):
        self.left = None
        self.right = None
        self.val = key

def pre_iterative(root):

    if root is None:
        return

    st = [] #stack
    st.append(root)

    while(len(st)>0):

        node = st.pop()
        print node.val,

        if node.right is not None:
            st.append(node.right)

        if node.left is not None:
            st.append(node.left)

def in_iterative(root):

    curr = root
    st = []
    flag = True

    while(flag):

        if curr is not None:
            st.append(curr)
            curr=curr.left
        else:

            if(len(st)>0):
                curr = st.pop()
                print curr.val,
                curr = curr.right
            else:
                flag = False

def post_iterative(root):

    if root is None:
        return

    st = []
    curr = root

    while(True):

        while(curr is not None):

            if curr.right is not None:
                st.append(curr.right)
            st.append(curr)
            curr = curr.left

        curr = st.pop()

        if ( (curr.right and len(st)>0) and curr.right == st[-1] ):
            st.pop()
            st.append(curr)
            curr = curr.right
        else:
            print curr.val,
            curr= None


        if(len(st)<=0):
            break


if __name__ == "__main__":

    root = Node(1)
    root.left = Node(2)
    root.right = Node(3)
    root.left.left = Node(4)
    root.left.right = Node(5)

    print 'Iterative PreOrder : '
    pre_iterative(root)

    print '\n Iterative InOrder : '
    in_iterative(root)

    print '\n Iterative PostOrder: '
    post_iterative(root)
