from multiprocessing import Process, Queue

Q = Queue()


def my_func(a):
    Q.put(a*a)


p1 = Process(target=my_func, args=(3,))
p1.start()
print(Q.get())
p1.join()
