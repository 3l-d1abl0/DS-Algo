if __name__ == '__main__':

    N,Q = map(int, raw_input().split(' '))

    A = raw_input()
    B = raw_input()

    Aa = int(A, 2)
    Bb = int(B, 2)

    for _ in range(Q):

        idx = int(raw_input())
        if B[idx-1]=='0':
            B[idx-1]='1'
            Bb = Bb + 2**(N-idx)

        if Bb >= Aa :
            print 'YES'
        else:
            print 'NO'
