#include <iostream>
#include <graphics.h>


using namespace std;


void liangBarsky(int x1, int y1, int x2, int y2, int xmin, int ymin, int xmax, int ymax)
{
    // Calculate the four coefficients p and q.
    int p[4] = {-(x2 - x1), (x2 - x1), -(y2 - y1), (y2 - y1)};
    int q[4] = {x1 - xmin, xmax - x1, y1 - ymin, ymax - y1};


    // Calculate the start and end points of the clipped line.
    float t1 = 0.0f, t2 = 1.0f;
    for (int i = 0; i < 4; i++)
    {
        // If the line is parallel to the clipping edge, then the line is clipped.
        if (p[i] == 0)
        {
            if (q[i] < 0)
            {
                t1 = 0.0f;
                t2 = 0.0f;
            }
            else
            {
                t1 = 1.0f;
                t2 = 1.0f;
            }
        }
        else
        {
            // Calculate the intersection point of the line and the clipping edge.
            float u = (float)q[i] / p[i];


            // If the intersection point is within the clipping edge, then update the start and end points of the clipped line.
            if (u >= 0.0f && u <= 1.0f)
            {
                if (p[i] < 0)
                {
                    t1 = max(t1, u);
                }
                else
                {
                    t2 = min(t2, u);
                }
            }
        }
    }


    // Draw the clipped line.
    line(x1 + (x2 - x1) * t1, y1 + (y2 - y1) * t1, x1 + (x2 - x1) * t2, y1 + (y2 - y1) * t2);
}


int main()
{


    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");


    // Set the clipping window.
    int xmin = 100, ymin = 100, xmax = 400, ymax = 400;




    setcolor(WHITE);
    rectangle(xmin, ymin, xmax, ymax);


    // Draw the original polygon.
    //line(100, 100, 400, 400);
    //line(400, 400, 400, 100);
    //line(400, 100, 100, 100);


    setcolor(YELLOW);
    setlinestyle(SOLID_LINE, 0, 3);
    // Clip the polygon using the Liang-Barsky algorithm.
    liangBarsky(10, 10, 500, 600, xmin, ymin, xmax, ymax);


    // Wait for the user to press a key.
    getch();


    // Close the graphics system.
    closegraph();


    return 0;
}


