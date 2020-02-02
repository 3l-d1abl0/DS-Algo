# Python program to cnt number of ways to
# express N as sum of consecutive numbers.
 
def cntConsecutive(N):
     

    cnt = 0
    i = 1
    while( i * (i + 1) < 2 * N):
        a = (1.0 * N - (i * (i + 1) ) / 2) / (i + 1)
        if (a - int(a) == 0.0):
            cnt += 1
        i += 1
    return cnt
 
# Driver code
 
N = 15
print cntConsecutive(N)
N = 10
print cntConsecutive(N)