import numpy as np

b_matrix = [[2, 4, 4, 2, 2, 4, 4, 2],
            [1, 1, 2, 2, 1, 1, 2, 2],
            [1, 1, 1, 1, 2, 2, 2, 2],
            [1, 1, 1, 1, 1, 1, 1, 1]]

o_cubeVertices = ((2, 1, 1), (4, 1, 1), (4, 2, 1), (2, 2, 1),
                  (2, 1, 2), (4, 1, 2), (4, 2, 2), (2, 2, 2))

print(b_matrix)
o_cubeVertices = np.transpose(o_cubeVertices)
b_matrix = np.vstack([o_cubeVertices, [1, 1, 1, 1, 1, 1, 1, 1]])
print(b_matrix)
