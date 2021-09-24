import random

lst = [random.randrange(1, 100) for _ in range(20)]
print("Original List")
print(lst)
print()
print("Modified List")
for i in lst:
    if i%5 == 0:
        lst.remove(i)
print(lst)
