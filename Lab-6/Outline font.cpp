#include <graphics.h>

// Define a bitmap font for the letter 'A'
int bitmap_A[17][12] =
{
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
    {1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

void draw_char_A( int x, int y, int color)
{

    for (int i = 0; i < 17; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            if (bitmap_A[i][j] == 1)
            {
                putpixel(x + j, y + i, color);
            }
        }
    }
}

void floodFill(int x, int y, int fill_color, int old_color) {
    if (getpixel(x, y) == old_color) {
        putpixel(x, y, fill_color);
        floodFill(x+1, y, fill_color, old_color);
        floodFill(x-1, y, fill_color, old_color);
        floodFill(x, y+1, fill_color, old_color);
        floodFill(x, y-1, fill_color, old_color);
    }
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Draw the letter 'A' at (100, 100) in red
    draw_char_A( 100, 100, WHITE);
    //floodFill(100+1, 100+1, WHITE, BLACK);

    getch();
    closegraph();
    return 0;
}
