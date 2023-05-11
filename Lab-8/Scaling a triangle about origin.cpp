#include<iostream>
#include<graphics.h>

using namespace std;

int main() {
   int gd = DETECT, gm;
   initgraph(&gd, &gm, "");

   // Triangle vertices
   int x1 = 100, y1 = 100;
   int x2 = 150, y2 = 200;
   int x3 = 200, y3 = 100;

   // Draw the original triangle
   line(x1, y1, x2, y2);
   line(x2, y2, x3, y3);
   line(x3, y3, x1, y1);

   // Scale factor
   int sx = 2, sy = 2;

   // Scale and draw the triangle
   x1 *= sx;
   y1 *= sy;
   x2 *= sx;
   y2 *= sy;
   x3 *= sx;
   y3 *= sy;
   line(x1, y1, x2, y2);
   line(x2, y2, x3, y3);
   line(x3, y3, x1, y1);

   getch();
   closegraph();
   return 0;
}
