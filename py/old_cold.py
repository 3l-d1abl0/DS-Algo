T = raw_input()
T=int(T)
for i in range(T):
    n = int(raw_input())
    arr = map(int, raw_input().split())
    o = [0]*int(n+1); c = [0]*int(n+1)
    for j in range(n):
        if arr[j]%2==0:
            o[j+1] = o[j]+1; c[j+1] = c[j]
        else:
            if arr[j]==1:
                o[j+1] = o[j]+1; c[j+1] = c[j]
            else:
                c[j+1] = c[j]+1; o[j+1] = o[j]

    q = int(raw_input())
    for qq in range(q):
        l,r = map(int, raw_input().split())

        if o[r]-o[l-1] >= c[r]-c[l-1]:
            print "0"
        else:
            sum = (o[r]-o[l-1]) + (c[r]-c[l-1])
            print (c[r]-c[l-1])- int(sum/2)
