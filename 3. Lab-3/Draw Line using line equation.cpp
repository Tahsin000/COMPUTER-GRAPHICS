
/*C graphics program to draw a line using line equation.*/
#include<bits/stdc++.h>
#include <graphics.h>
#include <conio.h>

using namespace std;

main()
{
    int gd = DETECT, gm;

    //init graphics
    initgraph(&gd, &gm, (char*) "");

    int y,m,x,c,x1,y1,x2,y2;

    cout<<"Enter first coordinates: ";
    cin>>x1>>y1;
    cout<<"Enter Second coordinates: ";
    cin>>x2>>y2;

    m=(y2-y1)/(x2-x1);
    c=y1-m*x1;

    for(int i =x1 ; i<=x2 ; i++)
        {
            y=m*i+c;
            putpixel(i,y,GREEN);
             delay(50);
        }
    getch();
    closegraph();
    return 0;
}

