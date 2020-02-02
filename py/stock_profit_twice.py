def maxProfit(price, n):
    profit = [0]*n

    max_price = price[n-1]
    for i in range(n-2, 0, -1):
        max_price = max_price if max_price>price[i] else price[i]

        profit[i] = max(profit[i+1], max_price-price[i])

    min_price= price[0]
    for i in range(1, n):
        min_price = min_price if min_price<price[i] else price[i]

        profit[i] = max(profit[i-1], profit[i]+price[i]-min_price)

    return profit[n-1]

if __name__ == '__main__':
    price = [2, 30, 15, 10, 8, 25, 80]
    print "Max profit : ", maxProfit(price, len(price))
