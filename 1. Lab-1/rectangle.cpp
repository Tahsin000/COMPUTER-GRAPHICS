// rectangle
#include <graphics.h>
#include <iostream>


using namespace std;


void drawRectangle(int x1, int y1, int x2, int y2) {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");


    rectangle(x1, y1, x2, y2);


    getch();
    closegraph();
}


int main() {
    int x1, y1, x2, y2;
    cout << "Enter top-left point x1, y1: ";
    cin >> x1 >> y1;
    cout << "Enter bottom-right point x2, y2: ";
    cin >> x2 >> y2;


    drawRectangle(x1, y1, x2, y2);


    return 0;
}
