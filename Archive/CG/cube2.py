import pygame as pg
from pygame.locals import *
import numpy as np

from OpenGL.GL import *
from OpenGL.GLU import *

o_cubeVertices = ((2, 1, 1), (4, 1, 1), (4, 2, 1), (2, 2, 1),
                  (2, 1, 2), (4, 1, 2), (4, 2, 2), (2, 2, 2))
o_cubeEdges = ((0, 1), (0, 3), (0, 4), (1, 2), (1, 5), (2, 6),
               (2, 3), (3, 7), (4, 5), (4, 7), (5, 6), (6, 7))


def wireCube(cubeVertices, cubeEdges):
    glBegin(GL_LINES)
    for cubeEdge in cubeEdges:
        for cubeVertex in cubeEdge:
            glVertex3fv(cubeVertices[cubeVertex])
    glEnd()


def plot_points():

    glColor3f(0.0, 1.0, 0.0)

    glPointSize(2.0)

    glBegin(GL_POINTS)

    for x in range(0, 10):
        glVertex3d(x, 0, 0)
        glVertex3d(0, x, 0)
        glVertex3d(0, 0, x)

    glEnd()


def translated_cube():
    
    alpha = np.radians(15.5)
    beta = np.radians(36.69)

    t4x4 = [[1, 0, 0, 2],
            [0, 1, 0, 0],
            [0, 0, 1, 1],
            [0, 0, 0, 1]]

    Rxa = [[1, 0, 0, 0],
            [0, np.cos(alpha), np.sin(alpha), 0],
            [0, -np.sin(alpha), np.cos(alpha), 0],
            [0, 0, 0, 1]]

    Ryb = [[np.cos(beta), 0, -np.sin(beta), 0],
           [0, 1, 0, 0],
           [np.sin(beta), 0, np.cos(beta), 0],
           [0, 0, 0, 1]]

    Rzt = [[np.cos(np.radians(45)), -np.sin(np.radians(45)), 0, 0],
           [np.sin(45), np.cos(45), 0, 0],
           [0, 0, 1, 0],
           [0, 0, 0, 1]]

    Ryb2 = [[np.cos(beta), 0, np.sin(beta), 0],
           [0, 1, 0, 0],
           [-np.sin(beta), 0, np.cos(beta), 0],
           [0, 0, 0, 1]]

    Rxa2 = [[1, 0, 0, 0],
           [0, np.cos(alpha), -np.sin(alpha), 0],
           [0, np.sin(alpha), np.cos(alpha), 0],
           [0, 0, 0, 1]]

    t2_4x4 = [[1, 0, 0, -2],
              [0, 1, 0, 0],
              [0, 0, 1, -1],
              [0, 0, 0, 1]]

    b_matrix = np.transpose(o_cubeVertices)
    
    b_matrix = np.vstack([b_matrix, [1, 1, 1, 1, 1, 1, 1, 1]])
    print(b_matrix)
    t_matrix = np.matmul(t4x4, np.matmul(Rxa, np.matmul(Ryb, np.matmul(Rzt, np.matmul(Ryb2, np.matmul(Rxa2, t2_4x4))))))
    
    f_matrix = np.matmul(t_matrix, b_matrix)
    f_matrix=f_matrix[0:3][:]
    f_matrix=f_matrix.transpose()
    pts=np.array(f_matrix)
    print(pts)
    return pts


def main():
    pg.init()
    display=(800, 800)
    pg.display.set_mode(display, DOUBLEBUF | OPENGL)

    gluPerspective(45, (1), 0.1, 50.0)
    #glTranslatef(0, 0, -20)
    gluLookAt(10, 10, 10, 0, 0, 0, 0,1, 0)
    plot_points()
    glColor3f(1.0, 0.0, 0.0)
    wireCube(o_cubeVertices, o_cubeEdges)
    glColor3f(0.0, 0.0, 1.0)
    wireCube(translated_cube(), o_cubeEdges)
    
    while True:
        for event in pg.event.get():
            if event.type == pg.QUIT:
                pg.quit()
                quit()

        pg.display.flip()
        pg.time.wait(100)
        

if __name__ == "__main__":
    main()
