def heapify(arr, start, end):

    root = start
    child = (2*root)+1
    while(child<=end):

        #pick the largest child
        if child+1<=end and arr[child]<arr[child+1]:
            child+=1

        #maxheap so max element should be on top
        #print "root= {} child= {}".format(arr[root], arr[child])
        if arr[root]<arr[child]:
            arr[root],arr[child] = arr[child],arr[root]
            root=child
            child = (2*root)+1
        else:
            return

def build_heap(arr, N):

    for start in range((N-2)/2,-1,-1):
        heapify(arr, start, N-1)

def heapsort(arr, N):

    for end in range(N-1, 0, -1):
        arr[end],arr[0] = arr[0],arr[end]
        heapify(arr, 0, end-1)

if __name__ == '__main__':

    arr =[2,6,3,4,1,2,9,5,8]
    #arr =[12, 3, 5, 7, 4, 19, 26]

    #creating Maxheap
    build_heap(arr, len(arr))
    heapsort(arr, len(arr))
    print arr
