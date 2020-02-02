def getSum(fenwickTree, n, idx):

	idx = idx+1
	sum = 0

	while(idx>0):
		sum += fenwickTree[idx]
		idx -= idx & (-idx)
	return sum

def updateBIT(fenwickTree, n, val, idx, K):
	idx = idx+1

	while(idx<=n):
		fenwickTree[idx] += val
		#get next index
		idx += idx &(-idx)

def buildFenwick(fenwickTree, n, freq, K):

	for idx in range(n):
		updateBIT(fenwickTree, n ,freq[idx], idx, K)

if __name__ == '__main__':

	#freq = [1,2,3,4,5,6,7,8,9,10]
	freq = [2,1, 1, 5, 18, 16]

	n = len(freq)

	Q = 5

	l = [1, 3, 2, 5, 1]
	r = [5, 5, 4, 5, 4]

	K = [20, 36, 10, 13, 5]

	fenwickTree = [[0 for _ in range(Q+1)]]*(n+1)

	#print fenwickTree



	buildFenwick(fenwickTree, n, freq, K)
	'''
	NOPE

	print fenwickTree

	#get sum [0..5]
	print getSum(fenwickTree, n, 4) #fenwickTree, n, idx

	#Sum of [2...5]

	print getSum(fenwickTree, n, 4) - getSum(fenwickTree, n, 1)
	'''
