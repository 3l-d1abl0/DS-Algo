from queue_stack import Queue
from queue_stack import Stack

from time import sleep

import random


def use_stack():

    st = Stack()

    for _ in range(10):
        st.push(random.randint(0, 50))

    st.get_stack()

    st.pop()

    print st.top()

    st.push(67)

    st.get_stack()

def use_queue():

    qq = Queue()

    for _  in range(20):
        qq.push(random.randint(0, 50))

    qq.get_queue()

    qq.pop()

    print qq.get_front()
    print qq.get_back()

    qq.get_queue()

if __name__ == '__main__':
    #use_stack()

    sleep(0.5)

    use_queue()
