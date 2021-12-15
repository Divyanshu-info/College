from read_file import *


def drawSun(sunTextureId):
    glPushMatrix()
    
    #create new blank quadratic object
    qobj = gluNewQuadric() 
    gluQuadricTexture(qobj, GL_TRUE)
    glEnable(GL_TEXTURE_2D)
    
    #bind texture with quadratic object
    glBindTexture(GL_TEXTURE_2D, sunTextureId) 
    
    # create a sphere of quadratic object
    # quads, radius, slices, stacks
    gluSphere(qobj, 5, 50, 50) 
    gluDeleteQuadric(qobj)
    glDisable(GL_TEXTURE_2D)
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
    
    glColor3f(1, 1, 1) #set colour of orbit
    glBegin(GL_LINE_LOOP) #draw orbit
    for i in range(0, 3600):
        angle = 2 * 3.14 * i / 3600
        x = np.cos(angle)
        y = np.sin(angle)
        glVertex3d(Orbit*x, Orbit*y, 0)
    glEnd()
    
    x = np.cos(revolutionTheta_earth)
    y = np.sin(revolutionTheta_earth)
    
    quad = gluNewQuadric()
    glTranslatef(Orbit*x, Orbit*y, 0)
    draw_moon(Moon_texture)
    #draw earth
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
revolutionTheta_moon = 0

def draw_moon(texture):
    Orbit = 5
    Size = 1
    global revolutionW_moon
    global revolutionTheta_moon
    glPushMatrix()
    glColor3f(1, 1, 1)
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

def main():
    pygame.init()
    display = (800, 600)
    pygame.display.set_caption(
        "OpenGL Sun Earth Moon")
    pygame.display.set_mode(display, DOUBLEBUF | OPENGL)
    
    #Load Texture of Sun earth and Moon
    texture = read_texture("earth.jpg")
    texture_sun = read_texture("sun.jpg")
    texture2 = read_texture("moon.jpg")

    glClearColor(0.0, 0.0, 0.12, 1)
    glMatrixMode(GL_PROJECTION)
    gluPerspective(45, (display[0] / display[1]), 0.1, 100.0)

    glMatrixMode(GL_MODELVIEW)

    glTranslatef(0,0,-50)
    while True:
        #quit program
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                quit()
        #clears the screen
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT)
        
        drawSun(texture_sun)
        draw_earth(texture, texture2)

        #to prevent interlacing
        glEnable(GL_CULL_FACE)
        glCullFace(GL_BACK)

        pygame.display.flip()
        pygame.time.wait(10)


angle = 0
main()
