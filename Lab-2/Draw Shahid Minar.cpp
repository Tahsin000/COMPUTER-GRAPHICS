// Draw Shahid Minar
#include <graphics.h>
#include <conio.h>


int main()
{
    initwindow(1000, 700, "Shahid Minar");
    // Draw the base rectangle
    //
    rectangle(30, 300, 130, 600);
    rectangle(60, 300, 100, 600);
    rectangle(20, 290, 140, 600);


    rectangle(160, 200, 280, 600);
    rectangle(200, 200, 240, 600);
    rectangle(150, 190, 290, 600);




    rectangle(310, 50, 510, 600);
    rectangle(350, 50, 470, 600);
    rectangle(300, 40, 520, 600);




    rectangle(540, 190, 680, 600);
    rectangle(580, 190, 630, 600);
    rectangle(530, 180, 690, 600);




    rectangle(710, 300, 810, 600);
    rectangle(740, 300, 780, 600);
    rectangle(700, 290, 820, 600);






    setcolor(4);  // red
    setfillstyle(SOLID_FILL, COLOR(220,20,60));  // red
    circle(410, 340, 150);
    floodfill(320, 400, 4);




    getch();
    closegraph();
    return 0;
}
