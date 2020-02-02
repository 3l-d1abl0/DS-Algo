# Dynamic programming implementation of LCS problem
'''
qqzqasdfe -4
qzzqqasdfee -4

zzzzasdf
zxcvbasdf

rebel

reebel
rebel
'''

def check_steps(a, aLen, b, bLen):
	a_idx=0
	b_idx=0
	steps = 0
	while a_idx < aLen and b_idx < bLen:

		print a[a_idx], b[b_idx]

		if a[a_idx] == b[b_idx]:
			a_idx +=1
			b_idx +=1
		else:

			if a[a_idx-1] == b[b_idx]:
				print 'add ',a[a_idx-1]
				b_idx +=1 #addition to a
				steps +=1
			elif a[a_idx] == b[b_idx-1]:
				print 'del ',a[a_idx]
				a_idx +=1 #deleteion in a
				steps +=1
			else:
				return { 'status': False, 'steps': steps }
	print aLen, bLen
	print a_idx, b_idx
	return { 'status': True, 'steps': steps }



# Returns length of LCS for X[0..m-1], Y[0..n-1]
def lcs(X, Y, m, n):
	L = [[0 for x in xrange(n+1)] for x in xrange(m+1)]

	# Following steps build L[m+1][n+1] in bottom up fashion. Note
	# that L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1]
	for i in xrange(m+1):
		for j in xrange(n+1):
			if i == 0 or j == 0:
				L[i][j] = 0
			elif X[i-1] == Y[j-1]:
				L[i][j] = L[i-1][j-1] + 1
			else:
				L[i][j] = max(L[i-1][j], L[i][j-1])

	# Following code is used to print LCS
	index = L[m][n]

	# Create a character array to store the lcs string
	lcs = [""] * (index+1)
	lcs[index] = ""

	# Start from the right-most-bottom-most corner and
	# one by one store characters in lcs[]
	i = m
	j = n
	while i > 0 and j > 0:

		# If current character in X[] and Y are same, then
		# current character is part of LCS
		if X[i-1] == Y[j-1]:
			lcs[index-1] = X[i-1]
			i-=1
			j-=1
			index-=1

		# If not same, then find the larger of two and
		# go in the direction of larger value
		elif L[i-1][j] > L[i][j-1]:
			i-=1
		else:
			j-=1

	print "LCS of " + X + " and " + Y + " is " + "".join(lcs)
	lc = "".join(lcs)
	print lc
	print L[m][n]

	if abs(m-L[m][n]) > abs(n-L[m][n]):
		check_steps(lc, L[m][n], Y, n)


# Driver program
#X = "AGGTAB"
#X = "REBEL"
#Y = "REEBEL"

X ="qqzqasdfe"
Y ="qzzqqasdfee"
m = len(X)
n = len(Y)
#lcs(X, Y, m, n)

XtoY = check_steps(X,m, Y,n)
YtoX = check_steps(Y,n, X,m)

print XtoY
print YtoX

if XtoY['status'] is True and YtoX['status'] is True:
	 print "1 ",min(XtoY['steps'], YtoX['steps'])
elif XtoY['status'] is True :
	print "2 ",XtoY['steps']
elif YtoX['status'] is True:
	print "3 ",YtoX['steps']
else:
	print "Not possible"
