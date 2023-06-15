// Draw smiling face
#include <graphics.h>
#include <cmath>


int main() {
    initwindow(500, 500, "Smiling Face"); // initialize graphics window


    // draw face
    circle(250, 250, 200);


    // draw eyes
    setfillstyle(SOLID_FILL, BLACK);
    circle(180, 180, 30);
    circle(320, 180, 30);
    floodfill(180, 180, WHITE);
    floodfill(320, 180, WHITE);


    // draw pupils
    setfillstyle(SOLID_FILL, WHITE);
    circle(180, 180, 10);
    circle(320, 180, 10);
    floodfill(180, 180, BLACK);
    floodfill(320, 180, BLACK);


    // draw smile
    int x, y;
    for (int angle = 30; angle <= 150; angle++) {
        x = 200 * cos(angle * 3.14 / 180);
        y = 150 * sin(angle * 3.14 / 180);
        putpixel(x + 250, y + 245, WHITE);
    }


    getch(); // wait for user to close window
    closegraph(); // close graphics window
    return 0;
}
