def Fib(no):
    if no <= 1:
        return 0
    if no == 2:
        return 1
    n1 = Fib(no-1)
    n2 = Fib(no-2)
    n = n1 + n2
    return n


no = 10

print("Fibonacci Series is ", end='')
for i in range(1, no+1):
    series = Fib(i)
    print(series, end=' ')
print()
