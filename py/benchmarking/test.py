import timeit

print('by index: ', timeit.timeit(stmt="mydict['c']", setup="mydict ={'a':5, 'b': 6, 'c': 7}", number=1000000))


print('by get: ', timeit.timeit(stmt="mydict.get('c')", setup="mydict= {'a':5, 'b': 6, 'c':7}", number=1000000))

'''
Terminal

python3 -m timeit -n 1000000 -s "mydict = {'a': 5, 'b': 6, 'c': 7}" "mydict.get('c')"

python3 -m timeit -n 1000000 -s "mydict = {'a' : 5, 'b':  6, 'c': 7}" "mydict['c']"

'''


def testme(this_dict, key):
    return this_dict[key]

mysetup = "from __main__ import testme; mydict ={'a': 1, 'b':2, 'c': 3}; key='c'"

print timeit.timeit(stmt="testme(mydict, key)", setup=mysetup, number=100000)
