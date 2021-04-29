import sys

def doubleit(x):

    if not isinstance(x, (int, float)):
        raise TypeError

    var = int(x)*2
    return var


if __name__ =='__main__':

    input_val = sys.argv[1]
    doubled_val = doubleit(input_val)

    print("{0} x 2 = {1}".format(input_val, doubled_val))
