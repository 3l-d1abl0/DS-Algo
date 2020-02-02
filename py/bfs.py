from queue_stack import Queue

class Graph:

    def __init__(self):

        self.graph = {}

    def addEdge(self, a, b):
        if a in self.graph:
            self.graph[a].append(b)
        else:
            self.graph[a]=[b]

        if b in self.graph:
            self.graph[b].append(a)
        else:
            self.graph[b]=[a]

    def BFS(self, node):

        visited = [False] * (self.graph.__len__())

        q = Queue()

        q.push(node)
        visited[node] = True
        #print q.get_queue()
        while q.get_front() is not None:

            tmp = q.pop()
            #print q.get_queue()
            print "%s\t"%(tmp)

            for vtx in self.graph[tmp]:
                if visited[vtx] is False:
                    q.push(vtx)
                    visited[vtx] = True

if __name__ == "__main__":

    g = Graph()
    g.addEdge(0, 1)
    g.addEdge(0, 2)
    g.addEdge(1, 2)
    g.addEdge(2, 0)
    g.addEdge(2, 3)
    g.addEdge(3, 3)

    print ("Following is Breadth First Traversal"
                  " (starting from vertex 2)")
    g.BFS(2)
