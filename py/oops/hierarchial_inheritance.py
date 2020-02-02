class A(object):
    def displayA(self):
        print('Method-A')


class B(A):
    def displayB(self):
        print('Method-B')

class C(A):
    def displayC(self):
        print('Method-C')


if __name__ == '__main__':
    c = C()
    c.displayA()
    c.displayC()
    c.displayB()
    
