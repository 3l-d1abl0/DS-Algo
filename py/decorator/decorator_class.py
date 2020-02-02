class decorator_class(object):

    def __init__(self, original_function):
        self.original_function = original_function

    def __call__(self, *args, **kwargs):
        print 'Call Method Before {}'.format(self.original_function.__name__)
        return self.original_function(*args, **kwargs)




@decorator_class
def display(first_name, last_name):
    print 'Dispaly {} {}'.format(first_name, last_name)

display('John', 'Doe')
