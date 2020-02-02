# Write your code here
n,m = map(int, raw_input().split())
max_count = -1
max_val = -1
for i in range(n):
    str = raw_input()
    if int(str,2)>max_val:
        max_val = int(str,2)
        max_count = i+1
        #print int(str,2),' ',(i+1)

print max_count
