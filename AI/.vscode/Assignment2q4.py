import random

num = int(input("Enter no. "))

if num > 1:
    for i in range(2, num+1//2):
        if ((num % i) == 0):
            print(num, "is not a prime number")
            break
    else:
        print(num, "is a prime number")
else:
	print(num, "is not a prime number")
