
def knapsack(val, wt, W):
    n = len(wt)

    arr = [ [0 for _ in range(W+1)] for _ in range(n+1) ]

    for i in range(n+1):
        for j in range(W+1):

            if i == 0 or j ==0:
                arr[i][j] =0
            elif wt[i-1] > W:
                arr[i][j] = arr[i-1][j]
            else:
                arr[i][j] = max(arr[i-1][j], val[i-1]+arr[i-1][j-wt[i-1]])


    return arr[n][W]


if __name__ =="__main__":

    val = [60, 100, 120]
    wt = [10, 20, 30]
    W = 50

    print "Max value Obtained :: ", knapsack(val, wt, W)
