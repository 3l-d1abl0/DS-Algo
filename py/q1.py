T= int(raw_input())

for _ in range(T):
    N,M = map(int, raw_input().split(' '))
    #print N, M
    mat = [ [0 for i in range(26) ] for j in range(N) ]



    for i in range(N):
        alpha = raw_input()
        for ch in alpha:
            mat[i][ord(ch)-97]+=1

    #for i in range(N):
    #    print mat[i]

    nstr = raw_input()
    l = len(nstr)
    for i in range(l):
        if mat[i%N][ord(nstr[i])-97]>0:
            mat[i%N][ord(nstr[i])-97]-=1
        else:
            print "No"

    print "Yes"
    #for i in range(N):
    #    print mat[i]
