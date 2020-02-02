from inspect import getmembers, isclass, isabstract
import autos



class AutoFactory(object):

    autos = {}

    def __init__(self):
        self.load_autos()
        print (self.autos)

    def load_autos(self):
        classes = getmembers(autos, lambda m: isclass(m) and not isabstract(m))
        #classes = getmembers(autos)
        #classes = getattr(autos)
        #classes = dir(autos)

        #print (getmembers(autos))

        """for element_name in dir(autos):
            element = getattr(autos, element_name)
            print (element)
        """

        for name, _type in classes:
            print(name," ", _type)
            if isclass(_type) and issubclass(_type, autos.AbsAuto):
                self.autos.update([[name, _type]])

    def create_instance(self, carname):
        if carname in self.autos:
            return self.autos[carname]()
        else:
            return autos.NullCar(carname)
