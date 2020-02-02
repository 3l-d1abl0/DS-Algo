class Queue(object):
    """docstring for Queue."""
    def __init__(self):
        #super(Queue, self).__init__()
        self.q = []

    def empty(self):
        return self.q ==[]

    def enqueue(self, ele):
        self.q.append(ele)

    def dequeue(self):
        return self.q.pop(0)

    def printAll(self):
        print self.q[0]


def bfs(num, idx):

    q = Queue()
    q.enqueue(idx)
    #print '---'
    #q.printAll()

    while(not q.empty()):
        i = q.dequeue()

        if i<=num:

            print '-> {}'.format(i)
            last_dig = i%10

            if last_dig ==0:
                q.enqueue( (i*10)+(last_dig+1) )
            elif last_dig ==9:
                q.enqueue( (i*10)+(last_dig-1) )

            else:
                q.enqueue( (i*10) + (last_dig-1) )
                q.enqueue( (i*10) + (last_dig+1) )

            #print '=> {}'.format((i*10) + (last_dig-1))
            #print '=> {}'.format((i*10) + (last_dig+1))
            #q.printAll()



def jumpingNum(num):
    print '{}'.format(0)
    for i in range(1,10):
        bfs(num, i)

if __name__=="__main__":
    num = 105 #upto 30
    jumpingNum(num)
