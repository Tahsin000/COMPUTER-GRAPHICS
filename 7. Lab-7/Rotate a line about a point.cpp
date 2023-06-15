#include <graphics.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265

void rotate_line(int x1, int y1, int x2, int y2, int x, int y, float angle, int *new_x1, int *new_y1, int *new_x2, int *new_y2)
{
    // Convert angle to radians
    angle = angle * PI / 180.0;

    // Translate points (x1, y1) and (x2, y2) to origin
    int a1 = x1 - x;
    int b1 = y1 - y;
    int a2 = x2 - x;
    int b2 = y2 - y;

    // Rotate points around origin
    int new_a1 = a1 * cos(angle) - b1 * sin(angle);
    int new_b1 = a1 * sin(angle) + b1 * cos(angle);
    int new_a2 = a2 * cos(angle) - b2 * sin(angle);
    int new_b2 = a2 * sin(angle) + b2 * cos(angle);

    // Translate points back to original position
    *new_x1 = new_a1 + x;
    *new_y1 = new_b1 + y;
    *new_x2 = new_a2 + x;
    *new_y2 = new_b2 + y;
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Original line
    int x1 = 100, y1 = 100, x2 = 200, y2 = 200;
    setcolor(GREEN);
    line(x1, y1, x2, y2);

    // Point to rotate around
    int x = 200, y = 200;
    setcolor(YELLOW);
    circle(x, y, 5);

    // Angle of rotation in degrees
    float angle = 45;

    // Rotate line
    int new_x1, new_y1, new_x2, new_y2;
    rotate_line(x1, y1, x2, y2, x, y, angle, &new_x1, &new_y1, &new_x2, &new_y2);

    // Display rotated line
    line(new_x1, new_y1, new_x2, new_y2);

    getch();
    closegraph();

    return 0;
}
