def heapify(arr,start,end):
    root= start
    while(root*2+1<end):
        child = root*2+1
        if(child+1<end and arr[child]<arr[child+1]):
            child+=1

        if(arr[root]<arr[child]):
            arr[root],arr[child] = arr[child], arr[root]
            root=child
        else:
            return

def build_heap(arr,N):

    for i in xrange((N-2)/2, -1,-1):
        heapify(arr,i,N)



def heapSort(arr):
    n = len(arr)

    #build Max heap
    build_heap(arr,n)

    #heapSort
    for i in xrange(n-1, -1, -1):
        arr[0],arr[i]= arr[i],arr[0]
        heapify(arr,0,i)

if __name__=="__main__":
    arr = [ 12, 11, 13, 5, 6, 7]
    heapSort(arr)
    print('Sorted Array !')
    for e in arr:
        print e,
