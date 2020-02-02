def catDp(n):
    if n is 0 or n is 1:
        return 1
    cat = [0 for i in range(n+1)]
    cat[0] = 1
    cat[1] = 1

    for i in range(2,n+1):
        cat[i] = 0
        for j in range(i):
            cat[i] += cat[j] * cat[i-j-1]

    return cat[n]

if __name__ == "__main__":

    '''
    cat = [-1 for i in range(1001)]

    cat[0] = cat [1] = 1
    for i in range(2,1001):
        cat[i] = cat[i]*cat[]
    '''

    n = int(raw_input())

    for _ in range(n):

        num = int(raw_input())
        print catDp(num)
