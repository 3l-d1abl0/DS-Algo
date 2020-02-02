cat = [-1 for _ in range(1001)]
cat[0]=1
cat[1]=1

def catalan(n):
    '''
    if n<=1:
        return 1

    print '{} = {}'.format(n, cat[n])
    '''

    if cat[n] !=-1:
        return cat[n]

    ans =0
    for i in range(n):
        #print '{}, {}'.format(i, n-i-1)
        ans += catalan(i)*catalan(n-i-1)

    cat[n] = ans
    return cat[n]

if __name__ == "__main__":

    n = int(raw_input())

    for _ in range(n):

        num = int(raw_input())
        print catalan(num)
