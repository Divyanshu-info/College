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
    glColor3f(1.0, 0.0, 0.0)
    for cubeEdge in cubeEdges:
        for cubeVertex in cubeEdge:
            glVertex3fv(cubeVertices[cubeVertex])
    glEnd()


def plot_points():

    glColor3f(0.0, 1.0, 0.0)

    glPointSize(2.0)

    glBegin(GL_POINTS)

    for x in range(0, 10):
        glColor3f(0.0, 1.0, 0.0)
        glVertex3d(x, 0, 0)
        glColor3f(0.0, 1.0, 0.0)
        glVertex3d(0, x, 0)
        glColor3f(0.0, 1.0, 0.0)
        glVertex3d(0, 0, x)

    glEnd()


def translated_cube():
    t4x4 = [[1, 0, 0, 2], 
            [0, 1, 0, 0],
            [0, 0, 1, 1],
            [0, 0, 0, 1]]
    
    sh4x4 = [[2, 0, 0, 0],
             [0, 2, 0, 0],
             [0, 0, 2, 0], 
             [0, 0, 0, 1]]
    
    t2_4x4 = [[1, 0, 0, -2],
              [0, 1, 0, 0],
              [0, 0, 1, -1],
              [0, 0, 0, 1]]
    
    b_matrix = np.transpose(o_cubeVertices)
    b_matrix = np.vstack([b_matrix, [1, 1, 1, 1, 1, 1, 1, 1]])
    f_matrix = np.matmul(np.matmul(np.matmul(t4x4, sh4x4), t2_4x4), b_matrix)
    f_matrix = f_matrix[0:3][:]
    f_matrix = f_matrix.transpose()
    pts = np.array(f_matrix)    
    print(pts)
    return pts


def main():
    pg.init()
    display = (800, 800)
    pg.display.set_mode(display, DOUBLEBUF | OPENGL)

    gluPerspective(45, (1), 0.1, 50.0)
    #glTranslatef(0, 0, -30)
    gluLookAt(10, 10, 10, 0, 0, 0, 0,1, 0)
    plot_points()
    wireCube(o_cubeVertices, o_cubeEdges)
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
