if __name__ == '__main__':

    t = int(raw_input())

    while(t):

        t-=1

        #n = int(file.readline())
        n = int(raw_input())

        #arr = file.readline().strip()
        arr = map(int,raw_input().split(" "))

        lf =[0 for _ in range(n)]
        rt =[0 for _ in range(n)]

        lf[0]=1
        for i in range(n):
            lf[i] = lf[i-1]+1 if arr[i]>arr[i-1] else 1

        rt[n-1] = 1
        for i in range(n-2,-1,-1):
            rt[i]= rt[i+1]+1 if arr[i]>arr[i+1]else 1

        for i in range(n):
            arr[i] = max(lf[i], rt[i])
            
        print(' '.join(map(str, dp)))
