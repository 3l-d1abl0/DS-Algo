import math
# Returns count of subsets of arr[] with
# XOR value equals to k.
def subsetXOR(arr, n, k):

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
    dp = [[0 for i in range(m + 1)]
             for i in range(n + 1)]

    # The xor of empty subset is 0
    dp[0][0] = 1

    # Fill the dp table
    for i in range(1, n + 1):
        for j in range(m + 1):
            dp[i][j] = (dp[i - 1][j] +
                        dp[i - 1][j ^ arr[i - 1]])

    # The answer is the number of subset
    # from set arr[0..n-1] having XOR of
    # elements as k
    return dp[n][k]

# Driver Code
arr = [1, 2, 3, 4, 5]
k = 4
n = len(arr)
print("Count of subsets is",
       subsetXOR(arr, n, k))
