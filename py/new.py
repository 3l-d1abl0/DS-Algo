

a = [3,5,1,5,1]

n = len(a)
k=2


prod =-1
for i in range(0, n-k+1):

	print 'prod = {}'.format(a[i] * a[k-1+i])

	if prod> a[i]*a[k-1+i]:
		prod = prod
	else:
		prod = prod> a[i]*a[k-1+i]


print 'ANS {}'.format(prod)