n1 = int(input())
arr = []
for i in range(n1):
    n, m = map(int, input().split())
    arr = []
    for j in range(n):
        arr.append(list(map(int, input().split())))
        print(arr)
    if n == 1 and m == 1:
        print("YES")
    else:
        i1 = 0
        i2 = 0
        a = arr[i1][i2]
        while True:
            if i1 == n-1 and i2 == m-1:
                print("YES")
            if arr[i1+1][i2] ==  a:
                i1+=1
                continue
            elif arr[i1][i2+1] == a:
                i2+=1
                continue
            else:
                print("NO")
                break
                
