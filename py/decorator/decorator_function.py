def decorator_function(original_function):

    def wrapper_function(*args, **kwargs):
        print 'Executing Wrapper {}'.format(original_function.__name__)
        return original_function(*args, **kwargs)

    return wrapper_function

#@decorator_function
def display(first_name, last_name):
    print 'Dispaly {} {}'.format(first_name, last_name)

#display('John', 'Doe')


decorated_display = decorator_function(display)

decorated_display('David', 'Jhones')
