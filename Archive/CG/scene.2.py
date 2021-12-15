from OpenGL.GLU import *
from OpenGL.GL import *
import pygame
from pygame.locals import *
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
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB,
                 img.size[0], img.size[1], 0, GL_RGB, GL_UNSIGNED_BYTE, img_data)
    return textID


#sunTextureId = read_texture("sun.jpg")

class Sun:
    def __init__(self, sunTextureId1):
        self.sunTextureId = sunTextureId1
        self.Size = 10
    def drawSun(self):
        glPushMatrix()
        qobj = gluNewQuadric()
        gluQuadricTexture(qobj, GL_TRUE)
        glEnable(GL_TEXTURE_2D)
        glBindTexture(GL_TEXTURE_2D, self.sunTextureId)
        gluSphere(qobj, 1, 50, 50)
        gluDeleteQuadric(qobj)
        glDisable(GL_TEXTURE_2D)
        #gluSphere(qobj, 2, 50, 50)  # quads, radius, slices, stacks
        glPopMatrix()
        
        # glPushMatrix()
        # quad = gluNewQuadric()
        # glEnable(GL_LIGHT1)
        # glEnable(GL_TEXTURE_2D)
        # glBindTexture(GL_TEXTURE_2D, sunTextureId)
        # gluQuadricTexture(quad, GLU_TRUE)
        # gluSphere(quad, self.Size, 50, 50)
        # glDisable(GL_TEXTURE_2D)
        # glDisable(GL_LIGHT1)
        # glPopMatrix()
        
    def update(self):
        self.drawSun()

moonTextureId = read_texture("moon.jpg")

class Moon:
    def __init__(self):
        self.Orbit = 10
        self.Size = 1
        self.revolutionW = 2.0*np.pi/273
        #27.3 times slower than earth
        self.revolutionTheta = 0
        
    def drawOrbit(self):
        glPushMatrix()
        glColor3ub(192, 192, 192)
        glBegin(GL_LINE_LOOP)
        for i in range (0, 3600):
            angle = 2 * np.pi * i / 3600
            x = np.cos(angle)
            y = np.sin(angle)
            glVertex3d(self.Orbit*x, self.Orbit*y, 0)
        glEnd()

        glPopMatrix()
        
    def drawMoon(self):
        glPushMatrix()
        quad = gluNewQuadric()
        #
        x = np.cos(self.revolutionTheta)
        y = np.sin(self.revolutionTheta)
        glTranslatef(self.Orbit*x, self.Orbit*y, 0)
        glEnable(GL_TEXTURE_2D)
        glBindTexture(GL_TEXTURE_2D, moonTextureId)
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST)
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST)
        gluQuadricTexture(quad, GLU_TRUE)
        gluSphere(quad, self.Size, 30, 30)
        glDisable(GL_TEXTURE_2D)
        glPopMatrix()
        
    def update(self):
        self.drawOrbit()
        self.drawMoon()
        self.revolutionTheta += self.revolutionW
    

earthTextureId = read_texture("earth.jpg")
class Earth:
    def __init__(self) -> None:
        self.Orbit = 40
        self.Size = 3
        self.revolutionW = 2.0*np.pi/3560
    #speed
        self.revolutionTheta = 0

        self.rotationW = 36
        self.rotationTheta = 0
    def drawOrbit(self):
        glPushMatrix()
        glColor3ub(192, 192, 192)
        glBegin(GL_LINE_LOOP)
        for i in range(0, 3600):
            angle = 2 * np.pi * i / 3600
            x = np.cos(angle)
            y = np.sin(angle)
            glVertex3d(self.Orbit*x, self.Orbit*y, 0)
        glEnd()

        glPopMatrix()
    def drawEarth(self):
        x = np.cos(self.revolutionTheta)
        y = np.sin(self.revolutionTheta)
        #draw earth
        quad = gluNewQuadric()
        glPushMatrix()
        glTranslatef(self.Orbit*x, self.Orbit*y, 0)
        glRotatef(self.rotationTheta, 0, 0, 1)
        glEnable(GL_TEXTURE_2D)
        glBindTexture(GL_TEXTURE_2D, earthTextureId)
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST)
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST)
        gluQuadricTexture(quad, GLU_TRUE)
        gluSphere(quad, self.Size, 30, 30)
        glDisable(GL_TEXTURE_2D)
        glPopMatrix()

        # draw moon
        glPushMatrix()
        glTranslatef(self.Orbit*x, self.Orbit*y, 0)
        moon.update()
        glPopMatrix()

    def update(self):
        self.drawOrbit()
        self.drawEarth()
        self.revolutionTheta += self.revolutionW
        self.rotationTheta += self.rotationW

sun = Sun()
earth = Earth()
moon = Moon()




def makeEnvironment():
    ambient = [0.2, 0.2, 0.2, 1]
    diffuse = [1, 1, 1, 1]
    position = [0, 0, 0, 1]
    # positional light
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient)
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse)
    glLightfv(GL_LIGHT0, GL_POSITION, position)

    ambient1 = [5, 5, 5, 1]
    diffuse1 = [1, 1, 1, 1]
    position1 = [0, 0, 0, 1]
    # positional light
    glLightfv(GL_LIGHT1, GL_AMBIENT, ambient1)
    glLightfv(GL_LIGHT1, GL_DIFFUSE, diffuse1)
    glLightfv(GL_LIGHT1, GL_POSITION, position1)

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
    glClearColor(0.0, 0.0, 0.0, 1.0)
    glEnable(GL_DEPTH_TEST)
    glShadeModel(GL_SMOOTH)
    glEnable(GL_NORMALIZE)
    glEnable(GL_LIGHTING)
    glEnable(GL_LIGHT0)
    # Put any initializing code for the GAME not PROGRAM below this line
    glTranslatef(0, 0, -50)
    glRotatef(90, 0, 1, 0)


# Change the code below only if absolutely needed!!
def main():
    pygame.init()
    display = (800, 600)
    pygame.display.set_caption(
        "OpenGL --> Lighting and Smooth Shading Demonstration")
    pygame.display.set_mode(display, DOUBLEBUF | OPENGL)

    glMatrixMode(GL_PROJECTION)
    gluPerspective(45, (display[0] / display[1]), 0.1, 50.0)

    glMatrixMode(GL_MODELVIEW)
    #glTranslatef(-2.0, -1.0, -5)
    glTranslatef(0, 0, -5)

    glMatrixMode(GL_MODELVIEW)
    glEnable(GL_DEPTH_TEST)
    glShadeModel(GL_SMOOTH)
    glEnable(GL_NORMALIZE)
    glEnable(GL_LIGHTING)
    glEnable(GL_LIGHT0)
    running =True
    #texture = read_texture("earth.jpg")
    sunTextureId = read_texture("sun.jpg")

    while running:
        #clock.tick(FPS)

        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False

        
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT)
        
        makeEnvironment()

        sun.update()
        earth.update()
        #plot_points()
        pygame.display.flip()


if __name__ == "__main__":
    main()
    pygame.quit()
    quit()
