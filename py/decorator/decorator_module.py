def my_decorator(original_function):

    def wrapper(*args, **kwargs):

        num =10
        if num %2==0:
            print 'Even'
        else:
            print 'Odd'

        original_function(*args, **kwargs)
        
    return wrapper
