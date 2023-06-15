// Draw a line, circle, rectangle
#include <graphics.h>
#include <iostream>


using namespace std;


void drawLine(int x1, int y1, int x2, int y2) {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    line(x1, y1, x2, y2);
    getch();
    closegraph();
}


int main() {
    int x1, y1, x2, y2;
    cout << "Enter starting point x1, y1: ";
    cin >> x1 >> y1;
    cout << "Enter ending point x2, y2: ";
    cin >> x2 >> y2;


    drawLine(x1, y1, x2, y2);


    return 0;
}
