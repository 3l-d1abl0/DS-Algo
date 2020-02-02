#O(n) time and O(1) Space

def bito(arr):
    n = len(arr)

    maxx =1
    j =0
    start = 0
    nxtStrt =0
    while j<n-1:

        #search ascent
        while(j<n-1 and arr[j]<=arr[j+1]):
            j+=1

        #search descent
        while (j<n-1 and arr[j]>=arr[j+1]):

            if arr[j]>arr[j+1]:
                nxtStrt = j+1
            j+=1

        maxx = max(maxx, j-start+1)
        start = nxtStrt

    return maxx


if __name__ == '__main__':
    arr = [12, 4, 78, 90, 45, 23]
    #print len(arr)
    print ' Max len Bitonic subarray : {}'.format(bito(arr))
