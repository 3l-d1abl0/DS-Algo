import math

if __name__ == '__main__':
    T = int(raw_input())

    for _ in range(T):
        N = int(raw_input())
        print int(math.floor(math.log(N*2+1)/math.log(3)))
