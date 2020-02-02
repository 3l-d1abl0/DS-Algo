if __name__=="__main__":
    
    T = int(raw_input())
    for _ in range(T):
        
        N = int(raw_input())
        
        arr = [ [0 for i in range(N+1)] for i in range(3) ]
        
        arr[0] = map(int, raw_input().split())
        
        ##
        for i in range(N):
            
            if arr[0][i]%2==0 or arr[0][i]==1:
                arr[1][i+1] = arr[1][i]+1#old
                arr[2][i+1] = arr[2][i]#cold
            else:
                arr[1][i+1] = arr[1][i] #old
                arr[2][i+1] = arr[2][i]+1 #cold           
                
        
        query = int(raw_input())
        
        for i in range(query):
            
            L,R = map(int, raw_input().split())
            if arr[1][R]-arr[1][L-1] < arr[2][R]-arr[2][L-1]:
                total = (arr[1][R]-arr[1][L-1])+(arr[2][R]-arr[2][L-1])
                print (arr[2][R]-arr[2][L-1]) - int(total/2)
            else:
                print '0'
            
            