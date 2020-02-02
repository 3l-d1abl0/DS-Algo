T = int(raw_input())

while (T>0):
    N= int(raw_input())
    stl = map( int, raw_input().split() )

    dic = dict()

    for x in stl:
    	if x in dic:
    		dic[x]+=1
    	else:
    		dic[x]=1
    
    #print dic
    flg = True

    while flg is True:
    	if bool(dic)==False:
    		flg=True
    		break
    	elif N in dic:
    		cnt = dic[N]
    		del dic[N]
    		N-=cnt
    		#print "N =", N
    		#print dic
    	else:
    		flg= False
    		break

    if flg is True:
    	print 'YES'
    else:
    	print 'NO'

    T-=1