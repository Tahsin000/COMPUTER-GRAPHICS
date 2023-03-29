#include <graphics.h>

int main() {
   int gd = DETECT, gm;
   initgraph(&gd, &gm, "");

   int x = 250;
   int y = 250;
   int radius = 100;
   int start_angle = 45; // start angle in degrees
   int end_angle = 135; // end angle in degrees

   arc(x, y, start_angle, end_angle, radius);

   getch();
   closegraph();
   return 0;
}
