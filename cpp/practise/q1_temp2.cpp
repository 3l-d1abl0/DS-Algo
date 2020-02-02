def solution (A, K, N):
    

    count = 0
    
    for i in xrange(N):
        stack = []
        for j in xrange(N):
            if len(stack) == 0 or stack[-1][2] == A[i][j]:
                stack.append((i, j, A[i][j]))
            else:
                if j - stack[-1][1] <= K:
                    count += 1 
                    stack.pop()
                    
    return count                
                    
T = input()
for _ in xrange(T):
    N, K = map(int, raw_input().split())
    A = []
    for _ in xrange(N):
        A.append(raw_input().split())
    out_ = solution(A, K, N)
    print out_