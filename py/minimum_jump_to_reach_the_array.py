def minJumps(arr,n):

    jmp =[float('inf') for i in range(n)]
    #jmp = [0] * n

    if n==0 or arr[0]==0:
        return float('inf')

    print'-----'
    jmp[0] = 0
    for i in range(1,n):

        for j in range(0,i):
             if j+arr[j]>=i:
                 jmp[i]= min(jmp[i], jmp[j]+1)

    return jmp[n-1]

def minJumpLinear(arr, n):

    ladder = arr[0]
    stairs = arr[0]
    jump =1;

    for lvl in xrange(1,n):

        if ladder < lvl +arr[lvl]:
            ladder = lvl+arr[lvl]

        stairs-=1
        if stairs ==0:
            jump+=1
            stairs = ladder - lvl

    return jump

if __name__ == '__main__':
    # Driver Program to test above function
    arr = [1, 3, 6, 1, 0, 9]
    size = len(arr)
    print('Minimum number of jumps to reach','end is', minJumps(arr,size))
    print('Minimum number of jumps to reach','end is', minJumpLinear(arr,size))
