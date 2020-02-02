def lcs_rec(x, i, m, y, j, n):

    if i == m or j==n:
        return 0

    if x[i]==y[j]:
        return lcs_rec(x,i+1,m, y, j+1, n)+1
    else:
        return max(lcs_rec(x, i+1, m, y, j, n), lcs_rec(x, i, m, y, j+1, n))


def lcs_dp(x, n, y, m):

    nn = n
    mm = m

    dp = [ [0 for i in range(m+1)] for j in range(n+1) ]

    for i in range(0, n+1):
        for j in range(m+1):

            if i==0 or j==0:
                dp[i][j]=0

            elif x[i-1]==y[j-1]:
                dp[i][j]= dp[i-1][j-1] +1
            else:
                dp[i][j] = max(dp[i-1][j], dp[i][j-1])


    lcs_len = dp[n][m]
    lcs_str = ['' for i in range(lcs_len)]
    lcs_len = lcs_len -1
    while (n>=0 and m>=0 and lcs_len>=0):

        if x[n-1] == y[m-1]:
            lcs_str[lcs_len]= x[n-1]
            n -=1
            m -=1
            lcs_len -=1

        elif dp[n-1][m] > dp[n][m-1]:
            n -=1

        else:
            m -=1

    print lcs_str


    return dp[nn][mm]


def lcs_opti(x, n, y, m):

    dp = [ [0 for i in range(m+1)] for j in range(2) ]

    idx = bool

    for i in range(0, n+1):
        idx = i & 1
        #print 'idx : ', idx
        for j in range(0, m+1):

            if i==0 or j==0:
                dp[idx][j]=0

            if x[i-1]==y[j-1]:
                dp[idx][j]= dp[1-idx][j-1]+1

            else:
                dp[idx][j]= max(dp[1-idx][j], dp[idx][j-1])

            #print dp

    return dp[idx][m]

if __name__=="__main__":

    #x = "AGGTAB" #"ABCDGH"
    x = "abcba"
    x_len = len(x)
    #y = "GXTXAYB" #"AEDFHR"
    y = "acab"
    y_len = len(y)

    #print 'LCS :: {}'.format(lcs_rec(x, 0, x_len, y, 0, y_len))


    #print 'LCS_DP :: {} '.format(lcs_dp(x, x_len, y, y_len))

    print 'LCS_OPTI :: {} '.format(lcs_opti(x, x_len, y, y_len))
