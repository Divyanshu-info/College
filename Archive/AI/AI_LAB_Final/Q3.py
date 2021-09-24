r = int(input("Enter the number of rows :"))
a = 2 * r - 2
for i in range(0, r):
    for j in range(0, a):
        print(end=" ")
    a = a - 2
    for j in range(0, i + 1):
        print("* ", end="")
    print("")
