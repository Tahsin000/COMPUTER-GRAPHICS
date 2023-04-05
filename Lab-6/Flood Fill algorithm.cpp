#include <graphics.h>

// function to perform the flood fill algorithm
void floodFill(int x, int y, int old_color, int new_color) {
    // check if the pixel at (x,y) is already the new color or out of the screen
    if (getpixel(x, y) == new_color || x < 0 || x >= getmaxx() || y < 0 || y >= getmaxy()) {
        return;
    }

    // check if the pixel at (x,y) is the old color
    if (getpixel(x, y) == old_color) {
        // set the pixel to the new color
        putpixel(x, y, new_color);

        // recursively call floodFill for neighboring pixels
        floodFill(x+1, y, old_color, new_color);
        floodFill(x-1, y, old_color, new_color);
        floodFill(x, y+1, old_color, new_color);
        floodFill(x, y-1, old_color, new_color);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // draw a rectangle with an inner rectangle
    rectangle(100, 100, 400, 400);
    rectangle(200, 200, 300, 300);
    floodFill(250, 250, BLACK, BLUE);

    getch();
    closegraph();
    return 0;
}
