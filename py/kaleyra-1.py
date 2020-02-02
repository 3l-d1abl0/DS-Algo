def isNext(a, b):

    if a== "r" and b=="g":
        return True
    elif a == "g" and b=="b":
        return True
    elif a == "b" and b== "r":
        return True
    else:
        return False

t = input()
#print(t)
for case in range(t):

    n = input()
    #print (n)
    word = str(raw_input())

    if n< 3:
        print('0')
    else:
        sum =0
        for i in range(n-2):

            for j in range(i+1,n):

                if isNext(word[j-1], word[j]):
                    if j-i+1 >=3:
                        sum +=1
                        print(word[i:j+1])
                else:
                    break

        print (sum)

'''
5
3
rgb
4
brgb
2
rg
1
b
16
rgbrbbrgbgbrgrgb
'''
