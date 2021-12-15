"""
Opengl project demonstrating Lighting and Smooth Shading
Using GLU primitive shapes
Written in python because C++ did not work for me
PyOpengl and Pygame are the anly two requirements to run the program

********CONTROLS********
* Press UP ARROW or DOWN ARROW to adjust the slices and stacks of the primitive shapes .
                [Controles the smoothness of the object]
* A,W,S,D to move around the viewport.
* Mouse Scroll to zoom in and out.
* X to enter X-ray mode [wireframe mode].
************************

****************CREDITS****************
* This was a team project            
* Written by SUHAS.K.SHETTY          
* Together with HARIHARAN.PARTHIBAN  
* Quarantine 2020                    
***************************************
"""

import time
import pygame
from pygame.locals import *

from OpenGL.GL import *
from OpenGL.GLU import *

import random
from PIL import Image
import numpy
import time
# GLUT doesn't work

# color and other variables for easy modification
planetColor = (0.0, 0.6, 0.7)
partialDiskColor = (0.7, 0.4, 0.0)

# solid Draw


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

def draw(texture):

    t = time.time() % 1000
    angle = t*90/4

    # planet
    glPushMatrix()

    glRotatef(angle, 0, 0, 1)
    qobj = gluNewQuadric()
    gluQuadricTexture(qobj, GL_TRUE)
    glEnable(GL_TEXTURE_2D)
    glBindTexture(GL_TEXTURE_2D, texture)
    gluSphere(qobj, 1, 50, 50)
    gluDeleteQuadric(qobj)
    glDisable(GL_TEXTURE_2D)
    #gluSphere(qobj, 2, 50, 50)  # quads, radius, slices, stacks
    glPopMatrix()


def draw_moon(texture):

    t = time.time() % 1000
    angle = t*13.2/16
    # planet

    glPushMatrix()
    glTranslate(2*numpy.cos(angle),
                2*numpy.sin(angle), 0)
    glRotatef(numpy.rad2deg(angle), 0, 0, 1)
    glRotatef(-45, 0, 0, 1)
    
    qobj = gluNewQuadric()
    gluQuadricTexture(qobj, GL_TRUE)
    glEnable(GL_TEXTURE_2D)
    glBindTexture(GL_TEXTURE_2D, texture)
    gluSphere(qobj, 0.2, 50, 50)
    gluDeleteQuadric(qobj)
    glDisable(GL_TEXTURE_2D)  # quads, radius, slices, stacks
    glPopMatrix()
# xray/Wireframe mode Draw

# light settings
light_ambient = [0.0, 0.0, 0.0, 1.0]
light_diffuse = [1.0, 1.0, 1.0, 1.0]
light_specular = [1.0, 1.0, 1.0, 1.0]
light_position = [2.0, 5.0, 5.0, 0.0]

mat_ambient = [0.7, 0.7, 0.7, 1.0]
mat_diffuse = [0.8, 0.8, 0.8, 1.0]
mat_specular = [1.0, 1.0, 1.0, 1.0]
high_shininess = [100.0]


def plot_points():
    glPushMatrix()
    glColor3f(1.0, 1.0, 1.0)

    glPointSize(3.0)

    glBegin(GL_POINTS)

    for x in [x * 0.1 for x in range(0, 100)]:
        glVertex3f(x, 0, 0)
        glVertex3f(0, x, 0)
        glVertex3f(0, 0, x)

    glEnd()
    glPopMatrix()

def main():
    slices = 7
    stacks = 7

    xrayButton = 1
    xyz_pos = 0.1
    movingDown = False
    z_pos = -8

    pygame.init()
    display = (800, 600)
    pygame.display.set_caption(
        "OpenGL")
    pygame.display.set_mode(display, DOUBLEBUF | OPENGL)
    texture = read_texture("earth.jpg")
    texture2 = read_texture("moon.jpg")

    glMatrixMode(GL_PROJECTION)
    gluPerspective(45, (display[0] / display[1]), 0.1, 50.0)

    glMatrixMode(GL_MODELVIEW)
    #glTranslatef(-2.0, -1.0, -5)
    glTranslatef(0,0,-5)
    glRotate(90, 1, 0, 0)
    glRotate(-23.5, 0, 1, 0)
    while True:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                quit()
        # glRotatef(1, 3, 1, 1)
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT)
        # drawing begins here
        
        draw(texture)
        
        draw_moon(texture2)
        #plot_points()
        #UFO(xyz_pos)

        # background color (space color)
        glClearColor(0.0, 0.0, 0.12, 1)
        glEnable(GL_CULL_FACE)
        glCullFace(GL_BACK)

        glEnable(GL_DEPTH_TEST)
        glDepthFunc(GL_LEQUAL)

        # glEnable(GL_LIGHT0)
        # glEnable(GL_NORMALIZE)
        # glEnable(GL_COLOR_MATERIAL)
        # glEnable(GL_LIGHTING)

        # glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient)
        # glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse)
        # glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular)
        # glLightfv(GL_LIGHT0, GL_POSITION, light_position)

        # glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient)
        # glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse)
        # glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular)
        # glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess)

        pygame.display.flip()
        pygame.time.wait(10)


angle = 0
main()
