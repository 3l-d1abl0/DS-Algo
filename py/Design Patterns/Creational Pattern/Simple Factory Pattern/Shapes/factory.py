'''
Interface vs Abstract Base class
Interface - just defines the methods
Abstract Base Class- also defines attributes that should be interited
'''

class ShapeInterface(object):
    def draw(self): pass

class Circle(ShapeInterface):
    def draw(self):
        print("Circle.draw")

class Square(ShapeInterface):
    def draw(self):
        print("Square.draw")

class ShapeFactory:
    @staticmethod
    def getShape(type):
        if type == 'circle':
            return Circle()
        if type == 'square':
            return Square()

        assert 0, 'Could not find shape '+type
