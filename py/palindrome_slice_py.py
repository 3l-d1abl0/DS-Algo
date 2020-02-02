
def countPalin(str, start_index, N, K, dp):
    #print 'idx={} K = {}'.format(start_index+1, K)

    if K<0:
        return -1

    if start_index+1>=N:
        return -1

    cnt =0
    K=K-1
    for start in xrange(start_index+1,N):
        val = countPalin(str, start, N, K, dp)
        if val==-1:
            val=0

        #print 'val {} dp {} '.format(val, dp[start_index][start])
        cnt += (dp[start_index][start] +val )%1000000007

    #print 'cnt {}'.format(cnt)
    return cnt

def calculateDP(str, N, K):

    dp = [[ 0 for i in range(N)] for j in range(N)]
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
    #print dp
    total_val = countPalin(str, -1, N, K, dp)
    #print 'total_val = {}'.format(total_val)
    return total_val


if __name__=="__main__":
    str_len,K = map(int, raw_input().split())
    str = raw_input()

    print calculateDP(str,str_len,K+1)
