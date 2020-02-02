def merge(arr, l, m, r):

    #0..3 -> 4, 1..4 ->4
    l1= m-l+1
    a1 = [0]*(l1)
    for i in range(l1):
        a1[i] = arr[l+i]

    #(3+1)..8 -> 5
    l2=r-m
    a2 = [0]*l2
    for i in range(l2):
        a2[i] = arr[m+1+i]

    i=0 #index for 1st half
    j=0 #index for 2nd half
    k=l #index for main array

    while i<l1 and j<l2:

        if a1[i] <= a2[j]:
            arr[k]= a1[i]
            i+=1
        else:
            arr[k]=a2[j]
            j+=1

        k+=1

    while i<l1:
        arr[k] = a1[i]
        k+=1
        i+=1

    while j<l2:
        arr[k] = a2[j]
        k+=1
        j+=1


def merge_sort(arr, l, r):

    if l<r:
        mid = l+(r-l)/2
        merge_sort(arr,l,mid)
        merge_sort(arr,mid+1,r)
        merge(arr,l,mid,r)

if __name__ == '__main__':

    arr =[2,6,3,4,1,2,9,5,8]
    #passing the index
    merge_sort(arr,0, len(arr)-1)

    print arr
