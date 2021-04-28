import pdb;

'''
n -> next line wont take you to the next frame /stack (function call)
use step -> s for that

l -> list shows you the code and the position within it

h -> help , lists the command that are available

'''

def doubleVal(argsum, val):
    argsum = 0
    newval = argsum +val;
    return newval


pdb.set_trace()

values = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]

mysum = 0

for val in values:
    mysum = doubleVal(mysum, val)

print (mysum)
