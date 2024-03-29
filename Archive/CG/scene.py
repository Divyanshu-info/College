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

def draw(slices, stacks, texture):

    t = time.time() % 1000
    angle = t*90
    quad = gluNewQuadric()

    glColor3fv(planetColor)

    # planet
    glPushMatrix()
    glTranslatef(1.8, 1.5, -6)
    glRotatef(45, 1, 0, 0)
    glRotatef(angle, 0, 0, 1)
    qobj = gluNewQuadric()
    gluQuadricTexture(qobj, GL_TRUE)
    glEnable(GL_TEXTURE_2D)
    glBindTexture(GL_TEXTURE_2D, texture)
    gluSphere(qobj, 1, 50, 50)
    gluDeleteQuadric(qobj)
    glDisable(GL_TEXTURE_2D)
    gluSphere(qobj, 2, slices, stacks)  # quads, radius, slices, stacks
    glPopMatrix()

    # partial disk to demonstrate overlapping
    glColor3fv(partialDiskColor)
    glPushMatrix()
    glTranslatef(4.4, 1.5, -6)
    # glRotatef(-60, 1, 0.2, 0)
    glRotatef(-angle, 0, 0, 1)
    # quad, inner, outer, slices, loops, start angle, sweep angle
    gluPartialDisk(quad, 0.5, 1, slices, stacks, 0, 270)
    glPopMatrix()

    # Rings
    glColor3f(1.0, 0.8, 0.2)        # controles the color of the rings
    glPushMatrix()
    glTranslatef(1.8, 1.5, -6)
    # glRotatef(-60, 1, 0.2, 0)
    glRotatef(-angle, 0, 1, 1)
    # quad, inner, outer, slices, loops
    gluDisk(quad, 2.2, 2.7, slices, stacks)
    glPopMatrix()

    # glColor3f(0.7, 0.5, 0.0)      # If you need to change the color of the other ring
    glPushMatrix()
    glTranslatef(1.8, 1.5, -6)
    glRotatef(-60, 1, 0.2, 0)       # pre rotated by an angle
    glRotatef(-angle, 1, 0, 1)      # contineous rotation of the ring
    # quad, inner, outer, slices, loops
    gluDisk(quad, 2.2, 2.7, slices, stacks)
    glPopMatrix()

# xray/Wireframe mode Draw


def xrayDraw(slices, stacks):
    t = time.time() % 1000
    angle = t * 90
    quad = gluNewQuadric()

    glColor3fv(planetColor)

    gluQuadricDrawStyle(quad, GLU_LINE)     # WireFrame Mode
    # planet
    glPushMatrix()
    glTranslatef(1.8, 1.5, -6)
    glRotatef(45, 1, 0, 0)
    glRotatef(angle, 0, 0, 1)
    gluSphere(quad, 2, slices, stacks)  # quads, radius, slices, stacks
    glPopMatrix()

    # space station
    glColor3fv(partialDiskColor)
    glPushMatrix()
    glTranslatef(4.4, 1.5, -6)
    # glRotatef(-60, 1, 0.2, 0)
    glRotatef(-angle, 0, 0, 1)
    # quad, inner, outer, slices, loops, start angle, sweep angle
    gluPartialDisk(quad, 0.5, 1, slices, stacks, 0, 270)
    glPopMatrix()

    # Rings
    glColor3f(1.0, 0.8, 0.2)  # controles the color of the rings
    glPushMatrix()
    glTranslatef(1.8, 1.5, -6)
    # glRotatef(-60, 1, 0.2, 0)
    glRotatef(-angle, 0, 1, 1)
    # quad, inner, outer, slices, loops
    gluDisk(quad, 2.2, 2.7, slices, stacks)
    glPopMatrix()

    # glColor3f(0.7, 0.5, 0.0)      # If you need to change the color of the other ring
    glPushMatrix()
    glTranslatef(1.8, 1.5, -6)
    glRotatef(-60, 1, 0.2, 0)  # pre rotated by an angle
    glRotatef(-angle, 1, 0, 1)  # contineous rotation of the ring
    # quad, inner, outer, slices, loops
    gluDisk(quad, 2.2, 2.7, slices, stacks)
    glPopMatrix()


