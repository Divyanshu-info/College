import os

pid = os.fork() 

if pid > 0: 
    print("\nSystem is in parent process")	
    print("Process ID:", os.getpid())
    info = os.waitpid(pid, 0)
    if os.WIFEXITED(info[1]): 
        code = os.WEXITSTATUS(info[1])
        print("Child's exit code:", code)
else:
    print("\tSystem is in child process")
    print("\tProcess ID:", os.getpid())
    print("\tHello! World")
    print("\tChild exiting..")
    os._exit(os.EX_OK)
