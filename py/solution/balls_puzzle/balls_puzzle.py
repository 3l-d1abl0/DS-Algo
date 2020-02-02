_inp_src ="input.txt"
_op_src = "output.txt"

def get_index(arr, len, sz):
    arr.sort()
    #print arr
    min_diff = 100000000000000
    idx = -1
    for i in range(len-sz+1):
        if arr[i+sz-1]-arr[i] < min_diff:
            min_diff,idx = arr[i+sz-1]-arr[i],i
    return idx

if __name__=="__main__":

    with open(_inp_src, 'r') as inp:
        array_len = int(inp.readline())
        #print array_len
        array = map(int, inp.readline().split(','))
        #print array
        subset_size = int(inp.readline())
        #print subset_size

        idx = get_index(array, array_len, subset_size)
        #print idx

        op = open(_op_src,"w")
        for i in range(idx,idx+subset_size):
            if i == idx+subset_size-1:
                op.write("{}".format(array[i]))
            else:
                op.write("{},".format(array[i]))
        op.close()

        #for i in range(idx,idx+subset_size):
            #print array[i]
