import time


def timing_function(some_function):
    def wrapper():
        t1 = time.time()
        some_function()
        t2 = time.time()

        print("Time it took to rum the functions: "+str((t2-t1))+"\n")
    return wrapper


def my_function():
    num_list = []
    for num in range(0,10000):
        num_list.append(num)

    print("\n Sum of all the numbers: "+str(sum(num_list)))

@timing_function
def new_function():
    num_list = []
    for num in range(0,1000000):
        num_list.append(num)

    print("\n Sum of Numbers: "+str(sum(num_list)))

if __name__ == '__main__':

    wrapped_func = timing_function(my_function)
    wrapped_func()

    '''Decorator Version'''

    new_function()
