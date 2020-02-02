'''
# Sample code to perform I/O:

name = input()         		 # Reading input from STDIN
print('Hi, %s.' % name)		 # Writing output to STDOUT

# Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
'''

def solve ( noOfQueriesP): #takes query input and processes them
    # your code ()
    pokemon = []
    mod = True
    for i in range(noOfQueriesP):
        Q, X = input().split(" ")

        if Q == 'A':
            pokemon.append(int(X)), mod = True
        elif Q == 'I':#increment
            for idx in range(len(pokemon)):
                pokemon[idx] += int(X)
        elif Q == 'D': #Decrement
            for idx in range(len(pokemon)):
                pokemon[idx] -= int(X)
        else:
            //P
            if mod == True:
                pokemon.sort()
                mod = False

            print(pokemon[int(X)-1])


noOfTestCasesQ = int(input())

while(noOfTestCasesQ > 0):
    noOfQueriesP = int(input())
    solve(noOfQueriesP)
    noOfTestCasesQ = noOfTestCasesQ - 1
