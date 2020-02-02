# Node class
class Node:

    # Constructor to initialize the node object
    def __init__(self, data):
        self.data = data
        self.next = None


class LinkedList:

    # Function to initialize head
    def __init__(self):
        self.head = None

    # Function to insert a new node at the beginning
    def push(self, new_data):
        new_node = Node(new_data)
        new_node.next = self.head
        self.head = new_node

    def detectAndRemoveLoop(self):
        if self.head is None or self.head.next is None:
            return

        slow = self.head
        fast = self.head

        while (fast is not None and fast.next is not None):

            slow = slow.next
            fast = fast.next.next

            if fast == slow:
                break

        if slow == fast:

            slow = self.head
            while slow.next is not fast.next:
                slow = slow.next
                fast = fast.next
            #Remove Loop
            fast.next = None

    def printList(self):
        temp = self.head
        while(temp):
            print temp.data,
            temp = temp.next

if __name__ == '__main__':
    # Driver program
    llist = LinkedList()
    llist.head = Node(50)
    llist.head.next = Node(20)
    llist.head.next.next = Node(15)
    llist.head.next.next.next = Node(4)
    llist.head.next.next.next.next = Node(10)

    #Create a loop for testing
    llist.head.next.next.next.next.next =  llist.head.next.next

    llist.detectAndRemoveLoop()

    print "Linked List after removing looop"
    llist.printList()
