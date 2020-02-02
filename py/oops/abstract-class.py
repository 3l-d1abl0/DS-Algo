import abc
class GetterSetter(object):
    __metaclass__ = abc.ABCMeta

    @abc.abstractmethod
    def set_val(self, input):
        """ Set value in the instace"""
        return

    @abc.abstractmethod
    def get_val(self):
        """ Get and return a value from the instance """
        return

class MyClass(GetterSetter):

    def set_val(self, input):
        self.val = input

    def get_val(self):
        return self.val


if __name__ == "__main__":
    #x = MyClass()
    x = GetterSetter()
    print(x)
    x.set_val(12)
    print(x.get_val())
