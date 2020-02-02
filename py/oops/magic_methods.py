#Many operations are handled by the internal Magic Methods
#Which can used to provide custom functionality in your own classes

class SumList(object):

    def __init__(self, this_list):
        self.my_list = this_list

    def __add__(self, other):
        new_list = [x + y for x,y in zip(self.my_list, other.my_list) ]
        #print zip(self.my_list, other.my_list)
        return SumList(new_list)

    def __repr__(self): #string representation
        return str(self.my_list)



if __name__ == '__main__':

    ob1 = SumList([1,2,3,4,5])
    ob2 = SumList([100, 200, 300, 400, 500])

    sumObj = ob1+ob2
    print sumObj


    ''' Core Syntax Resolutions

        'abc' in var  => var.__contains__('abc')
         var == 'abc' => var.__eq__('abc')
         var[1]  => var.__getitem__(1)
         var[1:3]  => var.__getslice__(1,3)
         len(var)  => var.__len__()
         print var  => var.__repr__()
    '''
