
T = int(raw_input())

def l2r(arr,ans, N):
    ans[0]= 1 if arr[0] is 0 else arr[0]

    curr = ans[0]

    for i in range(1,N):
        if arr[i]>arr[i-1]:
            ans[i] = curr+1
            curr+=1
        else:
            ans[i] = 1
            curr=1

def r2l(arr, ans, N):
    ans[N-1] = min(ans[N-1], 1 if arr[N-1] is 0 else arr[N-1])
    curr = ans[N-1]

    for i in range(N-2,0,-1):
        if arr[i]>arr[i+1]:
            ans[i] = max(ans[i],curr+1)
            curr=ans[i]
        else:
            ans[i]=max(ans[i],1)
            curr=ans[i]

    if arr[0] > arr[1]:
        ans[0]= ans[1]+1


for i in range(T):
    N = int(raw_input())
    arr = map(int, raw_input().split())

    if N==1:
        print 1
        continue

    ans = [-1]*N
    #print ans
    l2r(arr,ans, N)
    #print ans

    r2l(arr, ans, N)
    for i in range(N):
        print ans[i],
    print ''
