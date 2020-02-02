
class MyClass(object):

    #called when with block starts
    def __enter__(self):
        print('We have entered "with"')
        return self

    #called when with block exits
    def __exit__(self, type, value, traceback):
        print('We are leaving "with"')
        print('error type: {0}'.format(type))
        print('error value: {0}'.format(value))
        print('error Traceback: {0}'.format(traceback))

    def sayhi(self):
        print('Hi, instance %s '%(id(self)))
        5/0


with MyClass() as cc:
    cc.sayhi()

print("--Right after the 'with' Block--")
