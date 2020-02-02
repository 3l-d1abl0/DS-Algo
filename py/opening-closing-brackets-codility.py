# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")

def solution(S):
    # write your code in Python 3.6
    #print (type (S))
    s_len = len(S)
    left_b =0
    right_b =0
    
    left_list =[]
    right_list = []
    
    for i in S:
        if i is '(':
            left_b +=1
        left_list.append(left_b)
            
    for i in S[::-1]:
        if i is ')':
            right_b +=1
        right_list.append(right_b)
        
    right_list = right_list[::-1]
            
    right_list.append(0)
    
    #print (left_list)
    #print (right_list)
    
    for i in range(s_len):
        if left_list[i] == right_list[i+1]:
            #print (i+1)
            return i+1
            
        
    pass