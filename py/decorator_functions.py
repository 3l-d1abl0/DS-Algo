def decorator_func(func):
    def wrapper_func():
        print('--before Function--')
        func()
        print('--after Function--')

    return wrapper_func

#@decorator_func
def say_hello():
    print('Hello World')


def decorator_X(func):
    def wrapper_func():
        print('-- BeginX--')
        func()
        print('--EndX--')

    return wrapper_func

def decorator_Y(func):
    def wrapper_func():
        print('--BeginY--')
        func()
        print('--BeginY--')

    return wrapper_func

#@decorator_X
#@decorator_Y
def say_hi():
    print('--Hi--')

if __name__ == "__main__":

    #say_hello()
    hello = decorator_func(say_hello)
    hello()



    #say_hi()
    hi = decorator_Y(decorator_X(say_hi))
    hi()
