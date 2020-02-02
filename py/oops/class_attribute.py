class NewClass(object):
    classy = 'class value!'

    def __init__(self):
        print('Initalized')
count = 100
class InstanceCounter(object):
    count = 0

    def __init__(self,val):
        self.val = val
        InstanceCounter.count +=1

    #Instance Method
    def get_val(self):
        return self.val

    #Instance Method
    def get_count(self):
        return count


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
        print "val of obj : %s"%(obj.get_val())
        print "count (from instance) : %s   "%(obj.count)
