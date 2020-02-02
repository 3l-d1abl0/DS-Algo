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

    return True if counter ==1 else False

def shortestChainLen(start, target, D):

    q1 = list(); q2 = list()
    dist1 = {}
    dist2 = {}

    q1.append(Node(start, 1))
    q2.append(Node(target, 1))

    dist1[start] = 0
    dist2[target] = 0

    while q1.__len__() > 0 and q2.__len__():


        curr1 = q1.pop()

        for ele in D:

            if differByOne(curr1.word, ele) and ele not in dist1:

                q1.append(Node(ele, curr1.len+1))
                dist1[ele] = curr1.len+1

                if ele == target:
                    print('1')
                    return curr1.len+1

                #if this word has already been traversed by otherside
                if ele in dist2:
                    print('2')
                    return dist1[ele]+dist2[ele]-1


        curr2 = q2.pop()

        for ele in D:

            if differByOne(curr2.word, ele) and ele not in dist2:

                q2.append(Node(ele, curr2.len+1))
                dist2[ele] = curr2.len+1

                if ele == start:
                    print('3')
                    return curr2.len+1

                #if this word has already been traversed by otherside
                if ele in dist1:
                    print('4')
                    return dist1[ele]+dist2[ele]-1


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
