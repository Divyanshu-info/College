import random

lst = [random.randrange(1, 100) for _ in range(10)]
print("Original List")
print(lst)
print("Inserting Five Elements")
for i in range(5):
    lst.insert(0,random.randrange(1, 100))
print("Modified List")
print(lst)
print("Popping Three Elements")
for i in range(3):
    lst.pop()
print("Modified List")
print(lst)
print("Deleteing third to fifth Elements")
del lst[2:5]
print("Modified List")
print(lst)
print("Extending 5 items in List")
for _ in range(5):
    lst.extend([random.randint(1, 100)])
print("Modified List")
print(lst)
