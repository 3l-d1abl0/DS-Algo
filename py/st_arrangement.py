N,M,K = map( int,raw_input().split() )
stl = map( int, raw_input().split() )
row = [0 for x in range(M+1)]

def findNext(i,N,K):

    for x in range(i, M+1):
        if row[i]<K:
            row[i]+=1
            done = true
            return

    for x in range(0, i):
        if(row[i]<K):
            row[i]+=1
            return


no_seat =0;
for i in stl:
    if row[i]>=K:
        no_seat+=1
        findNext(i,M,K)
    else:
        row[i]+=1

print no_seat
