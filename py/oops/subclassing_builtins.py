
class MyDict(dict):

    def __setitem__(self, key, val):
        print "Setting a Key and Value"
        #self[key] = val # will lead to recursion, since this statement will call setitem
        dict.__setitem__(self, key, val)


class MyList(list): #List with 1 indexing

    def __getitem__(self, index):
        if index == 0: raise IndexError
        if index > 0 : index = index -1
        return list.__getitem__(self, index)

    def __setitem__(self, index, value):
        print('set Item')
        if index == 0: raise IndexError
        if index > 0 : index = index -1
        list.__setitem__(self, index, value)

if __name__ == '__main__':
    '''dd = MyDict()
    dd['a'] = 5
    dd['b'] = 6
    for key in dd.keys():
        print('{0} = {1}'.format(key, dd[key]) )
    '''

    x = MyList(['a', 'b', 'c'])
    print x
    x.append('spam')
    print x[1]
    print x[4]
    print x[0]
