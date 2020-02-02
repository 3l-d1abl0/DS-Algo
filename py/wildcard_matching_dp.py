def testing(str,patt):

    n = len(str)
    m = len(patt)

    if n==0:
        return (m==0)

    dp = [[False for i in range(m+1)] for j in range(n+1) ]

    #empty string and empty pattern
    dp[0][0]= True

    print '-------------'
    for i in range(1,n+1):
        for j in range(1,m+1):

            if patt[j-1] == '?' or str[i-1]==patt[j-1]:
                dp[i][j]= dp[i-1][j-1]

            elif patt[j-1]== '*':
                dp[i][j] = dp[i-1][j] or dp[i][j-1]

            else:
                dp[i][j] = False

    for i in range(n+1):
        for j in range(m+1):
            print dp[i][j],
        print ''
    return dp[n][m]

def test(str, patt):

    if testing(str, patt):
        print 'YES'
    else:
        print 'NO'


if __name__ == '__main__':
    #main()

    test("baabab","*****ba*****ab")
    test("baabab","?baaabab")
    test("baabab","*a*****ab")
