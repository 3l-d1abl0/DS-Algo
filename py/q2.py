INF = 10**9
N,M,K,X = map(int, raw_input().split(' '))
mat = [ [-1 for i in range(N) ] for j in range(N) ]
chocCities = map(int, raw_input().split(' '))   #k chocCities

for _ in range(M):
    u,v,d = map(int, raw_input().split(' '))
    mat[u-1][v-1]=d
    mat[v-1][u-1]=d

for k in range(N):
    for i in range(N):
        for j in range(N):
            if mat[i][k] is -1 or mat[k][j] is -1:
                continue
            mat[i][j] = min( mat[i][j], mat[i][k]+mat[k][j] )
            mat[j][i] = mat[i][j]

A,B = map(int, raw_input().split(' '))
Flag = 10**9
for k in chocCities:
    if mat[A][k-1] is -1 or mat[B][k-1] is -1:
        continue
    else:
        if mat[A][k-1]+mat[B][k-1] <=X:
            Flag = min(Flag, mat[A][k-1]+mat[B][k-1])

if Flag == 10**9:
    print "-1"
else:
    print Flag


for i in range(N):
    print mat[i]
