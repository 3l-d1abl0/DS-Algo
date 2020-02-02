import math

def fun (arr, n, k):
   # Your code goes here
       # Find maximum element in arr[]
    max_ele = arr[0]
    for i in range(1, n):
        if arr[i] > max_ele :
            max_ele = arr[i]

    # Maximum possible XOR value
    m = (1 << (int)(math.log2(max_ele) + 1)) - 1

    # The value of dp[i][j] is the number
    # of subsets having XOR of their elements
    # as j from the set arr[0...i-1]

    # Initializing all the values
    # of dp[i][j] as 0
    #dp = [[0 for i in range(m + 1)]
    #         for i in range(n + 1)]
    dp = [0 for i in range(m+1)]


    # The xor of empty subset is 0
    #dp[0][0] = 1
    dp[0]

    # Fill the dp table
    for i in range(1, n + 1):
        for j in range(i,m + 1):
            #dp[i][j] = (dp[i - 1][j] + dp[i - 1][j ^ arr[i - 1]])
            dp[j] = dp[j]+dp[j ^ arr[i - 1]]

    # The answer is the number of subset
    # from set arr[0..n-1] having XOR of
    # elements as k

    #for i in range(k):
    	#print("{}. {}".format(i, dp[n][i]))
    	#print (i, dp[n][i])
    	#print "{} {}".format(i,dp[n][i])

    return dp

T = int(input())
for _ in range(T):
   N = int(input())
   K = int(input())
   A = input().split(' ')
   A = [ int(x) for x in A ]

   #print (A)

   row = fun(A, N, K)
   cnt2= row[K]
   cnt1 = 0
   for i in range(K):
       cnt1 += row[i]

   #print (out_)

   cnt3 = 2**N -(cnt2+cnt1)

   #print ("{} {} {}".format(cnt1, cnt2, cnt3))


   print ("{}".format( (cnt1+cnt2)**2 + (cnt2+cnt3)**2 + (cnt3+cnt1)**2 - (cnt1**2 +cnt2**2 + cnt3**2) ) )

   #https://www.geeksforgeeks.org/count-number-of-subsets-having-a-particular-xor-value/
   #https://codeforces.com/blog/entry/10229
