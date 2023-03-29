#include <graphics.h>
#include <cmath>

int main() {
   int gd = DETECT, gm;
   initgraph(&gd, &gm, "");

   int h = 250; // x-coordinate of center
   int k = 250; // y-coordinate of center
   int a = 100; // horizontal radius
   int b = 50; // vertical radius

   int x = h - a;
   while (x <= h + a) {
      int y = k + b * sqrt(1 - ((x - h) / float(a)) * ((x - h) / float(a)));
      putpixel(x, y, WHITE);
      putpixel(x, 2 * k - y, WHITE);
      x++;
   }

   getch();
   closegraph();
   return 0;
}
