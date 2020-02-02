class Stack:
     def __init__(self):
         self.items = []
         self.minEle = 0

     def isEmpty(self):
         return self.items == []

     def push(self, item):

         if len(self.items) ==0:
             self.items.append(item)
             self.minEle = item
             print 'First Element'
             return

         if item<self.minEle:
            self.items.append(2*item-self.minEle)
            self.minEle = item
         else:
            self.items.append(item)
         print 'Inserted !'

     def pop(self):

         if len(self.items) ==0:
             print 'Stack Empty !'
             return
         if self.items[len(self.items)-1] > self.minEle:
             print 'Popped : {}'.format(self.items.pop())
             return
         else:
            print 'Popped : {} '.format(self.minEle)
            self.minEle = 2*self.minEle - self.items.pop()


     def peek(self):

         if self.items[len(self.items)-1]< self.minEle:
             print 'Top Ele : {}'.format(self.minEle)
         else:
             print 'Top Ele : {}'.format(self.items[len(self.items)-1])

     def getMin(self):
         print 'Min Element = {}'.format(self.minEle)
         return


     def size(self):
         return len(self.items)




if __name__ == '__main__':

    st = Stack()

    st.push(3)
    st.push(5)
    st.getMin()
    st.push(2)
    st.push(1)
    st.getMin()
    st.pop()
    st.getMin()
    st.pop()
    st.peek()
