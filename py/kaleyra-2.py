
if __name__ == '__main__':

    input_file = "kal-in.txt"

    charMap = {'r':'g', 'g':'b', 'b':'r'}

    with open(input_file) as file:

        t = int(file.readline())
        #t = int(raw_input())

        while(t):
            t-=1

            n = int(file.readline())
            #n = int(raw_input())

            str = file.readline().strip()
            #str = raw_input().strip()
            count =0
            '''
            dp = [ [0]*n for _ in range(n)]; count = 0

            #computing for len3
            for i in range(1,n-1):
                if charMap[str[i-1]] == str[i] and charMap[str[i]] == str[i+1] and charMap[str[i+1]] == str[i-1]:
                    dp[i-1][i+1] = 1
                    count +=1
                    #print(str[i-1:i+2])

            for gap in range(4, n+1):
                for i in range(0,n-gap+1):

                    if dp[i][i+gap-2] is 1 and charMap[str[i+gap-2]] == str[i+gap-1]:
                        dp[i][i+gap-1]=1
                        count+=1
                        #print(str[i:i+gap+1])

            print(count)
            #print (count, n, str)
            #print(dp)
            '''

            if n>=3:
                for i in range(n-2):
                    for j in range(i+1,n):
                        #print (charMap[str[j-1]] , str[j])
                        if charMap[str[j-1]] == str[j]:
                            if j-i+1>=3:
                                count+=1
                        else:
                            break
                print(count)
            else:
                print(0)
