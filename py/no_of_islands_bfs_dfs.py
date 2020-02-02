from queue_stack import Queue

class Graph:
    def __init__(self, mat):
        self.row = len(mat)
        self.col = len(mat[0])
        self.visited = []
        self.gr = mat
        self.x = [-1,-1,0,1,1,1,0,-1]
        self.y = [0,1,1,1,0,-1,-1,-1]

        '''
        for i in range(self.row):
            self.visited.append([])
            for j in range(self.col):
                if mat[i][j] is 0:
                    self.visited[i].append(False)
                else:
                    self.visited[i].append(True)

                print self.visited[i][j],
            print '\n'
        '''

        self.visited = [[False for _ in range(col)] for _ in range(row)]

    def check(self,i,j):
        if i>=0 and i<self.row and j>=0 and j<self.col and self.visited[i][j] is False and self.gr[i][j] is 1:
            return True
        else:
            return False

    def dfs(self,i,j):
        self.visited[i][j] = True
        for k in range(8):
            if self.check(i+self.x[k], j+self.y[k]):
                self.dfs(i+self.x[k], j+self.y[k])

    def findIslands(self):

        cnt =0
        for i in range(row):
            for j in range(col):
                if self.visited[i][j] is False and self.gr[i][j] is 1:
                    self.dfs(i,j)
                    cnt +=1

        return cnt

    def bfs(self, i, j):

        self.visited[i][j] = True
        q = Queue()

        q.push((i,j))

        while q.empty() is False:

            ij = q.pop()

            for idx in range(8):
                #print ij[0]+self.x[idx],ij[1]+self.y[idx]
                if self.check(ij[0]+self.x[idx], ij[1]+self.y[idx]):
                    self.visited[ij[0]+self.x[idx]][ij[1]+self.y[idx]] = True
                    q.push( (ij[0]+self.x[idx],ij[1]+self.y[idx]) )
                    #q.get_queue()


    def findIslandsBfs(self):
        cnt =0
        for i in range(row):
            for j in range(col):
                if self.visited[i][j] is False and self.gr[i][j] == 1:
                    self.bfs(i,j)
                    cnt+=1
        return cnt

if __name__=="__main__":

    mat = [[1, 1, 0, 0, 0],
        [0, 1, 0, 0, 1],
        [1, 0, 0, 1, 1],
        [0, 0, 0, 0, 0],
        [1, 0, 1, 0, 1]]

        #8 Neighbours

    row = len(mat)
    col = len(mat)

    #print row,col

    gr = Graph(mat)

    #print '{}'.format(gr.findIslands())

    print '#Islands {}'.format(gr.findIslandsBfs())
