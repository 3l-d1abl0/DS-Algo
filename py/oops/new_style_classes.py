#Old Style Class
class OldClass():
    pass


#New Style Class
class NewClass(object):
    pass


oc = OldClass()
nc = NewClass()

#Concept of class and type not related in Old style classes
print(type(oc)) #instance
print(type(nc)) #NewClass

print oc.__class__
print nc.__class__
