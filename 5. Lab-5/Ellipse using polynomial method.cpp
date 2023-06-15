#include<graphics.h>
#include<iostream>
#include<cmath>


using namespace std;


int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");


    int x0 = 300, y0 = 200; // center point of the ellipse
    int a = 100, b = 50; // major and minor axis lengths


    float theta = 0.0;
    while(theta <= 2 * M_PI)
    {
        int x = round(x0 + a * cos(theta));
        int y = round(y0 + b * sin(theta));
        putpixel(x, y, WHITE);
        theta += 0.01;
    }


    getch();
    closegraph();
    return 0;
}
