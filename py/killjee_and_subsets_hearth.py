import math

def powerset(s):
    x = len(s)
    masks = [1 << i for i in range(x)]
    for i in range(1, 1 << x):
        yield [ss for mask, ss in zip(masks, s) if i & mask]

def solve (a):
    # Write your code here
    sub_list = list(powerset(a))
    MAXX = max(a)
    dic = dict()
    for x in range(MAXX+1):
    	dic[x]=0

    for ll in sub_list:
    	xsum =0
    	lenn = len(ll)
    	for x in ll:
    		xsum =xsum^x
    	if xsum in dic:
    		dic[xsum] = max(dic[xsum], lenn)
    summ = 0
    for j in range(MAXX+1):
    	summ = (summ + (dic[j]*(math.pow(31,j) )%1000000007 )%1000000007 )% 1000000007

    return int(summ)



n = int(raw_input())
a = map(int, raw_input().split())

out_ = solve(a)
print out_
