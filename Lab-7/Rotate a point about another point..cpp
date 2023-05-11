#include <graphics.h>
#include <math.h>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // initial coordinates of point
    int x = 100, y = 100;

    // point to rotate about
    int pivot_x = 200, pivot_y = 200;

    // angle of rotation in degrees
    float angle_deg = 45;
    int red = 10;
    float angle_rad = angle_deg * 3.14159 / 180;

    // calculate rotated coordinates
    int new_x = pivot_x + (x - pivot_x) * cos(angle_rad) - (y - pivot_y) * sin(angle_rad);
    int new_y = pivot_y + (x - pivot_x) * sin(angle_rad) + (y - pivot_y) * cos(angle_rad);

    // draw initial point
    setcolor(WHITE);
    circle(x, y, red);

    // draw pivot point
    setcolor(RED);
    circle(pivot_x, pivot_y, red);

    // draw rotated point
    setcolor(YELLOW);
    circle(new_x, new_y, red);

    getch();
    closegraph();
    return 0;
}
