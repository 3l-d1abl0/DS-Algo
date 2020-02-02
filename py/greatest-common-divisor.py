def GCDItr(a, b):

    while b!=0:
        r = a%b
        a= b
        b = r
    return a

def GCDRec(a, b):
    if b == 0:
        return a
    else:
        return GCDRec(b, a%b)

if __name__ == "__main__":

    a = 32; b = 48
    print("GCD({}, {}) = {}".format(a, b, GCDRec(a, b)))

    a = 112 ; b=248
    print("GCD({}, {}) = {}".format(a, b, GCDItr(a, b)))
