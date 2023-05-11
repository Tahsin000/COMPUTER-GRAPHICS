#include <graphics.h>
#include <iostream>
#include <conio.h>
#include <math.h>

using namespace std;

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Input the coordinates of the point to be scaled
    int x = 100, y = 100;

    // Input the scaling factor
    float scaling_factor = 2;

    // Calculate the new coordinates after scaling
    int x_new = round(x * scaling_factor);
    int y_new = round(y * scaling_factor);

    // Use putpixel to draw the scaled point
    putpixel(x_new, y_new, WHITE);

    getch();
    closegraph();
    return 0;
}
