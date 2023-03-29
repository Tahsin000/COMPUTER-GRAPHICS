#include <graphics.h>
#include <cmath>

int main() {
   int gd = DETECT, gm;
   initgraph(&gd, &gm, "");

   int h = 250; // x-coordinate of center
   int k = 250; // y-coordinate of center
   int a = 100; // horizontal radius
   int b = 50; // vertical radius

   float theta = 0;
   while (theta <= 2 * M_PI) {
      int x = h + a * cos(theta);
      int y = k + b * sin(theta);
      putpixel(x, y, WHITE);
      putpixel(2 * h - x, y, WHITE); // symmetric point
      theta += 0.01; // increase angle by a small amount
   }

   getch();
   closegraph();
   return 0;
}
