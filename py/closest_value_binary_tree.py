
class BinaryTree(object):
    """docstring for BinartTree."""

    def __init__(self, data):

        self.key = data
        self.left = None
        self.right = None

def closestValueInTree(root, target, closestValue):
    if root is None:
        #print("1. return = {}".format(closestValue))
        return closestValue

    if abs(target - root.key) < abs(target - closestValue) :
        closestValue = root.key
        #print("closest = {}".format(closestValue))

    if target > root.key :
        return closestValueInTree(root.right, target, closestValue)
    elif target < root.key:
        return closestValueInTree(root.left, target, closestValue)
    else:
        #print("2. return = {}".format(closestValue))
        return closestValue


def closestValueInItrTree(root, target, closestValue):
    node = root
    while node is not None:

        if abs(target-node.key) < abs(closestValue-node.key):
            closestValue = node.key

        if node is not None and target > node.key:
            node = node.right
        elif node is not None and target < node.key:
            node = node.left
        else:
            return closestValue

    return closestValue

if __name__ == '__main__':

    root = BinaryTree(10)
    root.left = BinaryTree(5)
    root.right = BinaryTree(15)
    root.left.left = BinaryTree(2)
    root.left.right = BinaryTree(5)
    root.right.left = BinaryTree(13)
    root.right.right = BinaryTree(22)
    root.left.left.left = BinaryTree(1)
    root.right.left.right = BinaryTree(14)

    #Average : O(Log(n)) time | O(Log(n)) space
    #Worst: O(n) time | O(n) space
    print(closestValueInTree(root, 12, float("inf")))

    '''
    Iterative : Average : O(Log(n)) time | O(1) space
                Worst : O(n) time | O(1) space
    '''
    print(closestValueInItrTree(root, 12, float("inf")))
