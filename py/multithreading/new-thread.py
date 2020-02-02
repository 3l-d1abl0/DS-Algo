import threading


def uf(count):
    print 'Hello World ! ', count
    return

def one_thread():
    t = threading.Thread(target=uf)
    print t
    t.start()

def many_thread():
    threads =[]
    for i in range(5):
        t= threading.Thread(target=uf, args=[i])
        print t
        threads.append(t)
        t.start()

if __name__ == "__main__":
    #one_thread()
    many_thread()
    print '==========='