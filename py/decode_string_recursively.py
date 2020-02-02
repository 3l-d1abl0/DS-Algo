from queue_stack import Stack

def decode_str(str):

    l = str.__len__()

    int_stack = Stack()
    str_stack = Stack()

    for i in range(l):

        if str[i] >='0' and str[i] <='9':
            num =0
            while( str[i]>='0' and str[i]<='9'):
                num = num*10 + (ord(str[i])-ord('0'))
                i+=1

            int_stack.push(num)


        elif str[i]=='(': #push into char stack and the int multiplier

            if str[i-1]>='0' and str[i-1]<='9':
                str_stack.push('(')
            else:
                int_Stack.push(1)
                str_stack.push(')')

        elif str[i]==')':   #process

            multiplier = int_stack.top()
            int_stack.pop()
            new_str =''

            while(len(str_stack)!=0 and str_stack.top()!='('):
                new_str = str_stack.top() + new_str
                str_stack.pop()

            str_stack.pop() #popping the (

            replicated_str=''
            for j in range(multiplier):
                replicated_str += new_str

            for j in range(len(replicated_str)):
                str_stack.push(replicated_str[j])

        else:   #normal alphabets, just push them
            str_stack.push(str[i])

    print(str_stack)

if __name__ == '__main__':

    #str = "10(a25(bc))"
    str = "3(b2(ca))"
    #str = "2(ab)"
    print(decode_str(str))
