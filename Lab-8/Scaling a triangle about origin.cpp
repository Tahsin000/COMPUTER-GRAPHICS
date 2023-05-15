#include <graphics.h>
#include <stdlib.h>

void scale_triangle(int x1, int y1, int x2, int y2, int x3, int y3, float sx, float sy,
                     int *new_x1, int *new_y1, int *new_x2, int *new_y2, int *new_x3, int *new_y3)
{
    // Scale points
    *new_x1 = x1 * sx;
    *new_y1 = y1 * sy;
    *new_x2 = x2 * sx;
    *new_y2 = y2 * sy;
    *new_x3 = x3 * sx;
    *new_y3 = y3 * sy;
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Original triangle
    int x1 = 100, y1 = 100, x2 = 200, y2 = 200, x3 = 100, y3 = 200;
    setcolor(GREEN);
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);

    // Scaling factors
    float sx = 2.0, sy = 2.0;

    // Scale triangle
    int new_x1, new_y1, new_x2, new_y2, new_x3, new_y3;
    scale_triangle(x1, y1, x2, y2, x3, y3, sx, sy, &new_x1, &new_y1, &new_x2, &new_y2, &new_x3, &new_y3);

    // Display scaled triangle
    setcolor(YELLOW);
    line(new_x1, new_y1, new_x2, new_y2);
    line(new_x2, new_y2, new_x3, new_y3);
    line(new_x3, new_y3, new_x1, new_y1);

    getch();
    closegraph();

    return 0;
}
