from queue_stack import Stack

class Graph:

    def __init__(self, Nodes):
        self.node_num = Nodes
        self.graph = [ [] for _ in range(Nodes)]
        self.visited = [False for _ in range(Nodes)]

    def addEdge(self, i,j):
        self.graph[i].append(j)
        self.graph[j].append(i)

    def dfs(self, idx):
        st = Stack()
        #self.visited[idx] = True
        st.push(idx)
        while st.empty() is False:
            tmp = st.pop()
            #print 'node :',tmp
            #st.get_stack()
            if self.visited[tmp] is False:
                print tmp," ",
                self.visited[tmp] = True

            for node in self.graph[tmp]:
                if self.visited[node] is False:
                    st.push(node)


    def iterative_dfs(self):
        for idx in range(self.node_num):
            if self.visited[idx] is False:
                self.dfs(idx)


if __name__ == "__main__":

    g = Graph(5)
    g.addEdge(1, 0);
    g.addEdge(2, 1);
    g.addEdge(3, 4);
    #g.addEdge(4, 0);

    g.iterative_dfs()
