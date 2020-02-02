class Node():
    def __init__(self, name, distance):
        self.word = name
        self.len = distance

def differByOne(a, b):

    if len(a) != len(b):
        return False

    counter = 0
    for i in range( len(a) ):
        if a[i]!=b[i]:
            counter +=1

    return False if counter !=1 else True

def shortestChainLen(start, target, D):

    q= list()
    q.append(Node(start,1))

    while q.__len__() > 0:

        curr = q.pop()

        for ele in D:

            if differByOne(curr.word, ele):

                q.append(Node(ele, curr.len+1)) #add the word to queue

                D.remove(ele)

                if ele == target:
                    return curr.len+1


if __name__ == '__main__':
    D = []
    D.append("poon")
    D.append("plee")
    D.append("same")
    D.append("poie")
    D.append("plie")
    D.append("poin")
    D.append("plea")
    start = "toon"
    target = "plea"
    print ("Length of shortest chain is: %d"% shortestChainLen(start, target, D))
