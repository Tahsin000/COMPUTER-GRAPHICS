// Draw text "Hello world" with large font size and colorful
#include <graphics.h>
#include <iostream>


using namespace std;


void displayText() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");


    settextstyle(GOTHIC_FONT, HORIZ_DIR, 7);
    setcolor(YELLOW);
    outtextxy(70, 200, "Hello World");


    getch();
    closegraph();
}


int main() {
    displayText();


    return 0;
}
