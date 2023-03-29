#include <bits/stdc++.h>
#include <graphics.h>
void drawCircle(int xc, int yc, int x, int y)
{
	putpixel(xc+x, yc+y, GREEN);
	putpixel(xc-x, yc+y, GREEN);
	putpixel(xc+x, yc-y, GREEN);
	putpixel(xc-x, yc-y, GREEN);
	putpixel(xc+y, yc+x, GREEN);
	putpixel(xc-y, yc+x, GREEN);
	putpixel(xc+y, yc-x, GREEN);
	putpixel(xc-y, yc-x, GREEN);
}

int main()
{
	int xc = 200, yc = 200, r = 200;
	int gd = DETECT, gm;
	initgraph(&gd, &gm, "");
	int x = 0, y = r;
	int d = 3 - 2 * r;
	drawCircle(xc, yc, x, y);
	while (y >= x)
	{

		x++;
		if (d > 0)
		{
			y--;
			d = d + 4 * (x - y) + 10;
		}
		else
			d = d + 4 * x + 6;
		drawCircle(xc, yc, x, y);
 	   delay(60);
	}
    getch();

    closegraph();

}
