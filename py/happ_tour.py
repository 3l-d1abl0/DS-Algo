'''
# Sample code to perform I/O:

name = raw_input()          # Reading input from STDIN
print 'Hi, %s.' % name      # Writing output to STDOUT

# Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
'''

# Write your code here
totalH=0
maxHap =0

def dfs(node, totalH):
    #global totalH
    global maxHap
    #print 'dfs : ',node
    vis[node-1] =1
    if ar[node-1] <0:
        totalH =max(0,totalH+ar[node-1])
    else:
        totalH = totalH+ar[node-1]

    maxHap = max(maxHap,totalH)
    nextNode =0
    maxVal = -10000000002
    for i in graph[node]:

        if vis[i-1] ==0:
            dfs(i, totalH)

    #print 'maxVal: ',maxVal, nextNode

    #if maxVal>0:
        #totalH = totalH+ar[nextNode-1]
        #vis[nextNode-1]=1
    #if nextNode!=0:
        #dfs(nextNode)
    #else:
        #vis[nextNode-1]



T = int(raw_input())

for i in range(T):
    n = int(raw_input())
    vis = [0]*n
    ar = map(int, raw_input().split())
    ed = int(raw_input())
    #graph = defaultdict(list)
    graph = [ set() for i in range(n+1)]
    u = map(int, raw_input().split())
    v = map(int, raw_input().split())

    for j in range(ed):
        graph[u[j]].add(v[j])
        graph[v[j]].add(u[j])
        #print graph
    global totalH
    #totalH=0
    global maxHap
    maxHap=0
    dfs(1,0)
    '''
    ans =0
    for j in range(1,ed+1):
        dfs(j)
        ans = max(ans,totalH)
        totalH=0
        '''

    #print 'ANS : ',ans
    #print totalH
    print maxHap
'''
2
3
-1 1 2
2
1 1
2 3
8
-1 -3 4 2 1 5 -3 -3
7
1 1 2 3 3 5 6
2 3 4 5 6 7 8
'''
