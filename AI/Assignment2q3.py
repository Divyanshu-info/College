def add(x, y):
    return x + y


def subtract(x, y):
    return x - y


def multiply(x, y):
    return x * y


def divide(x, y):
    return x / y


while True:
    num1 = float(input("Enter first number:\t"))
    num2 = float(input("Enter second number:\t"))

    print("1.Add")
    print("2.Subtract")
    print("3.Multiply")
    print("4.Divide")

    choice = input()
    if choice not in ['1', '2', '3', '4']:
        print("Invalid Input")
        continue
    if choice == '1':
        print(f"{num1} + {num2} = {add(num1, num2)}")

    elif choice == '2':
        print(f"{num1} - {num2} = {subtract(num1, num2)}")

    elif choice == '3':
        print(f"{num1} x {num2} = {multiply(num1, num2)}")

    elif choice == '4':
        try:
            print(f"{num1} / {num2} = {divide(num1, num2)}")
        except:
            print("Can not divide by 0")
