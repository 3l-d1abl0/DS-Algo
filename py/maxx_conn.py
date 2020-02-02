def dfs(v):
    global mark,c_c
    q=[]
    q.append(v)
    s=0
    while q:
        top=q.pop()
        mark[top]=c_c
        for j in G[top]:
            if mark[j]==-1:
                q.append(j)
                s+=1
                mark[j]=mark[top]



n,m,x=map(int,raw_input().split())
sc=map(int,raw_input().split())
sci=[-1]*(n+1)
ans=[0]*(n+1)

for i in xrange(m):

    sci[sc[i]]=1
    #ans[sc[i]]=1
G=[[] for i in xrange(n+1)]
for k in xrange(x):
        x,y=map(int,raw_input().split())
        G[x].append(y)
        G[y].append(x)

mark=[-1]*(n+1)
d={}#dictinary containg component_ids and their size.
c_c=1
for v in xrange(1,n+1):

            if mark[v]==-1:
             dfs(v)
             c_c+=1
#print mark
for i in xrange(1,n+1):
    if sci[i]==1:

        if mark[i] in d:
            d[mark[i]]+=1
        else:
            d[mark[i]]=1
#print d
for i in xrange(1,n+1):
    if mark[i] in d:
      ans[i]+=d[mark[i]]

print sum(ans)
