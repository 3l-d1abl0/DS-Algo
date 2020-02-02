def lis(arr):
    
    n = len(arr)
    
    dp = [1]*n
    
    for j in range(n):
        
        for i in range(j):
            if arr[j] > arr[i] and dp[i]+1 > dp[j]:
                dp[j] = dp[i]+1
    #print dp      
    return max(dp)

def cal_idx(arr, l, r, ele):
    print l,r,ele
    while(r-l>1):
        mid = l+( (r-l) /2)
        
        if arr[mid]>=ele:
            r=mid
        else:
            l=mid
    return r

def lis_opti(arr):
    
    n = len(arr)
    print 'n =',n
    
    table = [0]*n
    table[0] = arr[0]
    idx =1
    
    for i in range(1, n):
        
        if arr[i]<table[0]:
            table[0] = arr[i]
            
        elif arr[i]> table[idx-1]:
            table[idx]= arr[i]
            idx+=1
        else:
            ret_idx = cal_idx(arr,0,idx, arr[i])
            print 'ret_idx :: ',ret_idx, arr[i]
            table[ret_idx] = arr[i] #returns index of largest of smallest number
            print table
            
    print table
    return idx
    
    

if __name__ == "__main__":
    
    arr =[2,6,3,4,1,2,9,5,8]
    
    
    print 'LIS : {}'.format(lis(arr)) #n^2
    
    print 'LIS OPTI : {}'.format(lis_opti(arr)) #nlogn