class Stack:

    def __init__(self):
        self.stack = []

    def empty(self):
        if self.stack.__len__() <1:
            return True
        else:
            return False

    def pop(self):
        if len(self.stack) < 1:
            return None
        return self.stack.pop()

    def push(self, item):
        self.stack.append(item)

    def size(self):
        return len(self.stack)

    def get_stack(self):
        print "Stack Data: \n %s "%(self.stack)

    def top(self):
        if len(self.stack) > 0:
            return self.stack[-1]
        else:
            return None

    def __len__(self):
        return len(self.stack)

    def __str__(self):
        return ' '.join(map(str, self.stack)) 

# And a queue that only has enqueue and dequeue operations
class Queue:

    def __init__(self):
        self.queue = []

    def empty(self):
        if self.queue.__len__() < 1:
            return True
        else:
            return False

    def push(self, item):
    #def enqueue(self, item):
        self.queue.append(item)

    def pop(self):
    #def dequeue(self):
        if len(self.queue) < 1:
            return None
        return self.queue.pop(0)

    def size(self):
        return len(self.queue)

    def get_queue(self):
        print "Queue Data: \n %s"%(self.queue)

    def get_front(self):
        if len(self.queue)>0:
            return self.queue[0]
        else:
            return None

    def get_back(self):
        if len(self.queue)>0:
            return self.queue[-1]
        else:
            return None
