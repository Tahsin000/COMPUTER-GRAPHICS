#include <graphics.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265

void rotate_point(int x1, int y1, int x2, int y2, int *new_x, int *new_y, float angle)
{
    // Convert angle to radians
    angle = angle * PI / 180.0;

    // Translate point (x2, y2) to origin
    int x = x1 - x2;
    int y = y1 - y2;

    // Rotate point around origin
    int new_x_temp = x * cos(angle) - y * sin(angle);
    int new_y_temp = x * sin(angle) + y * cos(angle);

    // Translate point back to original position
    *new_x = new_x_temp + x2;
    *new_y = new_y_temp + y2;
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Original point
    int x1 = 100, y1 = 100;
    setcolor(YELLOW);
    circle(x1, y1, 10);

    // Point to rotate around
    int x2 = 200, y2 = 200;
    setcolor(WHITE);
    circle(x2, y2, 10);

    // Angle of rotation in degrees
    float angle = 45;

    // Rotate point
    int new_x, new_y;
    rotate_point(x1, y1, x2, y2, &new_x, &new_y, angle);

    // Display rotated point
    setcolor(GREEN);
    circle(new_x, new_y, 10);

    getch();
    closegraph();

    return 0;
}
