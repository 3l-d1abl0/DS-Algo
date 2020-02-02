def maxProfit(arr,N,C):

    max_profit_far = 0
    max_profit_here = 0

    for i in range(0, N):
        max_profit_here = max_profit_here + (C-arr[i])
        if max_profit_here < 0:
            max_profit_here = 0
        elif (max_profit_far < max_profit_here):
            max_profit_far = max_profit_here

    return max_profit_far


if __name__ == '__main__':

    T= int(raw_input())

    for _ in range(T):
        N,C = map(int, raw_input().split(' '))
        arr = map(int, raw_input().split(' '))
        #print N,C
        #print arr
        print maxProfit(arr,N,C)
