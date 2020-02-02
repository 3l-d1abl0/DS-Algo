def permute(a, l, n):

    if l == n:
        print a
    else:
        for i in xrange(l,n+1):
            a[l], a[i] = a[i], a[l]
            permute(a, l+1, n)
            a[i], a[l] = a[l], a[i]


if __name__ == '__main__':
    string = "ABCD"
    n = len(string)
    a = list(string)

    permute(a, 0,n-1)
