class NewClass(object):
    classy = 'class value!'

    def __init__(self):
        print('Initalized')
count = 100
class InstanceCounter(object):
    count = 0

    def __init__(self,val):
        self.val = self.filterint(val)
        InstanceCounter.count +=1

    @staticmethod #any utility function that doesn't access any instance property directly
    def filterint(value):
        if not isinstance(value, int):
            return 0
        else:
            return value

    def set_val(self, newval):
        self.val = newval

    def get_val(self):
        return self.val

    #Instance Method
    # def get_count(self):
    #     return count

    @classmethod#decorator to specify if instace method or class method
    def get_count(cls):#receives the Class as argument
        return cls.count


if __name__ == "__main__":


    # dd = NewClass()
    # print(dd.classy)
    #
    # dd.classy ="Instance Value"
    #
    # print(dd.classy)
    #
    # del dd.classy
    #
    # print(dd.classy)

    a = InstanceCounter(4)
    b = InstanceCounter(8)
    c = InstanceCounter(16)


    for obj in (a, b, c):
        print ("val of Obj : %s"%(obj.get_val()))
        print(" Count (from instance) : {} ".format(obj.count))
        #print("val of obj : %s"%(obj.get_val())
