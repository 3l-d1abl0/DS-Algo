class A(object):
    def __init__(self):
        print('Constructor-A')

    def displayA(self):
        print('Method-A')

class B(A):
    def __init__(self):
        print('Constructor-B')

    def displayB(self):
        print('Method-B')

class C(B):
    def __init__(self):
        print('Constructor-C')

    def displayC(self):
        print('Method-C')


if __name__ == '__main__':
    c = C()
    c.displayB()
    c.displayA()
    c.displayC()

    print(C.mro())
