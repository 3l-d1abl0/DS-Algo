class BIT:

    """ Binary Indexed Tree - Fenwick Tree """

    def __init__(self, arr):

        self.n = len(arr)
        self.bit_array = [0]+arr

        for i in range(1,self.n+1):
            idx = i + ( i & (-i) )
            while idx<=self.n:
                self.bit_array[idx] += arr[i-1]
                idx = idx + ( idx & (-idx))

        print('Array: [{}]'.format(', '.join(map(str, self.bit_array))))

    def prefix_query(self, n):
        idx  = n+1
        sum =0
        while idx>0:
            sum += self.bit_array[idx]
            idx -= (idx & (-idx))
        return sum

    def range_query(self, from_idx, to_idx):
        if from_idx ==0:
            return self.prefix_query(to_idx)
        else:
            return self.prefix_query(to_idx) - self.prefix_query(from_idx)

    def update(self, idx, num):

        idx += 1
        while idx <=self.n:
            self.bit_array[idx] += num
            idx += (idx & (-idx))


if __name__== "__main__":

    arr = [1, 7, 3, 0, 5, 8, 3, 2, 6, 2, 1, 1, 4, 5]
    fenwick = BIT(arr)


    print('Prefix sum of first {} elements: {}'.format(13, fenwick.prefix_query(12)))
    print('Prefix sum of first {} elements: {}'.format(7, fenwick.prefix_query(6)))
    print('Range sum from pos {} to pos {}: {}'.format(1, 5, fenwick.range_query(1, 5)))

    print('Add {} to element at idx {}\n \n '.format(2, 4))
    fenwick.update(4, 2)

    print('Prefix sum of first {} elements: {}'.format(13, fenwick.prefix_query(12)))
    print('Prefix sum of first {} elements: {}'.format(7, fenwick.prefix_query(6)))
    print('Range sum from pos {} to pos {}: {}'.format(1, 5, fenwick.range_query(1, 5)))
