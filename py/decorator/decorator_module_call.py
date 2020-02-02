from decorator_module import my_decorator

@my_decorator
def display(first_name, last_name):
    print 'Display : {} {} '.format(first_name, last_name)


display('Logan', '.')
