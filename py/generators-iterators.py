#Iterators n Generators

class fibonacci:

    def __init__(self, max=1000000):
        self.a, self.b = 0, 1
        self.max = max

    def __iter__(self):
        # Return the iterable object (self)
        return self

    def next(self):
        # When we need to stop the iteration we just need to raise
        # a StopIteration exception
        if self.a > self.max:
            raise StopIteration

        # save the value that has to be returned
        value_to_be_returned = self.a

        # calculate the next values of the sequence
        self.a, self.b = self.b, self.a + self.b

        return value_to_be_returned

    def __next__(self):
        # For compatibility with Python3
        return self.next()


def iterators():
    fibonacci_numbers = fibonacci()
    #print fibonacci_numbers
    '''print fibonacci_numbers.next()
    '''

    for fib in fibonacci_numbers:
        print(fib)

    list = [1,2,3]
    for i in list:
        print(i)


    iter = list.__iter__()
    print iter.next()
    print iter.next()
    print iter

def getFibonacci(max):
    a, b = 0, 1
    while a < max:
        yield a
        a, b = b, a+b

def generators():
    '''
        Generators in Python are just another way of creating iterable objects
        and are usually used when you need to create iterable object quickly,
        without the need of creating a class and adopting the iteration protocol.
    '''

    # Create a generator of fibonacci numbers smaller than 1 million
    fibonacci_generator = getFibonacci(1000000)

    # print out all the sequence
    for fibonacci_number in fibonacci_generator:
        print(fibonacci_number)

    #wont work as all the values have been exhausted , it needs to be initialzed again
    #for fibonacci_number in fibonacci_generator:
    #    print(fibonacci_number)

    print('---')

    print list(fibonacci(1000000))




if __name__ == '__main__':

    #iterators()

    generators()
