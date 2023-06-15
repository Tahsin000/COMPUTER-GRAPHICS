#include<graphics.h>
#include<bits/stdc++.h>
#define pi 3.1416
using namespace std;
main()

{
    int gd = DETECT,gm, i;

    initgraph(&gd, &gm, (char*) "");

    int h,k,r,theta,x,y;
    cout<<"Enter the coordinate h,k :";
    cin>>h>>k;
    cout<<" Enter Radius: ";
    cin>>r;
    double rad = pi/180;
    for( theta = 0; theta <= 45; theta++ )
        {
            int x1= r* cos(theta*rad);

            int y1 = r* sin(theta*rad);
            x=int(x1+0.5);
            y=int(y1+0.5);
            putpixel(x+h,y+k,6);
            putpixel(x+h,-y+k,6);
            putpixel(-x+h,y+k,6);
            putpixel(-x+h,-y+k,6);
            putpixel(y+h,x+k,6);
            putpixel(y+h,-x+k,6);
            putpixel(-y+h,x+k,6);
            putpixel(-y+h,-x+k,6);
        }
    getch();
    closegraph();
}
