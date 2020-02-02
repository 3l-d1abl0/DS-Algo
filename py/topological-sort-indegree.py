from queue_stack import Queue

class Graph(object):

    def __init__(self, nov):
        self.adj = {}
        self.V = nov
        self.in_degree = [0] * self.V

    def addEdge(self, u, v):
        #Directed edges
        if u in self.adj:
            self.adj[u].append(v)
        else:
            self.adj[u] = [v]
        self.in_degree[v] +=1

    def printGraph(self):
        for node in self.adj:
            print "%s : "%node,
            for idx in self.adj[node]:
                print "-> %s "%idx,
            print "\n"

        print "Indegree :"
        for i in range(self.in_degree.__len__()):
            print "%s :: %s "%(i, self.in_degree[i])
        print "\n"

    def topoSort(self):
        q = Queue()
        #get the vertices with 0 indegree
        for idx, val in enumerate(self.in_degree):
            if val == 0:
                q.push(idx)

        while q.empty() == False:

            vtx = q.pop()
            print "%s "%vtx,
            if vtx in self.adj:
                for node in self.adj[vtx]:
                    self.in_degree[node] -=1
                    if self.in_degree[node] ==0:
                        q.push(node)


if __name__ == "__main__":
    g = Graph(6)

    g.addEdge(5,2)
    g.addEdge(5,0)
    g.addEdge(4,0)
    g.addEdge(4,1)
    g.addEdge(2,3)
    g.addEdge(3,1)

    g.printGraph()

    g.topoSort()
