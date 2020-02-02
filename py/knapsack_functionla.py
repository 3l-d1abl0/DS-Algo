


class Items:

    def __init__(self, val, wt):
        self.value = val
        self.weight = wt

    def __str__(self):
        return str(self.__class__) + ": " + str(self.__dict__)

def compare(it1, it2):
    return (it2.value/it2.weight) - (it1.value/it1.weight)

def fractional_knapsack(W, Itm):
    '''
        for ele in Itm:
            print ele
    '''
    Itm = sorted(Itm, cmp=compare)

    wtSum =0;
    valSum =0;

    for ele in Itm:

        if wtSum +ele.weight <=W:
            wtSum += ele.weight
            valSum += ele.value
        else:

            rem_weight = W-wtSum
            valSum += rem_weight * (ele.value/ele.weight)

            return valSum



if __name__ == '__main__':

    W = 50
    Itm = [Items(60,10), Items(100,20), Items(120, 30)]

    print "Max. value Obtained :: ", fractional_knapsack(W, Itm)
