T= int(raw_input())
for i in range(T):
    N= int(raw_input())
    M = map(int, raw_input().split())
    M.sort()
    
    sm =M[0];
    #msum =[0]*N-1
    msum =[]
    for j in range(1,N):
        msum.append(0)
        sm += M[j]
        msum[j-1] = sm
        
    print sum(msum)