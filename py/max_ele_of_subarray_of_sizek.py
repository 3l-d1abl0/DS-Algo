from collections import deque

def printMaxOfK(arr, n, k):

    dq = deque()

    for i in xrange(k):
        while dq and arr[i]>=arr[dq[-1]]:#<= for smaller
            dq.pop()

        dq.append(i)

    for i in xrange(k,n):

        print '{}'.format(arr[dq[0]])
        #evict out of range elements

        while dq and dq[0] <= i-k:
            dq.popleft()

        while dq and arr[i]>=arr[dq[-1]]:
            dq.pop()

        dq.append(i)

    print '{}'.format(arr[dq[0]])

if __name__ == '__main__':
    arr = [12, 1, 78, 90, 57, 89, 56]
    k = 3
    printMaxOfK(arr, len(arr), k)
