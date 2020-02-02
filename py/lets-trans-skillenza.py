import math

t = int(input())
for _ in range(t):

    n = int(input())
    #print(n, end="n \n")

    mid = []
    if n&1:
        mid.append(0), mid.append(math.floor(n/2))
    else:
        mid.append(math.floor(n/2)-1), mid.append(math.floor(n/2))

    num_list = list(map(int, input().split(" ")))
    #print(num_list)

    max_val = max(num_list)

    if n&1:
        #print(math.floor(n/2), end="==\n")
        if num_list[math.floor(n/2)] == max_val:
            print ('0')
            continue
    else:
        if num_list[math.floor(n/2)-1] == max_val or num_list[math.floor(n/2)] == max_val:
            print ('0')
            continue

    min_idx = 2000
    for x in range(n):
        if n&1:
            if num_list[x] == max_val:
                min_idx = min_idx if min_idx < abs(x-math.floor(n/2)) else abs(x-math.floor(n/2))
        else:
            if num_list[x] == max_val:
                #print(x, end=" x\n")
                min_idx = min_idx if min_idx < abs(x-(math.floor(n/2)-1)) else abs(x-(math.floor(n/2)-1))
                #print(min_idx, end="min_idx \n")
                min_idx = min_idx if min_idx < abs(x-math.floor(n/2)) else abs(x-math.floor(n/2))

    print(min_idx, end="\n")

          
