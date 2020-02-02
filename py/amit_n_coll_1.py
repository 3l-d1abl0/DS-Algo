
def detect_cycle(graph, N):
    visiting = set()
    visited = set()

    for i in xrange(1,N+1):
        if  dfs(i, graph,visiting, visited) == True:
            return True

    return False

def dfs(current, graph, visiting, visited):
        visiting.add(current)
        for nei in graph[current]:

            #print "visiting : {}".format(visiting)
            #print "visited : {}".format(visited)

            if nei in visited:
                continue

            if nei in visiting:
                return True

            if dfs(nei, graph, visiting, visited) == True:
                return True

        move_node(current, visiting, visited)
        return False

def move_node(i, src, dest):
    src.remove(i)
    dest.add(i)

if __name__ == "__main__":

    t = int(raw_input())
    for i in xrange(t):
        N,M = map(int, raw_input().split())
        #graph = {}
        graph =[[] for _ in xrange(0,N+1)]

        #print graph

        for j in xrange(M):
            x,y = map(int, raw_input().split())
            graph[x].append(y)

        #for j in xrange(1,N+1):
            #print graph[j]
        if detect_cycle(graph,N):
            print "0"
        else:
            print "1"
