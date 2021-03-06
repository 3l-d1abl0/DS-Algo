# Python program to print all primes smaller than or equal to
# n using Sieve of Eratosthenes

def SieveOfEratosthenes(n):

    # Create a boolean array "prime[0..n]" and initialize
    #  all entries it as true. A value in prime[i] will
    # finally be false if i is Not a prime, else true.
    prime = [True for i in range(n+1)]
    p=2
    while(p * p <= n):

        # If prime[p] is not changed, then it is a prime
        if (prime[p] == True):

            # Update all multiples of p
            for i in range(p * 2, n+1, p):
                prime[i] = False
        p+=1
    lis =[]

    file = open("testfile.txt","w")
    # Print all prime numbers
    i=1;
    for p in range(2, n):
        if i==3200:
            break

        if prime[p]:
            print p,
            file.write("{},".format(p));
            i+=1

    file.close()
    print "i= {}".format(i)

# driver program
if __name__=='__main__':
    n = 1000000
    print "Following are the prime numbers smaller",
    print "than or equal to", n
    SieveOfEratosthenes(n)
