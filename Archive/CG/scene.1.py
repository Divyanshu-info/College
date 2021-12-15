from OpenGL.GLU import *
from OpenGL.GL import *
import pygame
from pygame.locals import *
pygame.init()
from PIL import Image
import numpy
import time

def read_texture(filename):
    """
    Reads an image file and converts to a OpenGL-readable textID format
    """
    img = Image.open(filename)
    img_data = numpy.array(list(img.getdata()), numpy.int8)
    textID = glGenTextures(1)
    glBindTexture(GL_TEXTURE_2D, textID)
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1)
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP)
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP)
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT)
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT)
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST)
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST)
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL)
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB,
                 img.size[0], img.size[1], 0, GL_RGB, GL_UNSIGNED_BYTE, img_data)
    return textID


def Draw_earth(texture):
    qobj = gluNewQuadric()
    gluQuadricTexture(qobj, GL_TRUE)
    glEnable(GL_TEXTURE_2D)
    glBindTexture(GL_TEXTURE_2D, texture)
    gluSphere(qobj, 1, 50, 50)
    gluDeleteQuadric(qobj)
    glDisable(GL_TEXTURE_2D)


vertices = (
    (1, -1, -1),  # 0
    (1, 1, -1),  # 1
    (-1, 1, -1),  # 2
    (-1, -1, -1),  # 3
    (1, -1, 1),  # 4
    (1, 1, 1),  # 5
    (-1, 1, 1),  # 6
    (-1, -1, 1)  # 7
)

edges = (
    (0, 1),
    (0, 3),
    (0, 4),
    (1, 2),
    (1, 5),
    (2, 3),
    (2, 6),
    (3, 7),
    (4, 5),
    (4, 7),
    (5, 6),
    (6, 7)
)

surfaces = (
    (0, 1, 2, 3),
    (3, 7, 4, 0),
    (2, 3, 7, 6),
    (1, 2, 5, 6),
    (4, 5, 6, 7),
    (0, 1, 4, 5)
)


def plot_points():

    glColor3f(0.0, 1.0, 0.0)

    glPointSize(2.0)

    glBegin(GL_POINTS)

    for x in range(0, 10):
        glVertex3d(x, 0, 0)
        glVertex3d(0, x, 0)
        glVertex3d(0, 0, x)

    glEnd()


def start(FOV, width, height):
    gluPerspective(FOV, (width / height), 0.1, 50.0)

    # Put any initializing code for the GAME not PROGRAM below this line
    glTranslatef(0, 0, -4)
    glRotatef(25, 1, 0, 0)


def logic():
    t = time.time() % 1000
    angle = numpy.angle(t*90, True)
    glRotate(0.1, 0, 1, 0)
    

    # Put all rendering code between glClear() and pygame.display.flip()
    

    # Fill cube
    
    
    # glBegin(GL_QUADS)

    # for surface in surfaces:
    #     for vertex in surface:
    #         glColor3fv((1, 0, 0))
    #         glVertex3fv(vertices[vertex])

    # glEnd()

    # # Outline cube
    # glBegin(GL_LINES)

    # for edge in edges:
    #     for vertex in edge:
    #         glColor3fv((1, 1, 1))
    #         glVertex3fv(vertices[vertex])

    # glEnd()

    


# Change the code below only if absolutely needed!!
def main():
    width = 800
    height = 600
    win = pygame.display.set_mode((width, height), DOUBLEBUF | OPENGL)
    pygame.display.set_caption("Boilerplate Title")

    clock = pygame.time.Clock()
    running = True
    FPS = 90  # Frames Per Second
    FOV = 90  # Field Of Vision (in degrees)

    start(FOV, width, height)
    texture = read_texture("earth.jpg")
    while running:
        clock.tick(FPS)

        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False

        
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT)
        plot_points()
        Draw_earth(texture)
        logic()
        pygame.display.flip()


if __name__ == "__main__":
    main()
    pygame.quit()
    quit()
