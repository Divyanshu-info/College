import threading
import time


flag = [False, False]
turn = 0
line1 = 0
line2 = 0
def printstar(a,b):
	global line1, line2
	if a == 1:
		line1+=1
	if b == 1:
		line2+=1
	#print("\033[A")
	print("\r" + "Working on Process 1: " +  "*"*line1)
	print("\r" + "Working on Process 2: "+ "*"*line2, end="\033[A")

def process(pid):
	global flag, turn
	flag[pid] = True
	flag[pid-1] = False
	if flag[0] == True and turn == 0:
		#print("Working on Process 1")
		printstar(1,0)
		time.sleep(0.05)
		turn = 1 
	elif flag[1] == True and turn == 1:
		turn = 0
		#print("Working on Process 2")
		printstar(0,1)
		time.sleep(0.05)
		turn = 0

for i in range(100):
	thread1 = threading.Thread(target=process, args=(0,))
	thread2 = threading.Thread(target=process, args=(1,))

	thread1.start()
	thread1.join()

	thread2.start()
	thread2.join()
print("\033[2J\rExecution completed\n")
print("\r")
