// Using "imageloader" to load texture file
#include <GL/glut.h>
#include <GL/gl.h>
#include <math.h>
#include "imageloader.h"

using namespace std;

#define PI 3.1415926

#define MAX_LENGTH 1000
#define SOLAR_SYSTEM_RADIUS 500
#define SUN_RADIUS 10
#define EARTH_RADIUS 3
#define MOON_RADIUS 1

void makeEnvironment();
void makeCamera();
void drawSun();

GLuint earthTextureId; //The id of the earth texture
GLuint sunTextureId; //The id of the sun texture
GLuint moonTextureId; //The id of the moon texture

GLuint loadTexture(Image* image) {
	GLuint textureId;
	glGenTextures(1, &textureId);
	glBindTexture(GL_TEXTURE_2D, textureId);
	//Map the image to the texture
	glTexImage2D(GL_TEXTURE_2D,
				 0,
				 GL_RGB,
				 image->width, image->height,
				 0,
				 GL_RGB,
				 GL_UNSIGNED_BYTE,
				 image->pixels);
	return textureId; //Returns the id of the texture
}

class Sun
{
private:
    int Size = SUN_RADIUS;
private:
    void drawSun()
    {
        glPushMatrix();
        glEnable(GL_LIGHT1);
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D,sunTextureId);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        GLUquadricObj *quad = gluNewQuadric();
        gluQuadricTexture(quad,GLU_TRUE);
        gluSphere(quad,Size,30,30);
        glDisable(GL_TEXTURE_2D);
        glDisable(GL_LIGHT1);
        glPopMatrix();
    }

public:
    void update()
    {
        drawSun();
    };

};
Sun sun;

class Moon
{
private:
    int Orbit = 10;
    int Size = MOON_RADIUS;
    double revolutionW = 2.0*PI/273; // 27.3 times slower than earth
    double revolutionTheta = 0;
private:
    void drawOrbit()
    {
        glPushMatrix();
        glColor3ub(192,192,192);
        glBegin(GL_LINE_LOOP);
            for(int i =0; i <= 3600; i++)
            {
                double angle = 2 * PI * i / 3600;
                double x = cos(angle);
                double y = sin(angle);
                glVertex3d(Orbit*x,Orbit*y,0);
            }
        glEnd();

        glPopMatrix();
    }
    void drawMoon()
    {
        glPushMatrix();
        //
        double x = cos(revolutionTheta);
        double y = sin(revolutionTheta);
        glTranslatef(Orbit*x,Orbit*y,0);
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D,moonTextureId);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        GLUquadricObj *quad = gluNewQuadric();
        gluQuadricTexture(quad,GLU_TRUE);
        gluSphere(quad,Size,30,30);
        glDisable(GL_TEXTURE_2D);
        glPopMatrix();
    }

public:
    void update()
    {
        drawOrbit();
        drawMoon();
        revolutionTheta += revolutionW;
    };

};
Moon moon;

class Earth
{
private:
    int Orbit = 40;
    int Size = EARTH_RADIUS;
    double revolutionW = 2.0*PI/3560; // speed
    double revolutionTheta = 0;

    double rotationW = 36;
    double rotationTheta = 0;
private:
    void drawOrbit()
    {
        glPushMatrix();
        glColor3ub(192,192,192);
        glBegin(GL_LINE_LOOP);
            for(int i =0; i <= 3600; i++)
            {
                double angle = 2 * PI * i / 3600;
                double x = cos(angle);
                double y = sin(angle);
                glVertex3d(Orbit*x,Orbit*y,0);
            }
        glEnd();

        glPopMatrix();
    }
    void drawEarth()
    {
        double x = cos(revolutionTheta);
        double y = sin(revolutionTheta);
        // draw earth
        glPushMatrix();
        glTranslatef(Orbit*x,Orbit*y,0);
        glRotatef(rotationTheta,0,0,1);
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D,earthTextureId);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        GLUquadricObj *quad = gluNewQuadric();
        gluQuadricTexture(quad,GLU_TRUE);
        gluSphere(quad,Size,30,30);
        glDisable(GL_TEXTURE_2D);
        glPopMatrix();

        // draw moon
        glPushMatrix();
        glTranslatef(Orbit*x,Orbit*y,0);
        moon.update();
        glPopMatrix();
    }

public:
    void update()
    {
        drawOrbit();
        drawEarth();
        revolutionTheta += revolutionW;
        rotationTheta += rotationW;
    };

};
Earth earth;


void init()
{
    glClearColor(0.0f,0.0f,0.0f,1.0f);
    glEnable(GL_DEPTH_TEST);
    glShadeModel(GL_SMOOTH);

    Image* image = loadBMP("earth.bmp");
    earthTextureId = loadTexture(image);
    delete image;

    image = loadBMP("sun.bmp");
    sunTextureId = loadTexture(image);
    delete image;

    image = loadBMP("moon.bmp");
    moonTextureId = loadTexture(image);
    delete image;

    glEnable(GL_NORMALIZE);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    makeEnvironment();

    makeCamera();

    sun.update();
    earth.update();

    glutSwapBuffers();
}

void makeEnvironment()
{
    GLfloat ambient[4] = {0.2,0.2,0.2,1};
    GLfloat diffuse[4] = {1,1,1,1};
    GLfloat position[4] = {0,0,0,1}; //positional light
    glLightfv(GL_LIGHT0,GL_AMBIENT,ambient);
    glLightfv(GL_LIGHT0,GL_DIFFUSE,diffuse);
    glLightfv(GL_LIGHT0,GL_POSITION,position);

    GLfloat ambient1[4] = {5,5,5,1};
    GLfloat diffuse1[4] = {1,1,1,1};
    GLfloat position1[4] = {0,0,0,1}; //positional light
    glLightfv(GL_LIGHT1,GL_AMBIENT,ambient1);
    glLightfv(GL_LIGHT1,GL_DIFFUSE,diffuse1);
    glLightfv(GL_LIGHT1,GL_POSITION,position1);
}

void makeCamera()
{
    int w = glutGet((GLenum)GLUT_WINDOW_WIDTH);
    int h = glutGet((GLenum)GLUT_WINDOW_HEIGHT);
    // view port
    glViewport(0,0,w,h);

    // projection
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60,1.0*w/h,1.0,MAX_LENGTH);

    // view
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(50,50,20,0,0,0,0,0,1);

}

void idle()
{
    glutPostRedisplay();
}

void timer(int e)
{
    glutPostRedisplay();
    glutTimerFunc(30,timer,0);
}

int main(int argc, char **argv)
{
    glutInit(&argc,argv);
    glutInitWindowSize(800,600);
    glutCreateWindow("Solar System");
    glutInitDisplayMode(GL_RGB | GL_DEPTH | GL_DOUBLE);

    glutDisplayFunc(display);
    glutTimerFunc(30,timer,0);

    init();
    glutMainLoop();
    return 0;
}
