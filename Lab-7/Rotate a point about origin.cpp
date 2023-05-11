#include <graphics.h>
#include <math.h>

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, ""); // initialize graphics window

    int x1 = 100, y1 = 100; // initial coordinates of the point
    int angle = 30; // angle of rotation in degrees

    // convert angle to radians
    double rad = angle * 3.14159 / 180.0;

    // calculate new coordinates after rotation
    int x2 = x1 * cos(rad) - y1 * sin(rad);
    int y2 = x1 * sin(rad) + y1 * cos(rad);

    // draw initial point and rotated point
    circle(x1, y1, 5); // initial point
    circle(x2, y2, 5); // rotated point

    getch(); // wait for key press to close graphics window
    closegraph(); // close graphics window
    return 0;
}
