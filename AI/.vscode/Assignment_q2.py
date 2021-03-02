def fac(no):
    if no == 1:
        return 1
    else:
        return fac(no-1)*no


no = int(input("Input No.\t"))
factorial = None

if no < 0:
    print("Factorial Doesn't Exist")
    quit()
elif no == 0:
    factorial = 1
else:
    factorial = fac(no)

print(f"Factorial is :\t{factorial}")
