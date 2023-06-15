#include <graphics.h>


void floodFill(int x, int y, int fillColor, int oldColor) {
   if (getpixel(x, y) == oldColor) {
      putpixel(x, y, fillColor);
      floodFill(x + 1, y, fillColor, oldColor);
      floodFill(x - 1, y, fillColor, oldColor);
      floodFill(x, y + 1, fillColor, oldColor);
      floodFill(x, y - 1, fillColor, oldColor);
   }
}


int main() {
   int gd = DETECT, gm;
   initgraph(&gd, &gm, "");


   // Draw a rectangle with a different color
   rectangle(100, 100, 200, 200);
   setfillstyle(SOLID_FILL, YELLOW);
   floodfill(150, 150, WHITE);


   // Call the floodFill function to fill the rectangle with a different color
   floodFill(150, 150, BLUE, WHITE);


   getch();
   closegraph();
   return 0;
}
