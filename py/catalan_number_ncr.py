cat = [-1 for _ in range(1001)]
cat[0]=1
cat[1]=1

def biCoff(n,k):

    if k>n-k:
        k = n-k

    num =1
    for i in range(k):
        num = num * (n-i)
        num = num/(i+1)

    return num

def catalan(n):

    if cat[n] !=-1:
        return cat[n]

    #n,k
    num = biCoff(2*n, n)

    cat[n] = num/(n+1)
    return cat[n]

if __name__ == "__main__":

    n = int(raw_input())

    for _ in range(n):

        num = int(raw_input())
        print catalan(num)
