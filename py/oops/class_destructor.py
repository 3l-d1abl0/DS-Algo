class Demo:

    def __init__(self):
        print('Constructor Called')

    def display(self):
        print('Display Method Called')

    def __del__(self):
        print('Destructor Called')

D = Demo()
D.display()
