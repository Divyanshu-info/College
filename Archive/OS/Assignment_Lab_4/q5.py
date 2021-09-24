import random, time
from multiprocessing import Process, Lock, Semaphore, Array, Value


def Producer(lock, empty, full, buffer, to_produce, BUFFER_SIZE, numProducer, timeout):
    while(True and time.time() < timeout):
        empty.acquire()
        lock.acquire()
        print(f'Producer {numProducer} entering the critical region')
        Value = random.randint(1, 1000)
        buffer[to_produce.value] = Value
        print (f'Producer {numProducer} produced the value {Value} inserted it in position {to_produce.value}')
        to_produce.value = (to_produce.value + 1) % BUFFER_SIZE
        lock.release()
        print (f'Producer {numProducer} leaving the critical region.')
        full.release()
        ran1 = random.randint(0,5)
        print (f'Producer {numProducer} sleeping for {ran1}')
        time.sleep(ran1)
    return

def Consumer(lock, empty, full, buffer, to_consume, BUFFER_SIZE, numConsumer, timeout):
    while(True and time.time() < timeout):
        full.acquire()
        lock.acquire()
        print (f'Consumer {numConsumer} entering the critical region.')
        valor = buffer[to_consume.value]
        print (f'Consumer {numConsumer} consumed the value {valor} in position {to_consume.value}.')
        to_consume.value = (to_consume.value + 1) % BUFFER_SIZE
        lock.release()
        print( f'Consumer {numConsumer} leaving the critical region.')
        empty.release()
        ran2 = random.randint(0,5)
        print (f'Consumer {numConsumer} sleeping for {ran2} seconds.')
        time.sleep(ran2)
    return


if __name__ == '__main__': 
    exe = input("Input Execution time : ")
    pro = input("Input no of producers : ")
    con = input("Input no of consumers : ")
    
    BUFFER_SIZE = 5                    
    buffer = Array('i', BUFFER_SIZE)   
    lock = Lock()                      
    empty = Semaphore(BUFFER_SIZE)     
    full = Semaphore(0)                
    to_consume = Value('i', 0)         
    to_produce = Value('i', 0)         
    timeout = time.time() + int(exe)   
    producers = []                     
    consumers = []                     

    for i in range (int(pro)):
        Process(target = Producer, args=(lock, empty, full, buffer, to_produce, BUFFER_SIZE, i, timeout)).start()
    
    for j in range (int(con)):
        Process(target = Consumer, args=(lock, empty, full, buffer, to_consume, BUFFER_SIZE, j, timeout)).start()
    
    while(True):
        if(time.time() > timeout):
            quit()






