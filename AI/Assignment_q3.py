print("Input Order of Matrix\t")
N, M = int(input()), int(input())
print(f"Order is {N}, {M}")

Matrix = list()
MatrixT = [[0 for i in range(N)] for j in range(M)]

for i in range(N):
    tmp = []
    for j in range(M):
        tmp.append(int(input(f"Input {i+1},{j+1} \t")))
    Matrix.append(tmp)

print("\nInput Matrix")
for i in Matrix:
    print(i)
print()
print("Transposed Matrix")
for i in range(N):
    for j in range(M):
        MatrixT[j][i] = Matrix[i][j]

for i in MatrixT:
    print(i)
