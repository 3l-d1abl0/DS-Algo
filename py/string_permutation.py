def permute(arr, idx, len):

    if idx == n:
        print ''.join(arr)
    else:

        for i in xrange(idx, len+1):
            arr[idx], arr[i] = arr[i], arr[idx]
            permute(arr, i+1, len)
            arr[idx], arr[i] = arr[i], arr[idx]


if __name__ == "__main__":
    string ="AABC"
    n =len(string)
    arr = list(string)
    permute(arr, 0, n-1)
