#include <graphics.h>
#include <stdlib.h>


void scale_triangle(int x1, int y1, int x2, int y2, int x3, int y3, int cx, int cy, float sx, float sy,
                     int *new_x1, int *new_y1, int *new_x2, int *new_y2, int *new_x3, int *new_y3)
{
    // Translate points
    x1 -= cx;
    y1 -= cy;
    x2 -= cx;
    y2 -= cy;
    x3 -= cx;
    y3 -= cy;


    // Scale points
    x1 *= sx;
    y1 *= sy;
    x2 *= sx;
    y2 *= sy;
    x3 *= sx;
    y3 *= sy;


    // Translate points back to original position
    x1 += cx;
    y1 += cy;
    x2 += cx;
    y2 += cy;
    x3 += cx;
    y3 += cy;


    *new_x1 = x1;
    *new_y1 = y1;
    *new_x2 = x2;
    *new_y2 = y2;
    *new_x3 = x3;
    *new_y3 = y3;
}


int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");


    // Original triangle
    int x1 = 100, y1 = 100, x2 = 200, y2 = 200, x3 = 150, y3 = 50;
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);


    // Point to scale around
    int cx = 150, cy = 150;
    circle(cx, cy, 3);


    // Scaling factors
    float sx = 2.0, sy = 3.0;


    // Scale triangle
    int new_x1, new_y1, new_x2, new_y2, new_x3, new_y3;
    scale_triangle(x1, y1, x2, y2, x3, y3, cx, cy, sx, sy, &new_x1, &new_y1, &new_x2, &new_y2, &new_x3, &new_y3);


    // Display scaled triangle
    line(new_x1, new_y1, new_x2, new_y2);
    line(new_x2, new_y2, new_x3, new_y3);
    line(new_x3, new_y3, new_x1, new_y1);


    getch();
    closegraph();


    return 0;
}
