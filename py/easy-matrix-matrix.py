def solve (A):
    # Write your code here

n, m = input().split(' ')
n = int(n)
m = int(m)

A = []
for _ in range(n):
    A.append(input().split(' '))

dp = [ ['' for i in range(m + 1)] for i in range(n + 1) ]

dp[0][0] = A[0][0]

for i in range(1,m):
    dp[0][i] = dp[0][i]+A[0][i-1]

for i in range(1,n):
    dp[i][0] = dp[i][0]+A[i-1][0]

for i in range(1,n):
    for j in range(1,m):
        dp[i][j] = (dp[i-1][j]+A[i][j] < dp[i][j-1]+A[i][j])? dp[i-1][j]+A[i][j]:dp[i][j-1]+A[i][j]

out_ = solve(A)
print (out_)


#0 1 2 3 4 5 6 7 
