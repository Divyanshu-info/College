import threading as th
import time

class P(th.Thread):
    running = True 

    def __init__(self, n, Lfork, Rfork):
        th.Thread.__init__(self)
        self.index = n
        self.forkOnLeft = Lfork
        self.forkOnRight = Rfork

    def run(self):
        while(self.running):
            time.sleep(2)
            print (f"Philosopher {self.index} is hungry.\n", end="")
            self.dine()

    def dine(self):
        fork1, fork2 = self.forkOnLeft, self.forkOnRight
        while self.running:
            fork1.acquire()
            locked = fork2.acquire(False) 
            if locked: break
            fork1.release()
            fork1, fork2 = fork2, fork1
        else:
            return
        self.dining()
        fork2.release()
        fork1.release()
 
    def dining(self):			
        print (f'Philosopher {self.index} starts eating. \n', end="")
        time.sleep(1)
        print (f'Philosopher {self.index} finishes eating and leaves to think.\n', end="")

def main():
    forks = [th.Semaphore() for _ in range(5)] 
    philosophers= [P(i, forks[i%5], forks[(i+1)%5]) for i in range(5)]

    P.running = True
    for p in philosophers: p.start()
    time.sleep(5)
    P.running = False
    print ("We're about to Finish.")
 

if __name__ == "__main__":
    main()