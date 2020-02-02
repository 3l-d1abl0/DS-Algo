# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")

def solution(A, B):
    # write your code in Python 3.6
    A1 = str(A)
    a_len = len(A1)
    
    B1 = str(B)
    b_len = len(B1)
    C =[]
    a_idx =0
    b_idx =0
    while a_idx< a_len and b_idx < b_len:
        C.append(A1[a_idx])
        a_idx+=1
        C.append(B1[b_idx])
        b_idx+=1
    
    if a_idx<a_len:
        while a_idx<a_len:
            C.append(A1[a_idx])
            a_idx+=1
            
    if b_idx < b_len:
        while b_idx< b_len:
            C.append(B1[b_idx])
            b_idx+=1
    #print (A)
    #print (B)
    
    
    C = int("".join(map(str, C)))
    #print (C)
    if C > 100000000:
        return -1
    else:
        return C
    
    pass