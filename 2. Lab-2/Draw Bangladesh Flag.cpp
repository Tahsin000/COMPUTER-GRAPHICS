#include <graphics.h>
#include <conio.h>


int main() {
   int gd = DETECT, gm;
   initgraph(&gd, &gm, "");


   // Draw the green part of the flag
   setfillstyle(SOLID_FILL, COLOR(0,102,51));  // green
   bar(0, 0, 700, 500);


   // Draw the red circle
   setcolor(4);  // red
   setfillstyle(SOLID_FILL, COLOR(220,20,60));  // red
   circle(320, 240, 90);
   floodfill(320, 240, 4);


   getch();
   closegraph();
   return 0;
}
