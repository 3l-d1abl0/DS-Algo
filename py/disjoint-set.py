class DisjointSet:
    """docstring for DisjointSet."""
    def __init__(self):
        self.map = dict()

    class Node:
        def __init__(self, data, rank):
            self.data = data
            self.parent = self
            self.rank = rank

    def makeSet(self,data):
        node = self.Node(data,0)
        self.map[data] = node

        #findSet gives you the parent Element
    def findSet(self,data):

        set = self.map[data]
        if set.parent == set:
            return set
        else:
            return self.findSet(set.parent.data)

    def union(self,d1,d2):
        parent1 = self.findSet(d1)
        parent2 = self.findSet(d2)

        if parent1.data == parent2.data:
            return

        if parent1.rank >= parent2.rank:

            parent1.rank = parent1.rank+1 if (parent1.rank == parent2.rank) else parent1.rank
            parent2.parent = parent1
        else:
            parent1.parent = parent2


if __name__=="__main__":

    ds = DisjointSet()

    ds.makeSet(1)
    ds.makeSet(2)
    ds.makeSet(3)
    ds.makeSet(4)
    ds.makeSet(5)
    ds.makeSet(6)
    ds.makeSet(7)


    ds.union(1,2)
    ds.union(2,3)
    ds.union(4,5)
    ds.union(6,7)
    ds.union(5,6)
    #ds.union(3,7)



    print '{}'.format(ds.findSet(1).data)
    print '{}'.format(ds.findSet(2).data)
    print '{}'.format(ds.findSet(3).data)
    print '{}'.format(ds.findSet(4).data)
    print '{}'.format(ds.findSet(5).data)
    print '{}'.format(ds.findSet(6).data)
    print '{}'.format(ds.findSet(7).data)
