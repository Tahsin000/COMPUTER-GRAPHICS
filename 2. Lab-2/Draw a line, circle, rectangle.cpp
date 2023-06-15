// Draw a line, circle, rectangle


#include <graphics.h>
#include <conio.h>
#include <math.h>


int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");


    // Draw a line
    for (int x = 100; x <= 400; x++)
    {
        putpixel(x, 100, WHITE);
    }


    // Draw a circle
    int x0 = 250;   // center x-coordinate of the circle
    int y0 = 300;   // center y-coordinate of the circle
    int radius = 50;    // radius of the circle
    int x, y;
    float angle;


    for (int i = 0; i < 360; i++)
    {
        angle = i *3.14 / 180;
        x = x0 + radius* cos(angle);
        y = y0 + radius* sin(angle);
        putpixel(x, y, WHITE);
    }


    // Draw a rectangle
    for (int x = 100; x <= 400; x++)
    {
        putpixel(x, 200, WHITE);
        putpixel(x, 400, WHITE);
    }


    for (int y = 200; y <= 400; y++)
    {
        putpixel(100, y, WHITE);
        putpixel(400, y, WHITE);
    }


    getch();
    closegraph();
    return 0;
}
