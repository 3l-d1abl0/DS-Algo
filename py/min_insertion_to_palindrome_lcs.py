def LCS(length, str, str_len ):

    t = [[0 for i in range(length+1)]  for j in range(length+1)]

    for i in range(length+1):
        for j in range(length+1):

            if i ==0 or j == 0:
                t[i][j] = 0
            elif str[i-1] == str_len[j-1]:
                t[i][j] = t[i-1][j-1]+1
            else:
                t[i][j] = max(t[i-1][j], t[i][j-1])

    #print t
    return t[length][length]


if __name__=="__main__":
    #str = "abcda"
    str = "aabba"
    n = len(str)
    str_rev = str[::-1]
    print '{}'.format(n-LCS(n, str, str_rev))
