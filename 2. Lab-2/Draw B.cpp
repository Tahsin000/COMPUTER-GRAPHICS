#include <graphics.h>


int main() {
   int gd = DETECT, gm;
   initgraph(&gd, &gm, "");


   // Set color to red
   setcolor(RED);


   // Draw the vertical line
   for (int y = 100; y <= 300; y++) {
      putpixel(100, y, RED);
   }


   // Draw the top horizontal line
   for (int x = 100; x <= 200; x++) {
      putpixel(x, 100, RED);
   }


   // Draw the MID horizontal line
   for (int x = 100; x <= 200; x++) {
      putpixel(x, 200, RED);
   }


   // Draw the bottom horizontal line
   for (int x = 100; x <= 200; x++) {
      putpixel(x, 300, RED);
   }




   // Draw the curve
   for (int x = 100; x <= 200; x++) {
      int y = (x - 150) * (x - 150) / 100 + 150;
      putpixel(375-y,x, RED);
      putpixel(375-y,100+x, RED);
   }


   getch();
   closegraph();
   return 0;
}
