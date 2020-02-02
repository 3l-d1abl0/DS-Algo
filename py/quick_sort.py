import random

'''
def partition(arr, l, r):

    pivot = random.randint(l,r)
    arr[l], arr[pivot] = arr[pivot], arr[l]

    pivot = l
    pivotVal = arr[pivot]
    #print "l= {} r= {} pivot= {}".format(l, r, pivotVal)
    #print (arr[l:r+1])

    left=l
    right=r

    while(left < right):

        while left<=r and arr[left]<=pivotVal:
            left+=1

        while right>=l and arr[right]>pivotVal:
            right-=1
            
        if left<right:
            arr[left],arr[right] = arr[right],arr[left]

    arr[pivot],arr[right] = arr[right],arr[pivot]
    #print (arr[l:r+1])
    return right
'''



def partition(arr, l, r):

    pivot = random.randint(l,r)
    #print(pivot)
    #print "l= {} r= {} pivot= {}".format(l, r, arr[pivot])

    pivotVal = arr[pivot]
    arr[r], arr[pivot] = arr[pivot], arr[r]
    idx =l

    #print (arr[l:r+1])

    for i in range(l, r):

        if arr[i]<=pivotVal:
            arr[idx],arr[i] = arr[i],arr[idx]
            idx+=1

    #swap the pivot place
    arr[idx], arr[r] = arr[r],arr[idx]
    #print (arr[l:r+1])
    return idx


def quickSort(arr, l, r):
    if l<r:
        part = partition(arr, l, r)
        quickSort(arr, l, part-1)
        quickSort(arr, part+1, r)

if __name__ == '__main__':

    #arr =[2,6,3,4,1,2,9,5,8]
    arr =[12, 3, 5, 7, 4, 19, 26]

    quickSort(arr, 0, len(arr)-1)
    print(arr)
