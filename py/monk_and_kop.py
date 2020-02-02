

T = int(raw_input())

while (T!=0):
	N,K = map(int, raw_input().split())
	arr = map(int, raw_input().split())
	prod =-1
	last = N-1

	for i in xrange(0,K+1):
		#print '{} * {}'.format(arr[i], arr[last-(K-i)])
		if (arr[i]*arr[last-(K-i)]) > prod:
			prod = arr[i]*arr[last-(K-i)]

	print prod
	T-=1
	