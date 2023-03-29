// Draw Bangla Ka
#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0); // set color to white

    // draw the horizontal line
    glBegin(GL_LINES);
        glVertex2f(-0.5, 0.0);
        glVertex2f(0.5, 0.0);
    glEnd();

    // draw the vertical line
    glBegin(GL_LINES);
        glVertex2f(0.0, -0.5);
        glVertex2f(0.0, 0.5);
    glEnd();

    glutSwapBuffers();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Bangla Ka");

    glutDisplayFunc(display);

    glutMainLoop();
    return 0;
}
