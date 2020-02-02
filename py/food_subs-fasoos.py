sub = [199, 699, 2499]
#      1393 2796

if __name__ == '__main__':
    #n = int(raw_input())
    n= 7
    #arr = map(int, raw_input().split())
    arr = [1,2,4,5,7,29,30]

    days = [0]*31
    print days
    week_data  = [[0,0] for i in range(4)]

    print week_data

    for i in arr:
        days[i] = i

    day = 0
    cost = 0

    idx = 0
    for i in xrange(1, 31):
        if days[i] is not 0:
            day +=1

        if idx == 0 :
            week_data[idx][0] = 199*day
            week_data[idx][1] = 699 if day > 0 else 0
        else:
            week_data[idx][0] = week_data[idx-1][0] + 199*day
            week_data[idx-1][1] = week_data[idx-1][1]+699 if day>0 else week_data[idx-1][1]

        if i%7 ==0:
            day = 0
            idx+=0

    rem_cost = 199*day

    print 'rem cost ', rem_cost
    print week_data
    min_cost =0
    for i in xrange(4):
        min_cost = min_cost + week_data[i][0] if min_cost + week_data[i][0] < min_cost + week_data[i][1] else min_cost + week_data[i][1]
        print min_cost


    if min_cost + rem_cost > 2499:
        print 2499
    else:
        print min_cost+rem_cost


    '''
        elif i is 14 :
            pass
        elif i is 21 :
            pass
        elif i is 28:
            pass

    ########################

    ctr =0, prev_day =-1
    for i in xrange(n):

        if prev_day is not -1 :

            if arr[i] - prev_day >

    '''
