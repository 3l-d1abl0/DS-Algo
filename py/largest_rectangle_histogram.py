from queue_stack import Stack

def get_rectangle(hist, sz):

    max_area =0
    idx =0

    st = Stack()

    while idx < sz:

        if st.top() is None or hist[idx] >= hist[st.top()]:
            st.push(idx)
            idx+=1
        else:
            top_ele = st.pop()
            current_area = hist[top_ele] * (idx if st.top() is None else (idx-st.top()-1) )
            #print "current_area  %s %s"%(hist[top_ele], current_area)
            max_area = max(max_area, current_area)

    #print "max= %s"%(max_area)
    while st.top() is not None:

        top_ele = st.pop()
        current_area = hist[top_ele]* (idx if st.top() is None else (idx-st.top()-1))
        max_area = max(max_area, current_area)


    print "Max rectangele = %s"%(max_area)

if __name__ == "__main__":


    hist = [6, 2, 5, 4, 5, 1, 6]
    sz = hist.__len__()

    get_rectangle(hist, sz)
