def comb(m, n):
    res = 1 
    for i in range(1, n + 1):
        res *= m - n + i 
        res /= i 
    return res


n, l, k = int(input()), input().split(), int(input()) 
pos, x = comb(n, k), sum([1 for i in l if i == "a"]) 
print("%.4f" % ((pos - comb(n - x, k)) / pos))
