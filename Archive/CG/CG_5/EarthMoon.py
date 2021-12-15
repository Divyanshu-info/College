from read_file import *

def draw(texture):

    t = time.time() % 1000
    angle = t*90/4

    glPushMatrix()

    glRotatef(angle, 0, 0, 1)
    qobj = gluNewQuadric()
    gluQuadricTexture(qobj, GL_TRUE)
    glEnable(GL_TEXTURE_2D)
    glBindTexture(GL_TEXTURE_2D, texture)
    gluSphere(qobj, 1, 50, 50)
    gluDeleteQuadric(qobj)
    glDisable(GL_TEXTURE_2D)
    glPopMatrix()


def draw_moon(texture):

    t = time.time() % 1000
    angle = t*13.2/16

    glPushMatrix()
    glTranslate(2*np.cos(angle),
                2*np.sin(angle), 0)
    glRotatef(np.rad2deg(angle), 0, 0, 1)
    glRotatef(-45, 0, 0, 1)
    
    qobj = gluNewQuadric()
    gluQuadricTexture(qobj, GL_TRUE)
    glEnable(GL_TEXTURE_2D)
    glBindTexture(GL_TEXTURE_2D, texture)
    gluSphere(qobj, 0.2, 50, 50)
    gluDeleteQuadric(qobj)
    glDisable(GL_TEXTURE_2D)
    glPopMatrix()

def main():
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
    glTranslatef(0,0,-5)
    glRotate(90, 1, 0, 0)
    glRotate(-23.5, 0, 1, 0)
    while True:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                quit()
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT)
        
        draw(texture)
        draw_moon(texture2)
        
        glClearColor(0.0, 0.0, 0.12, 1)
        glEnable(GL_CULL_FACE)
        glCullFace(GL_BACK)

        glEnable(GL_DEPTH_TEST)
        glDepthFunc(GL_LEQUAL)

        pygame.display.flip()
        pygame.time.wait(10)

main()