def UFO(xyz_pos):
    t = time.time() % 1000
    angle = t * 90

    quad = gluNewQuadric()

    glColor3f(0.4, 0.1, 0.4)
    glPushMatrix()
    glTranslatef(1, 1.5, -8)  # was -8
    glTranslatef(xyz_pos, xyz_pos, -xyz_pos)
    glRotatef(45, 1, 0, 0)
    glRotatef(angle, 0, 0, 1)
    gluSphere(quad, 1, 17, 17)  # quads, radius, slices, stacks
    # glRotatef(70, 1, 0, 0)
    glPopMatrix()

    glColor3f(0.4, 0.8, 0.2)
    glPushMatrix()
    glTranslatef(1, 0.56, -8)
    glTranslatef(xyz_pos, xyz_pos, -xyz_pos)
    glRotatef(-90, 1, 0.0, 0)
    glRotatef(angle, 0, 0, 1)
    # quads, base, top, height, slices, stacks
    gluCylinder(quad, 1.5, 0.74, 1.6, 17, 17)
    glPopMatrix()


# light settings
light_ambient = [0.0, 0.0, 0.0, 1.0]
light_diffuse = [1.0, 1.0, 1.0, 1.0]
light_specular = [1.0, 1.0, 1.0, 1.0]
light_position = [2.0, 5.0, 5.0, 0.0]

mat_ambient = [0.7, 0.7, 0.7, 1.0]
mat_diffuse = [0.8, 0.8, 0.8, 1.0]
mat_specular = [1.0, 1.0, 1.0, 1.0]
high_shininess = [100.0]


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
        "OpenGL --> Lighting and Smooth Shading Demonstration")
    pygame.display.set_mode(display, DOUBLEBUF | OPENGL)
    texture = read_texture("earth.jpg")

    glMatrixMode(GL_PROJECTION)
    gluPerspective(45, (display[0] / display[1]), 0.1, 50.0)

    glMatrixMode(GL_MODELVIEW)
    glTranslatef(-2.0, -1.0, -5)
    # glTranslatef(0,0,-5)
    while True:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                quit()
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_UP:
                    slices += 1
                    stacks += 1
                if event.key == pygame.K_DOWN and (slices > 3 and stacks > 3):
                    slices -= 1
                    stacks -= 1
                if event.key == pygame.K_x:
                    xrayButton = xrayButton+1

                # camera controles
                if event.key == pygame.K_a:
                    glTranslatef(0.5, 0, 0)
                if event.key == pygame.K_d:
                    glTranslatef(-0.5, 0, 0)

                if event.key == pygame.K_w:
                    glTranslatef(0, -0.5, 0)
                if event.key == pygame.K_s:
                    glTranslatef(0, 0.5, 0)
            if event.type == pygame.MOUSEBUTTONDOWN:
                if event.button == 4:
                    glTranslatef(0, 0, 0.5)
                if event.button == 5:
                    glTranslatef(0, 0, -0.5)
        # logic to move the UFO
        if(movingDown):
            if(xyz_pos > -4):
                xyz_pos = xyz_pos - 0.04
            else:
                movingDown = False

        else:
            if(xyz_pos < 8):
                xyz_pos = xyz_pos + 0.04
            else:
                movingDown = True

        # glRotatef(1, 3, 1, 1)
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT)
        glColor3f(1.0, 1.0, 3.0)

        # drawing begins here
        if(xrayButton % 2):
            draw(slices, stacks, texture)
        else:
            xrayDraw(slices, stacks)
        UFO(xyz_pos)

        # background color (space color)
        glClearColor(0.0, 0.0, 0.12, 1)
        glEnable(GL_CULL_FACE)
        glCullFace(GL_BACK)

        glEnable(GL_DEPTH_TEST)
        glDepthFunc(GL_LEQUAL)

        glEnable(GL_LIGHT0)
        glEnable(GL_NORMALIZE)
        glEnable(GL_COLOR_MATERIAL)
        glEnable(GL_LIGHTING)

        glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient)
        glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse)
        glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular)
        glLightfv(GL_LIGHT0, GL_POSITION, light_position)

        glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient)
        glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse)
        glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular)
        glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess)

        pygame.display.flip()
        pygame.time.wait(10)


angle = 0
main()
