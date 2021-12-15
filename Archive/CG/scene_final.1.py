import time
import pygame
from pygame.locals import *

from OpenGL.GL import *
from OpenGL.GLU import *

import random
from PIL import Image 
import numpy as np
import time



def read_texture(filename):
    """
    Reads an image file and converts to a OpenGL-readable textID format
    """
    img = Image.open(filename)
    img_data = np.array(list(img.getdata()), np.int8)
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
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE)

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB,
                 img.size[0], img.size[1], 0, GL_RGB, GL_UNSIGNED_BYTE, img_data)
    return textID


def drawSun(sunTextureId):
    glPushMatrix()
    qobj = gluNewQuadric()
    gluQuadricTexture(qobj, GL_TRUE)
    glEnable(GL_TEXTURE_2D)
    glBindTexture(GL_TEXTURE_2D, sunTextureId)
    gluSphere(qobj, 5, 50, 50)
    gluDeleteQuadric(qobj)
    glDisable(GL_TEXTURE_2D)
    #gluSphere(qobj, 2, 50, 50)  # quads, radius, slices, stacks
    glPopMatrix()


revolutionTheta_earth = 0
revolutionW_earth = 1.0*3.14/3560
rotationW_earth = 1
rotationTheta_earth = 0

def draw_earth(Earth_texture, Moon_texture):
    
    Orbit = 20
    Size = 3
    global revolutionTheta_earth
    global revolutionW_earth
    global rotationW_earth 
    global rotationTheta_earth
    
    glPushMatrix()
    
    glColor3ub(192, 192, 192)
    glBegin(GL_LINE_LOOP)
    for i in range(0, 3600):
        angle = 2 * 3.14 * i / 3600
        x = np.cos(angle)
        y = np.sin(angle)
        glVertex3d(Orbit*x, Orbit*y, 0)
    glEnd()
    
    x = np.cos(revolutionTheta_earth)
    y = np.sin(revolutionTheta_earth)
    #draw earth
    quad = gluNewQuadric()
    glTranslatef(Orbit*x, Orbit*y, 0)
    draw_moon(Moon_texture)
    glRotatef(rotationTheta_earth, 0, 0, 1)
    glEnable(GL_TEXTURE_2D)
    glBindTexture(GL_TEXTURE_2D, Earth_texture)
    gluQuadricTexture(quad, GLU_TRUE)
    
    gluSphere(quad, Size, 30, 30)
    glDisable(GL_TEXTURE_2D)
    glTranslatef(Orbit*x, Orbit*y, 0)
    
    revolutionTheta_earth += revolutionW_earth
    rotationTheta_earth += rotationW_earth
    
    glPopMatrix()



revolutionW_moon = 2.0*np.pi/273
#27.3 times slower than earth
revolutionTheta_moon = 0


def draw_moon(texture):
    Orbit = 5
    Size = 1
    global revolutionW_moon
    global revolutionTheta_moon
    glPushMatrix()
    glColor3ub(192, 192, 192)
    glBegin(GL_LINE_LOOP)
    for i in range(0, 3600):
        angle = 2 * np.pi * i / 3600
        x = np.cos(angle)
        y = np.sin(angle)
        glVertex3d(Orbit*x, Orbit*y, 0)
    glEnd()
    quad = gluNewQuadric()
    #
    x = np.cos(revolutionTheta_moon)
    y = np.sin(revolutionTheta_moon)
    glTranslatef(Orbit*x, Orbit*y, 0)
    glEnable(GL_TEXTURE_2D)
    glBindTexture(GL_TEXTURE_2D, texture)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST)
    gluQuadricTexture(quad, GLU_TRUE)
    gluSphere(quad, Size, 30, 30)
    glDisable(GL_TEXTURE_2D)
    revolutionTheta_moon += revolutionW_moon
    glPopMatrix()
# xray/Wireframe mode Draw


def makeEnvironment():
    glEnable(GL_NORMALIZE)
    glClearColor(0.0, 0.0, 0.0, 1.0)
    glClearDepth(1.0)
    glEnable(GL_DEPTH_TEST)
    glShadeModel(GL_SMOOTH)
    
    ambient = [1, 1, 1, 1]
    diffuse = [1, 1, 1, 1]
    position = [0, 0, 0, 1]
    # positional light
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient)
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse)
    glLightfv(GL_LIGHT0, GL_POSITION, position)
    
    ambient1 = [0, 0, 0, 1]
    diffuse1 = [0, 0, 0, 1]
    position1 = [1, 0, 0, 0]
    # positional light
    glLightfv(GL_LIGHT1, GL_AMBIENT, ambient1)
    glLightfv(GL_LIGHT1, GL_DIFFUSE, diffuse1)
    glLightfv(GL_LIGHT1, GL_POSITION, position1)

    #
    
    
    
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
    pygame.init()
    display = (800, 600)
    pygame.display.set_caption(
        "OpenGL --> Lighting and Smooth Shading Demonstration")
    pygame.display.set_mode(display, DOUBLEBUF | OPENGL)
    

    glClearColor(0.0, 0.0, 0.0, 1.0)

    texture = read_texture("earth.jpg")
    texture_sun = read_texture("sun.jpg")
    texture2 = read_texture("moon.jpg")

    
    glMatrixMode(GL_PROJECTION)
    gluPerspective(45, (display[0] / display[1]), 0.1, 50.0)

    glMatrixMode(GL_MODELVIEW)
    #glTranslatef(-2.0, -1.0, -5)
    #makeEnvironment()
    glTranslatef(0,0,-50)
    #glRotate(45, -1, 0, 0)
    #glRotate(-23.5, 0, 1, 0)
    
    while True:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                quit()
        # glRotatef(1, 3, 1, 1)
        
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT)
        # glEnable(GL_LIGHTING)
        # glEnable(GL_LIGHT0)
        # glEnable(GL_LIGHT1)

        #clock.tick(10)
        drawSun(texture_sun)
        draw_earth(texture, texture2)
        #draw_moon(texture2)
        #plot_points()
        #UFO(xyz_pos)

        # background color (space color)
        glClearColor(0.0, 0.0, 0.12, 1)
        glEnable(GL_CULL_FACE)
        glCullFace(GL_BACK)

        # glDisable(GL_LIGHTING)
        # glDisable(GL_LIGHT0)
        # glDisable(GL_LIGHT1)

        pygame.display.flip()
        pygame.time.wait(10)


angle = 0
main()
