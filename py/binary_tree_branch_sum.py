class BinaryTree(object):
    """docstring for BinartTree."""

    def __init__(self, data):

        self.key = data
        self.left = None
        self.right = None

def branchSum(root, runningSum, sum_array):

    runningSum = runningSum + root.key

    if root.left is None and root.right is None:
        sum_array.append(runningSum)
        return

    if root.left is not None:
        branchSum(root.left, runningSum, sum_array)


    if root.right is not None:
        branchSum(root.right, runningSum, sum_array)

if __name__ == '__main__':

    '''

    root = BinaryTree(0)
    root.left = BinaryTree(9)
    root.right = BinaryTree(1)
    root.right.left = BinaryTree(15)
    root.right.right = BinaryTree(10)
    root.right.right.left = BinaryTree(100)
    root.right.right.right = BinaryTree(200)
    #[9, 16, 111, 211]
    '''

    '''
    root = BinaryTree(0)
    root.right = BinaryTree(1)
    root.right.right = BinaryTree(10)
    root.right.right.right = BinaryTree(100)
    #[111]
    '''

    '''
    root = BinaryTree(0)
    root.left = BinaryTree(1)
    root.left.left = BinaryTree(10)
    root.left.left.left = BinaryTree(100)
    #[111]
    '''

    root = BinaryTree(1)
    root.left = BinaryTree(2)
    root.right = BinaryTree(3)
    root.left.left = BinaryTree(4)
    root.left.right = BinaryTree(5)
    root.right.left = BinaryTree(6)
    root.right.right = BinaryTree(7)
    root.left.left.left = BinaryTree(8)
    root.left.left.right = BinaryTree(9)
    root.left.right.left = BinaryTree(10)
    root.right.left = BinaryTree(6)
    root.right.right = BinaryTree(7)
    #[15, 16, 18, 10, 11]

    sum_array = []

    branchSum(root, 0, sum_array)

    print(sum_array)
