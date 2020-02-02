from queue_stack import Stack

class Graph(object):
    """class for Graph."""
    def __init__(self, nov):
        self.adj = {}
        self.V = nov

    def addEdge(self, u, v):
        """ Directed Graph u -> v"""
        if u in self.adj:
            self.adj[u].append(v)
        else:
            self.adj[u] = [v]

    def printGraph(self):

        for u in self.adj:
            print "%s ::"%u,
            for v in self.adj[u]:
                print "-> %s"%v,
            print "\n"

    def topoSort(self):

        st = Stack()
        visited = [False] * self.V

        for node in self.adj:
            if visited[node] == False:
                self.DFS(node, visited, st)

        while st.empty()== False:
            print "%s "%st.pop(),

    def DFS(self, node, visited, st):

        visited[node] = True
        if node in self.adj:
            for vtx in self.adj[node]:
                if visited[vtx] == False:
                    self.DFS(vtx, visited, st)

        st.push(node)


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
