#include <graphics.h>
#include <stdlib.h>

void scale_point(int x1, int y1, float sx, float sy, int *new_x, int *new_y)
{
    // Scale point
    *new_x = x1 * sx;
    *new_y = y1 * sy;
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Original point
    int x1 = 100, y1 = 100;
    setcolor(YELLOW);
    circle(x1, y1, 3);

    // Scaling factors
    float sx = 2.0, sy = 3.0;

    // Scale point
    int new_x, new_y;
    scale_point(x1, y1, sx, sy, &new_x, &new_y);

    // Display scaled point
    setcolor(GREEN);
    circle(new_x, new_y, 3);

    getch();
    closegraph();

    return 0;
}
