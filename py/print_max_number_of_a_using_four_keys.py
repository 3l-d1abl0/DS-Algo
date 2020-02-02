

def ways(N):

    dp = [0]*(N+1)

    for i in range(1,7):
        dp[i]= i

    for n in range(7, N+1):

        dp[n]=0

        for i in range(n-3,0,-1):
            dp[n] = max(dp[n],(n-i-1)*dp[i])

    return dp[N]

if __name__ == '__main__':

    N = 15

    print('No. of  \'A\' :: {}'.format(ways(N)))
