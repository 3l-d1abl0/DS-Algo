

class MyError(Exception):

    def __init__(self, *args):
        print 'Calling init'
        if args:
            self.message = args[0]
        else:
            self.message = ''

    def __str__(self):
        print 'calling str'
        if self.message:
            return "Here is MyError Exception with a message: {0}".format(self.message)
        else:
            return "Here is a MyError Exception"


if __name__ == '__main__':
    raise MyError
    #raise MyError('Houston, we have a Problem')
