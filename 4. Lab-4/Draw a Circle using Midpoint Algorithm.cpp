#include<graphics.h>
#include<bits/stdc++.h>
#define pi 3.1416
using namespace std;
main()

{

    int gd = DETECT,gm, i;

    initgraph(&gd, &gm, (char*) "");

    int  r,x,y,xc,yc,p;
    cout<<"Enter the coordinates (x,y) :";
    cin>>xc>>yc;
    cout<<" Enter Radius: ";
    cin>>r;
    p=(5/4)-r;
    y=r;
    x=0;
    y=r;
    putpixel(xc+x,yc+y,GREEN);
    putpixel(xc-x,yc+y,GREEN);
    putpixel(xc+x,yc-y,GREEN);
    putpixel(xc-x,yc-y,GREEN);
    putpixel(xc+y,yc+x,GREEN);
    putpixel(xc-y,yc+x,GREEN);
    putpixel(xc+y,yc-x,GREEN);
    putpixel(xc-y,yc-x,GREEN);
    p=1-r;
    while(x<y)
        {
            if(p<0)
                {
                    x=x+1;
                    p=p+2*x+1;
                }
            else
                {
                    x=x+1;
                    y=y-1;
                    p=p+2*(x-y)+1;
                }
            putpixel(xc+x,yc+y,GREEN);
            putpixel(xc-x,yc+y,GREEN);
            putpixel(xc+x,yc-y,GREEN);
            putpixel(xc-x,yc-y,GREEN);
            putpixel(xc+y,yc+x,GREEN);
            putpixel(xc-y,yc+x,GREEN);
            putpixel(xc+y,yc-x,GREEN);
            putpixel(xc-y,yc-x,GREEN);
            delay(50);
        }

    getch();

    closegraph();

}
