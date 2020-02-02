N, Q = map(int,raw_input().split())
nums = map(int, raw_input().split())

dig = []
for n in nums:
        #dig.append( ( n % 9 == 0) ? 9 : (n%9) )
        dig.append(9 if (n%9 ==0) else n%9)

dig.sort()
sum = [0] * N
sum[0] = dig[0]

for x in range(1,N):
        sum[x]= dig[x] + sum[x-1]
#print dig
#print sum

for x in range(Q):
        T,R = map(int, raw_input().split())

        if T == 1:
                if R ==N:
                        print sum[N-1]
                else:
                        print sum[N-1] - sum[N-1-R]
        else:
                print sum[R-1]

