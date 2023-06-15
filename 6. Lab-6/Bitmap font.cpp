#include <graphics.h>

// Define a bitmap font for the letter 'A'
int bitmap_B[8][8] = {
    {1, 1, 1, 1, 0, 0, 0, 0},
    {1, 0, 0, 0, 1, 0, 0, 0},
    {1, 0, 0, 0, 1, 0, 0, 0},
    {1, 1, 1, 1, 0, 0, 0, 0},
    {1, 0, 0, 0, 1, 0, 0, 0},
    {1, 0, 0, 0, 1, 0, 0, 0},
    {1, 0, 0, 0, 1, 0, 0, 0},
    {1, 1, 1, 1, 0, 0, 0, 0}
};

void draw_char_A( int x, int y, int color) {

    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 8; j++) {
            if (bitmap_B[i][j] == 1) {
                putpixel(x + j, y + i, color);
            }
        }
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Draw the letter 'A' at (100, 100) in red
    draw_char_A( 100, 100, YELLOW);

    getch();
    closegraph();
    return 0;
}
