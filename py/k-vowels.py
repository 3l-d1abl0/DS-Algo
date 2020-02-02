MAX_CHARS = 26
 
# This function calculates number of unique characters
# using a associative array count[]. Returns true if
# no. of characters are less than required else returns
# false.
def isValid(vow, k):
    val = 0
    for key in vow :
        if vow[key] >0:
            val+=1
 
    # Return true if k is greater than or equal to val
    return (k >= val)
 
# Finds the maximum substring with exactly k unique characters
def kUniques(st,N,K):
    '''
    u = 0   # number of unique characters
    n = len(s)
 
    # Associative array to store the count
    count = [0] * MAX_CHARS
 
    # Tranverse the string, fills the associative array
    # count[] and count number of unique characters
    for i in xrange(n):
        if count[ord(s[i])-ord('a')] == 0:
            u += 1
        count[ord(s[i])-ord('a')] += 1
 '''
    if K==0:
        print N
        return
    # If there are not enough unique characters, show
    # an error message.
    if N < K:
        print "-1"
        return
 
    # Otherwise take a window with first element in it.
    # start and end variables.
    curr_start = 0
    curr_end = 0
 
    # Also initialize values for result longest window
    max_window_size = 1
    max_window_start = 0
 
    # Initialize Vowels
    vow = {'a': 0, 'e': 0, 'i': 0, 'o':0, 'u':0}
 
    if st[0].lower() in vow:
        vow[st[0].lower()]+=1
 
                # Start from the second character and add
                # characters in window according to above
    # explanation
    for i in xrange(1,N):

        if st[i].lower() in vow:
            vow[st[i].lower()]+=1

        curr_end+=1
 
        # If there are more than k unique characters in
        # current window, remove from left side
        while not isValid(vow, K):
            if st[curr_start].lower() in vow:
                vow[st[curr_start].lower()] -= 1
            #count[ord(s[curr_start])-ord('a')] -= 1
            curr_start += 1
        ''''
        while not isValid(vow, K):
        pass
            if st[curr_start].lower() in vow:
                vow[st[curr_start].lower()] -= 1
            curr_start += 1
        '''

        # Update the max window size if required
        if curr_end-curr_start+1 > max_window_size:
            max_window_size = curr_end-curr_start+1
            max_window_start = curr_start
 
    #print "Max substring is : " + st[max_window_start:max_window_start+max_window_size-1] \
            + " with length " + str(max_window_size)
    print max_window_size
 
# Driver function

T = int(raw_input())
for _ in range(T):

    N,K = map(int, raw_input().split())
    st = raw_input()

    #print N,K
    #print st
    #print '--------------'
    kUniques(st,N,K)
