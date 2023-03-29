// Display image.
#include<graphics.h>
#include<conio.h>
int main()
{
    int gmode= DETECT, gm;
    initgraph (&gmode, & gm, "E://7th Semester//CG//Lab//Lab-1");
    readimagefile("temp.jpg",50,50, 500, 400);
    getch();
    closegraph ();
}
