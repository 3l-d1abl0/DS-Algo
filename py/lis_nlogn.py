def bi_search(arr,num):
    ft = 0
    lt = len(arr)-1
    while(ft+1<lt):
        #print ft,lt,"x"
        mid = (ft+lt)/2
        if num < arr[mid]:
            lt = mid
        elif num > arr[mid]:
            ft = mid
        else:
            return mid
    return lt


def lis(num):
    lt = len(num)
    used = [num[0]]
    for i in num[1:]:
        if used[0] >= i:
            used[0] = i;
        elif used[-1] < i:
            used.append(i)
            #print i,
            #print "Z"
        else:
            j = bi_search(used,i)
            #print i,
            #print "-"
            used[j] = i
    return len(used)

print lis([input() for i in xrange(input())])
