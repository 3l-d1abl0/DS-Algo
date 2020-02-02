#O(n) tine and O(n) space

def bito(arr):
    n = len(arr)

    inc = [0]*n
    dec = [0]*n

    inc[0]=1
    for i in range(1,n):
        if arr[i]>=arr[i-1]:
            inc[i] = inc[i-1]+1
        else:
            inc[i]=1

    dec[n-1]=1
    for i in range(n-2,-1,-1):
        if arr[i]>arr[i+1]:
            dec[i] = dec[i+1]+1
        else:
            dec[i]=1

    maxx = inc[0]+dec[0]-1
    for i in range(1,n):
        if maxx < inc[i]+dec[i]-1:
            maxx = inc[i]+dec[i]-1

    return maxx



if __name__ == "__main__":
    arr = [12, 4, 78, 90, 45, 23]
    #print len(arr)
    print ' Max len Bitonic subarray : {}'.format(bito(arr))
