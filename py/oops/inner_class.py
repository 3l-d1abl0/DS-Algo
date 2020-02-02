class College:

    def __init__(self):
        print('Outer Class Constructor')

    def displayC(self):
        print('College Method')

    class Student:
        def __init__(self):
            print('Inner Class Constructor')

        def displayS(self):
            print('Student Method')


C = College()
C.displayC()

#C.displayS()

S = C.Student()
S.displayS()


S= College().Student()
S.displayS()
