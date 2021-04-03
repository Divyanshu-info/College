import _thread
import time
DELAY=1
nprocesses=int(input("Input No. of Processes : ")) 
choosing=[False]*nprocesses
number=[0]*nprocesses
critical=[False]*nprocesses
time_t = 0

def max_number():
    global choosing
    global number
    max=-1
    for i in number:
        if(i>max):
            max=i
    return max

def Comparision_tuples(a,b,c,d):
    if(a<c):
        return True
    elif (a==c and b<d):
        return True
    return False

def lock(i):
    global choosing
    global number
    choosing[i]=True
    number[i]=max_number()+1
    choosing[i]=False
    for j in range(nprocesses):
        while(choosing[j]):
            continue
        while(number[j]!=0 and Comparision_tuples(number[j],j,number[i],i)):
            continue

def unlock(i):
    global choosing
    global number
    number[i]=0

def run_thread(i):
    global time_t
    while(True):

        lock(i)
        print ("\nTime: " + str(time_t))
        print ("Thread " + str (i) + " in critical section")
        critical[i]=True
        print(critical)
        critical[i]=False
        time.sleep(DELAY)

        unlock(i)

        print ("Thread " + str (i) + " out of critical section\n")
        #time.sleep(DELAY)

def monitorear():
    global time_t
    while(True):
        time_t+=1
        time.sleep(1)
        
def bakery():
    for i in range(nprocesses):
        _thread.start_new_thread( run_thread, (i,) )
bakery()
monitorear()