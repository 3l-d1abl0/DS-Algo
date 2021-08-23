import sys
from queue import PriorityQueue
from collections import defaultdict

class Graph(object):
    """Graph"""

    def __init__(self, nov, noe, edges, weights):
        self.number_of_nodes = nov
        self.number_of_edges = noe
        self.edges = edges
        self.weights = weights
        #adjceny list
        self.adj = defaultdict(list)
        self.pq = PriorityQueue()
        self.mst = [False] *self.number_of_nodes
        #self.distance = [sys.maxsize] *self.number_of_nodes
        self.distance = list()

        self.prepareEdges()

    def prepareEdges(self):

        for idx in range(self.number_of_edges):
            self.adj[self.edges[idx][0]].append([ self.weights[idx], self.edges[idx][1] ])
            self.adj[self.edges[idx][1]].append([ self.weights[idx], self.edges[idx][0] ])

    def prims(self, vertex):

        self.pq.put((0, vertex))

        while not self.pq.empty():

            current_node = self.pq.get()

            if self.mst[current_node[1]] is False:

                self.mst[current_node[1]] = True
                self.distance.append(current_node)

                for node in self.adj[current_node[1]]:
                    if self.mst[node[1]] == False:
                        self.pq.put((node[0], node[1]))

    def display_mst(self):

        sum =0
        print(self.distance)
        for ele in self.distance:
            sum+= ele[0]
            print("E: ",ele[1]," wt: ",ele[0])

        print("MST: ", sum)



if __name__ == '__main__':
    '''
    pick an min edge from the qriority queue
    check if its already in the mst
    if not add it to the mst
    add its neighbours to the priority queue
    O(ElogV)
    '''

    '''
    edges = [ [0,7],[2,3],[1,7],[0,2],
                      [5,7],[1,3],[1,5],[2,7],
                      [4,5],[1,2],[4,7],[0,4],
                      [6,2],[3,6],[6,0],[6,4] ]

    weights = [ 0.16, 0.17, 0.19, 0.26,
                     0.28, 0.29, 0.32, 0.34,
                     0.35, 0.36, 0.37, 0.38,
                     0.40, 0.52, 0.58, 0.93 ]

    number_of_nodes = 8
    number_of_edges = len(weights)
    '''

    
    edges = [ [0,1], [0,4], [0,7], [1,2], [1,3], [1,7], [2,3], [2,6], [3,6], [4,5], [4,6], [4,7], [5,2], [5,6], [7,5], [7,2] ];
    weights = [5, 9, 8, 12, 15, 4, 3, 11, 9, 4, 20, 5, 1, 13, 6, 7];

    number_of_nodes = 8
    number_of_edges = len(weights)


    '''
    edges = [ [0,1], [1,2], [2,3], [3,4], [4,5], [0,3], [0,4] ];
    weights = [5, 9, 8, 12, 15, 4, 3, 11, 9, 4, 20, 5, 1, 13, 6, 7];

    number_of_nodes = 7
    number_of_edges = len(weights)
    '''

    g = Graph(number_of_nodes, number_of_edges, edges, weights)

    g.prims(0)

    g.display_mst()
