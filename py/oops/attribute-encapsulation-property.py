'''
    @property is a decorator that designates an instance attribute
    as encapsulable through methods
'''

class GetSet(object):

    instance_count = 0

    __mangled_name = 'No Privacy!'

    def __init__(self, value):
        self._attrval = value
        GetSet.instance_count +=1

    @property
    def var(self):
        print 'Getting the "var" attribute'
        return self._attrval

    @var.setter
    def var(self, value):
        print 'Setting the "var" attribute'
        self._attrval = value

    @var.deleter
    def var(self):
        print 'Deleteing the "var" attribute'
        self._attrval = None

if __name__ == "__main__":

    me = GetSet(5)
    me.var = 1000
    print me.var
    del me.var
    print me.var

    me.var = 54
    print me._attrval
    print me._GetSet__mangled_name
    print me.__mangled_name
