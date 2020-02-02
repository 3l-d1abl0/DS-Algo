if __name__=="__main__":
    
    #str ="agbdba"
    str = "GEEKS FOR GEEKS"
    str_len = len(str)
    
    dp = [ [ 0 for i in range(str_len) ] for j in range(str_len)]
    
    #print dp
    
    for i in range(0,str_len):
        dp[i][i]=1
        
    for j in range(2,str_len+1):
        
        for i in range(0, str_len-j+1):
            
            if str[i]==str[i+j-1] and j==2:
                dp[i][i+j-1]=2
            elif str[i]==str[i+j-1]:
                dp[i][i+j-1]= 2+ dp[i+1][i+j-2]
            else:
                dp[i][i+j]= max(dp[i+1][i+j+1], dp[i][i+j])
                
    print dp[0][str_len-1]