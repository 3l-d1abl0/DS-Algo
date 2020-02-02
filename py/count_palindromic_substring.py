dp = [[ 0 for i in range(5000)] for j in range(5000)]

def count_ways(str, idx, N, K):

    if K<=0:
        return -1

    if idx+1>=N:
        return -1

    total_count =0
    for start in xrange(idx+1,N):
        print '---'
        K= K-1
        val = count_ways(str, start, N, K)
        if val==-1:
            continue
        print 'val %d dp %d'%(val, dp[idx][start])
        total_count += (dp[idx][start] +val )%1000000007

    print 'tot %d'%(total_count)
    return total_count

def countPS(str, N, K):


    P = [ [False for i in range(N)] for j in range(N) ]

    for i in xrange(N):
        P[i][i]= True

    for i in xrange(N-1):
        if str[i] == str[i+1]:
            P[i][i+1] = True
            dp[i][i+1] =1

    for gap in xrange(2,N):

        for i in xrange(0,N-gap):

            j = gap+i

            if str[i]==str[j] and P[i+1][j-1]:
                P[i][j]= True

            if P[i][j] == True:
                dp[i][j] = dp[i][j-1]+dp[i+1][j]+1-dp[i+1][j-1]
            else:
                dp[i][j] = dp[i][j-1]+dp[i+1][j]-dp[i+1][j-1]

    total_val = count_ways(str, -1, N, K)
    print total_val
    return total_val

N,K = map(int, raw_input().split())
str = raw_input()

print countPS(str,N,K)
