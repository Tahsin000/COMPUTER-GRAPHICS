#include <iostream>
#include <graphics.h>
#include <math.h>


using namespace std;


void drawSector(int xc, int yc, int r, float start_angle, float end_angle) {
    int x, y;
    float angle;


    // Convert angles to radians
    start_angle = start_angle * 3.14159 / 180;
    end_angle = end_angle * 3.14159 / 180;


    // Draw sector using polynomial method
    for (angle = start_angle; angle <= end_angle; angle += 0.01) {
        x = xc + r * cos(angle);
        y = yc + r * sin(angle);
        putpixel(x, y, YELLOW);
    }


    // Draw lines connecting center to endpoints
    line(xc, yc, xc + r * cos(start_angle), yc + r * sin(start_angle));
    line(xc, yc, xc + r * cos(end_angle), yc + r * sin(end_angle));
}


int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");


    // Draw a sector centered at (200, 200) with radius 100, starting at 45 degrees and ending at 135 degrees
    drawSector(200, 200, 100, 45, 135);


    getch();
    closegraph();
    return 0;
}
