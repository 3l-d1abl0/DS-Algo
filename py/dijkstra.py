from heap_sort import build_heap
import sys
from collections import defaultdict

class Node_Weight(object):

    def __init__(self, node, dist) :
        self.node = node
        self.dist = dist
        
    def __repr__(self):
        return "{} :: {}".format(self.node, self.dist)
'''
    def __str__(self):
        return "{} :: {}".format(self.name, self.dist)'''


class Priority_Queue(object):
    '''min heap'''
    
    def __init__(self) -> None:
        self.size =0
        self.arr = list()

    def empty(self):
        if self.size == 0:
            return True
        else:
            return False

    def top(self):
        if self.size ==0:
            return None
        else:
            return self.arr[0]

    def pop(self):
        
        self.arr[0]= self.arr[self.size-1]
        self.size = self.size-1
        self.arr.pop()

        self.heapify(0, self.size-1)

    def push(self, weight, node):
        
        self.size = self.size +1
        self.arr.append([weight, node])
        self.build_heap()

    def build_heap(self):
        
        for start in range(int((self.size-2)/2),-1,-1):
            self.heapify(start, self.size-1)

    def heapify(self, start, end):
        #minheap
        
        root = start
        child = (2*root)+1

        while(child <= end):

            #pick the smallest child
            if child+1<=end and self.arr[child][0]>self.arr[child+1][0]:
                child +=1

            if self.arr[root][0]> self.arr[child][0]:
                self.arr[root][0], self.arr[child][0] = self.arr[child][0], self.arr[root][0]
                self.arr[root][1], self.arr[child][1] = self.arr[child][1], self.arr[root][1]
                
                #new root and new child
                root = child
                child= (2*root)+1
            else:
                return

    def display(self):

        print("Queue Size :", self.size)
        for idx in range(self.size):
            print(self.arr[idx])


class Graph(object):

    def __init__(self, nov, noe) -> None:

        self.number_of_vertices = nov
        self.number_of_edges = noe

        #self.distance = [sys.maxsize for _ in range(nov)]
        self.distance = [1000000] * self.number_of_vertices

        #adjacency list
        self.graph = defaultdict(list)

        #get a priority queue
        self.pq = Priority_Queue()

    def addEdge(self, src, dest, weight):
        #Undirected, non negative
        self.graph[src].append( Node_Weight(dest, weight) )
        self.graph[dest].append( Node_Weight(src, weight) )

    def printGraph(self, node):

        '''
        print('Adjceny List: ')
        for idx, val in self.graph.items():
            print(" {} --> {}".format(idx, val))
        '''


        print("Shortest distance from Node {}".format(node))
        for i, val in enumerate(self.distance):
            print("{} to {} -> {}".format(node, i, val))


    def dijkstra(self, source_node):

        self.distance[source_node] = 0
        self.pq.push(0, source_node) #weight, source_node

        while(self.pq.empty() is False):

            current_node = self.pq.top()
            self.pq.pop()


            for ele in self.graph[current_node[1]]:
                
                if(current_node[0]+ele.dist <  self.distance[ele.node]):
                
                    self.pq.push(current_node[0]+ele.dist, ele.node)
                    self.distance[ele.node] = current_node[0]+ele.dist


if __name__ == "__main__":
    '''
    edges = [ [0,1], [0,4], [0,7], [1,2], [1,3], [1,7], [2,3], [2,6], [3,6], [4,5], [4,6], [4,7], [5,2], [5,6], [7,5], [7,2] ]
    weights =  [ 5, 9, 8, 12, 15, 4, 3, 11, 9, 4, 20, 5, 1, 13, 6, 7 ]
    '''


    edges = [ [0,1], [1,2], [2,3], [3,4], [4,5], [0,3], [0,4] ]
    weights = [5, 2, 3, 2, 3, 9, 2]

    '''
    Single source shortest path
    non-negative weights
    '''

    number_of_vertices = 8
    number_of_edges = len(edges)

    g = Graph(number_of_vertices, number_of_edges)

    for idx in range(0, len(weights)):
        g.addEdge( edges[idx][0], edges[idx][1], weights[idx])

    g.printGraph(0)

    g.dijkstra(0)
    
    g.printGraph(0)