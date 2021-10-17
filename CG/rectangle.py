import numpy as np
import cv2
canvas = (1000, 1000, 1)
Box_coordinates = [[3, 5, 5, 3], [1, 1, 2, 2]]
Final_Box_coordinates = Adjusted_Box_coordinates = np.zeros((2, 4))

pivot_point = (5, 5)
theta = 45
shape = (1000, 1000)


def draw_coordinates():
    graph = np.zeros(shape, dtype="uint8")
    for i in range(10):
        for j in range(10):
            graph = cv2.add(graph, cv2.circle(graph, (i*100, j*100),
                                              radius=1, color=(255, 255, 255), thickness=-1))
    return graph


for i in range(2):
    temp = pivot_point[i]
    for j in range(4):
        Adjusted_Box_coordinates[i][j] = Box_coordinates[i][j] - temp

rotation_matrix = [[np.cos(45), np.cos(45)], [np.sin(45), np.cos(45)]]

Rotated_Box_coordinates = np.matmul(rotation_matrix, Adjusted_Box_coordinates)

for i in range(2):
    temp = pivot_point[i]
    for j in range(4):
        Final_Box_coordinates[i][j] = Rotated_Box_coordinates[i][j] + temp

canvas = np.zeros(shape, dtype="uint8")

point1 = int(Final_Box_coordinates[0][0] *
             100), int(Final_Box_coordinates[1][0]*100)
point2 = int(Final_Box_coordinates[0][2] *
             100), int(Final_Box_coordinates[1][2]*100)
print(point1, point2)
print(Final_Box_coordinates)



blue = (255, 0, 0)
cv2.rectangle(canvas, (300, 100), (500, 200), blue, -1)

cv2.rectangle(canvas, point1, point2, blue, -1)

cv2.imshow("title", mat=draw_coordinates() + canvas)
cv2.waitKey(0)
cv2.destroyAllWindows()
#x2 = ((x1 - x0) * cos(theta)) - ((y1 - y0) * sin(theta)) + x0
#y2 = ((x1 - x0) * sin(theta)) + ((y1 - y0) * cos(theta)) + y0
