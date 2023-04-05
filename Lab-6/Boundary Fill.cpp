#include <graphics.h>

// Function to perform boundary fill
void boundaryFill(int x, int y, int fill_color, int boundary_color) {
    if (getpixel(x, y) != boundary_color && getpixel(x, y) != fill_color) {
        putpixel(x, y, fill_color);
        boundaryFill(x + 1, y, fill_color, boundary_color);
        boundaryFill(x, y + 1, fill_color, boundary_color);
        boundaryFill(x - 1, y, fill_color, boundary_color);
        boundaryFill(x, y - 1, fill_color, boundary_color);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Draw a rectangle
    rectangle(100, 100, 200, 200);

    // Perform boundary fill at (150, 150) with fill color RED and boundary color BLACK
    boundaryFill(150, 150, RED, BLACK);

    getch();
    closegraph();
    return 0;
}
