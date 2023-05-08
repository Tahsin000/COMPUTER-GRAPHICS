#include <graphics.h>
#include <conio.h>


void boundaryFill4(int x, int y, int fill_color, int boundary_color) {
    if (getpixel(x, y) != boundary_color && getpixel(x, y) != fill_color) {
        putpixel(x, y, fill_color);
        boundaryFill4(x + 1, y, fill_color, boundary_color);
        boundaryFill4(x - 1, y, fill_color, boundary_color);
        boundaryFill4(x, y + 1, fill_color, boundary_color);
        boundaryFill4(x, y - 1, fill_color, boundary_color);
    }
}


int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");


    // draw the boundary
    rectangle(100, 100, 200, 200);


    // call the boundary fill algorithm
    boundaryFill4(150, 150, RED, BLACK);


    getch();
    closegraph();
    return 0;
}
