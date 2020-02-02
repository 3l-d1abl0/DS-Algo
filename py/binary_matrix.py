def maxBinary(N):
    
    local_max = -1000000
    local_index = -1
    for i in range(1,N+1):
        binary = int(raw_input(),2)
        
        if binary > local_max:
            local_max = binary
            local_index = i
            
    return local_index

if __name__=="__main__":
    
    N,M = map(int, raw_input().split())
    
    print maxBinary(N)