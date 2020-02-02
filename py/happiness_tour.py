max_count=0

def traverse(n, happy_count):
    
    visited[n] = True
    #print 'visited : ',n
    #print visited
    if arr[n-1]<0:
        happy_count = max(0, happy_count+arr[n-1])
    else:
        happy_count = happy_count+arr[n-1]
    
    global max_count
    max_count = max(max_count, happy_count)
    
    for i in gr[n]:
        #print i," :: ",gr[n][i]," ",visited[i]
        if visited[i]==False:
            traverse(i, happy_count)
    

if __name__=="__main__":
    
    T = int(raw_input())
    
    for _ in range(T):
        N = int(raw_input())
        
        gr = [ set() for i in range(N+1)]
        visited = [False for i in range(N+1)]
        
        arr = map(int, raw_input().split())
        M = int(raw_input())
        
        
        u = map(int, raw_input().split())
        v = map(int, raw_input().split())
        
        for i in range(M):
            gr[u[i]].add(v[i])
            gr[v[i]].add(u[i])
        
        #print gr
        global max_count
        max_count =0
        happy_count =0
        traverse(1, happy_count)
        
        print max_count