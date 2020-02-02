import bisect
n=input()
l={}
l=[input()]

for i in range(1,n):
    t=input()

    j=bisect.bisect_left(l,t)

    if j==len(l):
        l.append(t)
    else:
        l[j]=t

print n-len(l)
