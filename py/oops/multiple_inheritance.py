


# "new style" classes, inheriting from Super Ancestor Class - Object

class A(object):

    def dothis(self):
        print 'doing this in A'

class B(A):
    def dothis(self):
        print('Doing this in B')
'''
class C(object):

    def dothis(self):
        print 'doing this in C'
'''
class C(A):

    def dothis(self):
        print 'doing this in C'

class D(B,C):
    pass



if __name__ == "__main__":

    dd = D()
    dd.dothis()
    #By default python uses DFS to resolve inheritance Order
    #Method resolution order
    #D -> B -> A -> C
    print D.mro()


    #For diamond inheritance
    #If same class appears in mro, the earlier occurances of classes are removed in the mro
    #D -> B -> C -> A
