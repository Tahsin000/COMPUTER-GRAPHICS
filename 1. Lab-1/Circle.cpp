// Circle

#include <graphics.h>
#include <iostream>


using namespace std;


void drawCircle(int x, int y, int r) {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");


    circle(x, y, r);


    getch();
    closegraph();
}


int main() {
    int x, y, r;
    cout << "Enter center x, y: ";
    cin >> x >> y;
    cout << "Enter radius r: ";
    cin >> r;


    drawCircle(x, y, r);


    return 0;
}
