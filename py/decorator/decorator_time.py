import time


def decorator_timing(original_function):

    def wrapper(number):

        t1 = time.time()
        original_function(number)
        t2 = time.time()

        print 'Time took for Function : {} '.format( (t2-t1) )

    return wrapper



@decorator_timing
def my_function(n):

    num_list = []
    for num in range(n):
        if num%2==0:
            num_list.append(num)

        print 'Even number upto {} : {}'.format(n, num_list)



my_function(10000)
