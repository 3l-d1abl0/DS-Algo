
def interleave(A, B, C):

    alen = len(A)
    blen = len(B)
    clen = len(C)

    if alen+blen is not clen:
        return False

    dp = [ [False] * (blen+1)  for _ in range(alen+1)]


    for i in range(0, alen+1):
        for j in range(0, blen+1):

            if i==0 and j==0:
                dp[i][j] = True

            #when A is empty string
            if i==0:
                if B[j-1] == C[i+j-1]:
                    dp[i][j]= dp[i][j-1]

            elif j==0: #When B string is empty
                if A[i-1] == C[i+j-1]:
                    dp[i][j] = dp[i-1][j]

            elif A[i-1] == C[i+j-1] and B[j-1] != C[i+j-1]:
                dp[i][j] = dp[i-1][j]

            elif B[j-1] == C[i+j-1] and A[i-1] != C[i+j-1]:
                dp[i][j] = dp[i][j-1]

            elif A[i-1] == C[i+j-1] and B[j-1] == C[i+j-1]:
                dp[i][j] = dp[i][j-1] or dp[i-1][j]


    return dp[alen][blen]




if __name__ == '__main__':
    print (interleave("XXY", "XXZ", "XXZXXXY"))
    print (interleave("XY", "WZ", "WZXY"))
    print (interleave("YX", "X", "XXY"))
    print(interleave("XY", "X", "XXY"))
    print (interleave("XXY", "XXZ", "XXXXZY"))


    #https://ideone.com/4jnFZu
