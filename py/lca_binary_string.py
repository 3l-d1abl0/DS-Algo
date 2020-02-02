class Node:
    """docstring for Node."""
    def __init__(self, key):
        ##super(Node, self).__init__()
        self.data = key
        self.left = Node
        self.right = Node

def getLCA(root, n1, v1, n2, v2):

    if root is None:
        return None

    if root is n1:
        v1[0]=True
        return root

    if root is n2:
        v2[0]= True
        return root

    print root.__dict__
    left = getLCA(root.left, n1, v1,  n2,v2)
    right = getLCA(root.right, n1,v1, n2,v2)

    if left and right:
        return root

    return left if left is not None else right

def findL(root, n):
    if root is None:
        return False

    if root is n or findL(root.left, n) or findL(root.right, n):
        return True

    return False

def findLCA(root, n1, n2):

    v1 = [False]
    v2 = [False]

    lca = getLCA(root, n1,v1, n2,v2)

    if v1[0] and v2[0] :
        return lca
    elif v1[0] and findL(lca, n2):
        return lca
    elif v2[0] and findL(lca, n2):
        return lca
    else:
        return False

if __name__=="__main__":

    print '#######'

    '''
        Node *start = new Node(20);
    start->left = new Node(8);
    start->right = new Node(22);
    start->right->right = new Node(25);

    start->left->left = new Node(4);
    start->left->right = new Node(12);

    start->left->right->left = new Node(10);
    start->left->right->right = new Node(14);
    //                                20
//                        8                  22
//                4           12                25
//                          10    14
    '''

    root = Node(20)
    root.left = Node(8)
    root.right = Node(22)
    root.right.left = Node(25)

    root.left.left = Node(4)
    root.left.right = Node(12)

    root.left.right.left = Node(10)
    root.left.right.right = Node(14)

    lcs = findLCA(root, root.left.left, root.left.right.right)
