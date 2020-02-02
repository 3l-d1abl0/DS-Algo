from time import time

def timing(func):

    def wrapper_func(*args, **kwargs):
        start = time()

        result = func(*args, **kwargs)

        end = time()
        print('Elasped time : {} '.format(end-start))
        return result

    return wrapper_func



@timing
def my_func(num):
    sum =0
    for i in range(num+1):
        sum +=1
    return sum



if __name__ == "__main__":

    print(my_func(5000000))
