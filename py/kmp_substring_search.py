
def aux_array_build(a):

    aux = [0] * len(a)

    j=0; i=1

    while(i < len(a)):

        if a[i] == a[j]:
            aux[i] = j+1
            i+=1;j+=1

        elif a[i]!=a[j] and j==0:
            aux[i] = 0
            i+=1
        else:
            j=aux[j-1]

    return aux


def kmp_search(patt, txt, aux):
    pat_len = len(patt)
    txt_len = len(txt)

    pat_idx = 0; txt_idx = 0
    idx_array = []

    while txt_idx < txt_len :

        if patt[pat_idx] == txt[txt_idx]:
            pat_idx +=1; txt_idx+=1
            if pat_idx == pat_len:
                idx_array.append(txt_idx)
                #continuing for other occurances as if not match was Found
                pat_idx = aux[pat_idx-1]
        elif patt[pat_idx] != txt[txt_idx] and pat_idx == 0:
            txt_idx +=1
        else:
            pat_idx = aux[pat_idx-1]

    print idx_array

    return idx_array


if __name__ == '__main__':

    '''Pattern - Txt'''
    #a = "abcdabca"
    #a = "ACABACACD"
    #a = "aabaabaaa"
    #a = "acacabacacabacacac"
    #a = "abcaby" txt = "abxabcabcaby"

    #a = "acabacacd" txt = "acfacabacabacacdk"
    a = "DAMN"
    txt= "THIS_IS_A_TEST_TEXT_AND_NOT_A_TEST_TEST_OK"

    aux_array = aux_array_build(a)

    print "For String : {}".format(a)
    print "For Aux ArrAY : {}".format(aux_array)

    idx = kmp_search(a, txt, aux_array)

    if len(idx) == 0:
        print "Pattern Not Found"
    else:
        for id in idx:
            print txt[id-len(a) : id]
