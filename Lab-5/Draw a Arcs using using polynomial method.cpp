#include <graphics.h>
#include <cmath>


using namespace std;


int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");


    int x0 = 300, y0 = 200; // center point of the arc
    int r = 100; // radius of the arc
    float startAngle = 30, endAngle = 150; // start and end angles in degrees
    float theta;


    for (int i = 0; i <= r; i++)
    {
        theta = startAngle * M_PI / 180.0;
        while (theta <= endAngle * M_PI / 180.0)
        {
            int x = round(x0 + i * cos(theta));
            int y = round(y0 + i * sin(theta));
            putpixel(x, y, WHITE);
            theta += 0.01;
        }
    }


    getch();
    closegraph();
    return 0;
}
