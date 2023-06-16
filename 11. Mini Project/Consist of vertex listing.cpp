#include<windows.h>
#include <GL/glut.h>
#include <stdlib.h>


static int slices = 6;
static int stacks = 6;


/* Vertex Listing */
GLfloat vertices[][3] = {
    {-0.5, -0.5, -0.5},  // Vertex 0
    {-0.5, -0.5, 0.5},   // Vertex 1
    {-0.5, 0.5, 0.5},    // Vertex 2
    {-0.5, 0.5, -0.5},   // Vertex 3
    {0.5, -0.5, -0.5},   // Vertex 4
    {0.5, -0.5, 0.5},    // Vertex 5
    {0.5, 0.5, 0.5},     // Vertex 6
    {0.5, 0.5, -0.5}     // Vertex 7
};


/* Polygon Listing */
GLint polygons[][4] = {
    {0, 1, 2, 3},    // Polygon 0 (Front face)
    {4, 5, 6, 7},    // Polygon 1 (Back face)
    {0, 1, 5, 4},    // Polygon 2 (Left face)
    {2, 3, 7, 6},    // Polygon 3 (Right face)
    {0, 3, 7, 4},    // Polygon 4 (Top face)
    {1, 2, 6, 5}     // Polygon 5 (Bottom face)
};


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


    // Draw the box wireframe
    for (int i = 0; i < 6; i++) {
        glBegin(GL_LINE_LOOP);
        for (int j = 0; j < 4; j++) {
            glVertex3fv(vertices[polygons[i][j]]);
        }
        glEnd();
    }


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
