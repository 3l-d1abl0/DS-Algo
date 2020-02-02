def interleave(len1, idx, new_str, str1, str2):

    #print '-> {} {}'.format(str1, str2)
    #print '==> {} '.format(new_str)

    if str1 is  '' and str2 is '':
        #print 'XXXXX {} '.format(new_str)
        print ''.join(new_str)

    if str1 is not '':
        #print str1[:1]
        #print new_str[idx]
        new_str[idx] = str1[:1]
        interleave(len1, idx+1, new_str, str1[1:], str2)

    if str2 is not '':
        new_str[idx] = str2[:1]
        interleave(len1, idx+1, new_str, str1, str2[1:])

def interleaveString(str1, str2):

    len1 = len(str1)
    len2 = len(str2)

    new_str = ['']*(len1+len2)
    #print new_str

    interleave(len1+len2, 0, new_str, str1, str2)

if __name__ =="__main__":


    string1 = raw_input()
    string2 = raw_input()

    print 'interleaving {} & {}'.format(string1, string2)
    interleaveString(string1, string2)
