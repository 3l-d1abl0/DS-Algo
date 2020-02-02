'''
Singleton pattern ensures that a class has only one instance,
and provide a global access to it. eg. logger
uses __new__ => called before __init__ and responsible for returning
a new instance of your class


The Borg Idiom lets a class ahve as many instances as one like,
but ensures that they all share the same state.
uses __init__ => doesn't return anything , only responsible for
initalizing the instance after its been created.
'''

class Singleton(object):
    __instance = None
    def __new__(cls, val=None):

        if Singleton.__instance is None:
            Singleton.__instance = super(Singleton, cls).__new__(cls)
            #Singleton.__instance = object.__new__(cls)
            print Singleton.__instance
        else:
            print('Not None')

        Singleton.__instance.val = val
        return Singleton.__instance


class Borg:
    __shared_state = {}
    def __init__(self):
        self.__dict__ = self.__shared_state
