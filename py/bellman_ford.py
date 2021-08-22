import sys

class Graph(object):
    """Graph"""

    def __init__(self, noe, nov, edges, weights):
        self.number_of_edges = noe
        self.number_of_nodes = nov
        self.edges = edges
        self.weights = weights
        self.edgeWeight = list()
        self.distance = [sys.maxsize] * (self.number_of_nodes+1)

        self.prepareEdges()

    def prepareEdges(self):

        for i in range(self.number_of_edges):
            self.edgeWeight.append([edges[i][0], edges[i][1], weights[i]])

    def bellmanFord(self, node):

        self.distance[node] = 0

        for i in range(0,self.number_of_nodes-1):
            for j in range(0, self.number_of_edges):

                if self.distance[self.edgeWeight[j][1]] > self.distance[self.edgeWeight[j][0]]+self.edgeWeight[j][2]:
                    self.distance[self.edgeWeight[j][1]] = self.distance[self.edgeWeight[j][0]]+self.edgeWeight[j][2]


    def displayDistance(self):

        print(self.distance)


if __name__ == '__main__':

    number_of_edges = 5
    number_of_nodes = 5

    #directed Graph
    edges =[
            [1, 2],
            [1, 3],
            [3, 4],
            [1, 4],
            [3, 5]
        ]

    weights = [ 5, 2, 1, 6, 5 ]

    g = Graph(number_of_edges, number_of_nodes, edges, weights);

    g.bellmanFord(1);

    g.displayDistance();
