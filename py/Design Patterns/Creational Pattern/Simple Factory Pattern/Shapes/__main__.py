from factory import ShapeFactory

f = ShapeFactory()
s = f.getShape('square')
print s
s.draw()

t = f.getShape('triangle')
