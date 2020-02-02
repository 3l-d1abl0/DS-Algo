import sys

def doubleit(x):
    var = x*2
    return var

if __name__ == '__main__':
    input_val = sys.argv[1]
    double_val = doubleit(input_val)

    print "the value of {0} is {1}".format(input_val, double_val)
