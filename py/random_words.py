
T = int(raw_input())


ll =[]
while (T!=0):
	ll.append(raw_input().split())
	T-=1

ll.sort()
ll.sort(key=len, reverse=False)

for p in ll: print p