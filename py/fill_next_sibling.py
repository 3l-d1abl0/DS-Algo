from collections import deque

class Node:
    def __init__(self, key):
        self.right = None
        self.left = None
        self.val = key
        self.nextSibling = None
        

def fillNextSibling(root):
    
    if root is None:
        return
    
    q = deque()
    q.append(root)
    q.append(None)
    
    while q:
        
        tmp = q.popleft()
        
        if tmp is None:
            if q:
                q.append(None)
                
        else:
            tmp.nextSibling = q[0]
            
            if tmp.left is not None:
                q.append(tmp.left)
                
            if tmp.right is not None:
                q.append(tmp.right)
    
def printNextSibling(root):
    
    if root is None:
        return 
    
    print root.nextSibling.val
    
    printNextSibling(root.left)
    printNextSibling(root.right)
        
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

    fillNextSibling(root)
    
    printNextSibling(root)