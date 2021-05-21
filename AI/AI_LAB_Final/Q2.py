tup = tuple(list(map(int, input("Input values\t").split())))

K = int(input("Input value of k\t"))

res = []
tup = list(tup)
temp = sorted(tup)

for idx, val in enumerate(temp):
    if idx < K or idx >= len(temp) - K:
        res.append(val)
res = tuple(res)

print("Values are  " + str(res))
