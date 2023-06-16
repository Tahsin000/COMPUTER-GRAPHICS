#include<windows.h>
#include <GL/glut.h>
#include <stdlib.h>


static int slices = 6;
static int stacks = 6;


/* GLUT callback Handlers */


// Resize the viewport and projection matrix when the window is resized
static void resize(int width, int height)
{
    const float ar = (float) width / (float) height;


    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);


    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity() ;
}


// Display function for rendering the scene
static void display(void)
{
    const double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
    const double a = t*90.0;


    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3d(1,0,0);


    glPushMatrix();
    glTranslated(0,0,-3);
    glRotated(60,1,0,0);
    glRotated(a,0,0,1);
    glutWireTorus(0.2,0.8,slices,stacks);
    glPopMatrix();


    glutSwapBuffers();
}


// Keyboard input callback function
static void key(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 27 :
    case 'q':
        exit(0);
        break;


    case '+':
        slices++;
        stacks++;
        break;


    case '-':
        if (slices>3 && stacks>3)
        {
            slices--;
            stacks--;
        }
        break;
    }


    glutPostRedisplay();
}


// Idle function called when the system is idle
static void idle(void)
{
    glutPostRedisplay();
}


/* Program entry point */


int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);


    glutCreateWindow("GLUT Shapes");


    glutReshapeFunc(resize);
    glutDisplayFunc(display);
    glutIdleFunc(idle);


    glClearColor(1,1,1,1);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);


    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);


    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);


    glutMainLoop();


    return EXIT_SUCCESS;
}
