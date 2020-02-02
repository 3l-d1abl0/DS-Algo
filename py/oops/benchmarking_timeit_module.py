
import timeit

'''
print ('by index')
print timeit.timeit(stmt="mydict['c']", setup="mydict= {'a': 5, 'b':6, 'c': 7}", number =100000000)

print ('by get')
print timeit.timeit(stmt="mydict.get('c')", setup="mydict= {'a': 5, 'b':6, 'c': 7}", number =100000000)
'''

'''
python -m timeit -n 1000000 -s "mydict = {'a':5, 'b':6, 'c':7}" "mydict.get('c')"

python -m timeit -n 1000000 -s "mydict = {'a':5, 'b':6, 'c':7}" "mydict['c']"

'''

import timeit

def testfunc(this_dict, key):
    return this_dict[key]

print timeit.timeit("testfunc(mydict, key)", setup="from __main__ import testfunc; mydict= {'a':1, 'b':2, 'c':3}; key='c' ", number=10000)
