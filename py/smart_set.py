import math


'''
3
9
6 2 11 1 9 14 13 4 18
3
7 3 1
3
1 2 4


1 6 11
1 3 7
1
'''

def countBit(num):
	print 'Counting ... ', num
	cnt=0
	while(num>0):
		if(num&1):
			cnt+=1
		num = num>>1
		print 'Num :: {} '.format(num)
		
	return cnt
		

if __name__ == "__main__":
	print 'T'
	T= int(raw_input())
	print 'loop'
	
	for _ in xrange(T):
		bitarr = {}
		
		N= int(raw_input())
		arr = map(int, raw_input().split())
		
		print N,arr
		
		for i in xrange(N):
			idx = countBit(arr[i]);
			print ' {} : {} '.format(arr[i], idx)
			if idx in bitarr:
				bitarr[idx].append(arr[i])
			else:
				bitarr.update({idx: [arr[i]] })
			
		sset = []
		#for i in xrange(0,33):
		for key in bitarr:
			print 'key : {}'.format(key)
			print bitarr[key]
			minn = 10**6
			for j in xrange( len(bitarr[key]) ):
				if(minn>bitarr[key][j]):
					minn = bitarr[key][j]
					
			sset.append(minn)
		sset.sort()
		#print sset
		for val in sset:
			print val,
		print '\n'
			
