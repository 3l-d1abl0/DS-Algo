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

    def DFS(self, visited, node):
        visited[node] = True
        print ("%s\t"%node)
        for vtx in self.graph[node]:
            if visited[vtx] == False:
                self.DFS(visited, vtx)



if __name__ == "__main__":

    g = Graph()
    # g.addEdge(0, 1)
    # g.addEdge(0, 2)
    # g.addEdge(1, 2)
    # g.addEdge(2, 0)
    # g.addEdge(2, 3)
    # g.addEdge(3, 3)

    g.addEdge(5,2);
    g.addEdge(5,0);
    g.addEdge(4,0);
    g.addEdge(4,1);
    g.addEdge(2,3);
    g.addEdge(3,1);

    print ("Following is Deapth First Traversal")


    V = g.graph.__len__()
    visited = [False] * V
    #print V
    for i in range(V):
        if visited[i] == False:
            g.DFS(visited, i)
