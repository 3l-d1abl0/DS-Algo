def isPalindrome(str):

    # Run loop from 0 to len/2
    print str
    for i in xrange(0, len(str)/2):
        if str[i] != str[len(str)-i-1]:
            return False

    #print 'returning True'
    return True

N= int(raw_input())

for i in xrange(N):
    str = raw_input()
    str_len = len(str)

    flag = False
    for id in xrange(1,str_len):
        #print str[:id], str[id:]
        if isPalindrome(str[id:]+str[:id]) is True:
            flag = True
            break

    if flag is True:
        print 'YES'
    else:
        print 'NO'
