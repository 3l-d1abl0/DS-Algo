def maxProfit(arr,N,C):

    max_profit_far = 0
    max_profit_here = 0

    for i in range(0, N):
        max_profit_here = max_profit_here + (C-arr[i])
        if max_profit_here < 0:
            max_profit_here = 0
        elif (max_profit_far < max_profit_here):
            max_profit_far = max_profit_here

    return max_profit_far


if __name__ == '__main__':

    T= int(raw_input())

    for _ in range(T):
        N=int(raw_input())
        arr = map(str,raw_input().split(' '))
        #print N,C
        #print arr

        val =0
        if N%2==0:
            val= arr[N/2-1]+arr[N/2]
        else:
            val = arr[N/2]

        #print val,'\n'


        tmp='-10000'
        #print tmp,'\n'
        for i in xrange(N):
            if tmp !='-10000':
                arr[i],tmp=tmp,arr[i]
                print 'not !=-10000'
            if arr[i]=='0':
                if i!=N-1:
                    tmp = arr[i+1]
                    arr.append(str(val))
                else:
                    arr[i+1]=str(val)

                i+=1

        if tmp!='-10000':
            arr.append(str(tmp))

        #print arr

        neg_cnt =0
        pos_cnt=0

        neg_idx=-1
        pos_idx=-1
        for i in xrange(len(arr)):
            if neg_cnt>=1 and pos_cnt>=2:
                break

            if int(arr[i])<0:
                neg_cnt+=1

                if neg_cnt==1:
                    neg_idx= i

            else:
                pos_cnt+=1
                if pos_cnt==2:
                    pos_idx = i

        if neg_idx < pos_idx:
            if neg_idx !=-1:
                del arr[neg_idx]
                if pos_idx!=-1:
                    del arr[pos_idx-1]
            else:
                if pos_idx!=-1:
                    del arr[pos_idx]
        else:
            if pos_idx !=-1:
                del arr[pos_idx]
                if neg_idx !=-1:
                    del arr[neg_idx-1]
            else:
                if neg_idx !=-1:
                    del arr[neg_idx]


        arr = map(int, arr)
        for i in arr:
            print i,

        print '\n'
