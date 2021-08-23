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

    #directed Graph
    '''
    number_of_nodes = 5
    number_of_edges = 5

    edges =[ [1, 2], [1, 3], [3, 4], [1, 4], [3, 5] ]
    weights = [ 5, 2, 1, 6, 5 ]


    number_of_nodes = 5
    number_of_edges = 7
    edges = [ [0,1], [0,2], [1,2], [0,3], [3,4], [4,3], [2,4] ]
    weights = [ 4, 5, -3, 8, 2, 1, 4]
    '''

    number_of_nodes = 6
    number_of_edges = 8
    edges = [ [4,5], [3,4], [2,5], [0,2], [1,2], [5,4], [0,3], [0,1] ];
    weights = [ 2, 2, 4,5,-3,1,6,4 ];

    g = Graph(number_of_edges, number_of_nodes, edges, weights);

    g.bellmanFord(1);

    g.displayDistance();
