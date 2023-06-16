#include <windows.h>
#include <GL/glut.h>
#include <stdlib.h>


static int slices = 6;
static int stacks = 6;


/* GLUT callback Handlers */


static void resize(int width, int height)
{
    const float ar = (float) width / (float) height;


    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-ar, ar, -1.0, 1.0, 1.0, 100.0);


    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}


static void display(void)
{
    const double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
    const double a = t*90.0;


    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


    glPushMatrix();
    glTranslated(0, 0, -3);
    glRotated(120, 1, 0, 0);
    glRotated(a, 0, 0, 1);


    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);


    // Draw front face
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.0, 0.0); // Set color to red
    glVertex3f(-0.5, -0.5, 0.5);
    glVertex3f(0.5, -0.5, 0.5);
    glVertex3f(0.5, 0.5, 0.5);
    glVertex3f(-0.5, 0.5, 0.5);
    glEnd();


    // Draw back face
    glBegin(GL_QUADS);
    glColor3f(0.0, 1.0, 0.0); // Set color to green
    glVertex3f(-0.5, -0.5, -0.5);
    glVertex3f(0.5, -0.5, -0.5);
    glVertex3f(0.5, 0.5, -0.5);
    glVertex3f(-0.5, 0.5, -0.5);
    glEnd();


    // Draw top face
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 1.0); // Set color to blue
    glVertex3f(-0.5, 0.5, -0.5);
    glVertex3f(-0.5, 0.5, 0.5);
    glVertex3f(0.5, 0.5, 0.5);
    glVertex3f(0.5, 0.5, -0.5);
    glEnd();


    // Draw bottom face
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 0.0); // Set color to yellow
    glVertex3f(-0.5, -0.5, -0.5);
    glVertex3f(0.5, -0.5, -0.5);
    glVertex3f(0.5, -0.5, 0.5);
    glVertex3f(-0.5, -0.5, 0.5);
    glEnd();


    // Draw right face
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.0, 1.0); // Set color to purple
    glVertex3f(0.5, -0.5, -0.5);
    glVertex3f(0.5, 0.5, -0.5);
    glVertex3f(0.5, 0.5, 0.5);
    glVertex3f(0.5, -0.5, 0.5);
    glEnd();


     glBegin(GL_QUADS);
    glColor3f(0.5, 0.5, 0.5); // Set color to red
    glVertex3f(-5.0, -5.0, 0.5);
    glVertex3f(5.0, -5.0, 0.5);
    glVertex3f(5.0, 5.0, 0.5);
    glVertex3f(-5.0, 5.0, 0.5);
    glEnd();


    // Draw left face
    glBegin(GL_QUADS);
    glColor3f(0.0, 1.0, 1.0); // Set color to cyan
    glVertex3f(-0.5, -0.5, -0.5);
    glVertex3f(-0.5, 0.5, -0.5);
    glVertex3f(-0.5, 0.5, 0.5);
    glVertex3f(-0.5, -0.5, 0.5);
    glEnd();


    glPopMatrix();


    glutSwapBuffers();
}


static void key(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 27:
        case 'q':
            exit(0);
            break;


        case '+':
            slices++;
            stacks++;
            break;


        case '-':
            if (slices > 3 && stacks > 3)
            {
                slices--;
                stacks--;
            }
            break;
    }


    glutPostRedisplay();
}


static void idle(void)
{
    glutPostRedisplay();
}


/* Program entry point */


int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(10, 10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);


    glutCreateWindow("GLUT Shapes");


    glutReshapeFunc(resize);
    glutDisplayFunc(display);
    glutIdleFunc(idle);
    glutKeyboardFunc(key);


    glClearColor(1, 1, 1, 1);


    glutMainLoop();


    return EXIT_SUCCESS;
}
