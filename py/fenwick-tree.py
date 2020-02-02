def getSum(fenwickTree, n, idx):

	idx = idx+1
	sum = 0

	while(idx>0):
		sum += fenwickTree[idx]
		idx -= idx & (-idx)
	return sum

def updateBIT(fenwickTree, n, val, idx):
	idx = idx+1

	while(idx<=n):
		fenwickTree[idx] += val
		#get next index
		idx += idx &(-idx)

def buildFenwick(fenwickTree, n, freq):

	for idx in range(n):
		updateBIT(fenwickTree, n ,freq[idx], idx)

if __name__ == '__main__':

	freq = [1,2,3,4,5,6,7,8,9,10]

	n = len(freq)

	fenwickTree = [0]*(n+1)

	buildFenwick(fenwickTree, n, freq)

	print fenwickTree

	#get sum [0..5]
	print getSum(fenwickTree, n, 4) #fenwickTree, n, idx

	#Sum of [2...5]

	print getSum(fenwickTree, n, 4) - getSum(fenwickTree, n, 1)
