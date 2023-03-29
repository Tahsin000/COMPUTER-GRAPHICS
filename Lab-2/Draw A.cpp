#include <graphics.h>
#include <iostream>


using namespace std;


int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");


    setcolor(WHITE);


    for (int i = 50; i <= 150; i++) {
        putpixel(100+i, i, WHITE);
        putpixel(200 - i, i, WHITE);
    }


    for (int i = 100; i <= 200; i++) {
        putpixel(i, 100, WHITE);
    }


    getch();
    closegraph();


    return 0;
}
