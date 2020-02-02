def findRotation(str):
    n= len(str)
    tmp = str+str
    for i in range(1,n):

        #subs = str[i:i+n]
        if str == tmp[i:i+n]:
            return i

    return n


if __name__ =="__main__":

    #str = "abc"
    str = "abab"
    print 'Min rotation : {}'.format(findRotation(str))
