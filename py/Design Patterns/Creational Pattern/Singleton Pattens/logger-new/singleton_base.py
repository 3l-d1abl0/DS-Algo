class Singleton(object):
    _instance = {}

    def __new__(cls, *args, **kwargs): #gets called __init__
        if cls not in cls._instance:
            instance = super(Singleton, cls).__new__(cls)
            cls._instance[cls] = instance
        return cls._instance[cls]
