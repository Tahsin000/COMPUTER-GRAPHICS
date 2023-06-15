#include <graphics.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265

void rotate_triangle(int x1, int y1, int x2, int y2, int x3, int y3, int x, int y, float angle,
                      int *new_x1, int *new_y1, int *new_x2, int *new_y2, int *new_x3, int *new_y3)
{
    // Convert angle to radians
    angle = angle * PI / 180.0;

    // Translate points (x1, y1), (x2, y2) and (x3, y3) to origin
    int a1 = x1 - x;
    int b1 = y1 - y;
    int a2 = x2 - x;
    int b2 = y2 - y;
    int a3 = x3 - x;
    int b3 = y3 - y;

    // Rotate points around origin
    int new_a1 = a1 * cos(angle) - b1 * sin(angle);
    int new_b1 = a1 * sin(angle) + b1 * cos(angle);
    int new_a2 = a2 * cos(angle) - b2 * sin(angle);
    int new_b2 = a2 * sin(angle) + b2 * cos(angle);
    int new_a3 = a3 * cos(angle) - b3 * sin(angle);
    int new_b3 = a3 * sin(angle) + b3 * cos(angle);

    // Translate points back to original position
    *new_x1 = new_a1 + x;
    *new_y1 = new_b1 + y;
    *new_x2 = new_a2 + x;
    *new_y2 = new_b2 + y;
    *new_x3 = new_a3 + x;
    *new_y3 = new_b3 + y;
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Original triangle
    int x1 = 100, y1 = 100, x2 = 200, y2 = 200, x3 = 150, y3 = 50;
    setcolor(YELLOW);
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);

    // Point to rotate around
    int x = 200, y = 200;
    circle(x, y, 5);

    // Angle of rotation in degrees
    float angle = 45;

    // Rotate triangle
    int new_x1, new_y1, new_x2, new_y2, new_x3, new_y3;
    rotate_triangle(x1, y1, x2, y2, x3, y3, x, y, angle, &new_x1, &new_y1, &new_x2, &new_y2, &new_x3, &new_y3);

    // Display rotated triangle
    setcolor(GREEN);
    line(new_x1, new_y1, new_x2, new_y2);
    line(new_x2, new_y2, new_x3, new_y3);
    line(new_x3, new_y3, new_x1, new_y1);

    getch();
    closegraph();

    return 0;
}
