#include<graphics.h>
#include<bits/stdc++.h>
#include<conio.h>

#include<stdio.h>
#define pi 3.1416
using namespace std;
main()

{

    int gd = DETECT,gm, i;

    initgraph(&gd, &gm, (char*) "");

    int h,k,r;

    double x,y;

    cout<<"Enter the coordinate h,k :";
    cin>>h>>k;
    cout<<" Enter Radius: ";
    cin>>r;
    double n = r/sqrt(2);
    for(  x = 0; x <= n; x++ )
        {

            y=sqrt((r*r-x*x) );
            putpixel(x+h, y+k, RED);
            putpixel(x+h, -y+k, RED);
            putpixel(-x+h, -y+k, RED);
            putpixel(-x+h, y+k, RED);
            putpixel(y+h, x+k, RED);
            putpixel(y+h, -x+k, RED);
            putpixel(-y+h, -x+k, RED);
            putpixel(-y+h, x+k, RED);

            delay(50);
        }

    getch();

    closegraph();

}
