# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")

def solution(S):
    # write your code in Python 3.6
    #print (type(S))
    
    word_count = 0
    word_flag = False
    last_char = True
    for i in S:
        
        if i is '.' or i is '?' or i is '!':
            #sentense
            if word_flag is True :#or last_char is True:
                word_count +=1
                
            word_flag = False
            last_char = True
        else:
            
            if (i>='a' and i<='z') or (i>='A' and i<='Z'):
                word_flag = True
                last_char = False
                
    return word_count
    pass