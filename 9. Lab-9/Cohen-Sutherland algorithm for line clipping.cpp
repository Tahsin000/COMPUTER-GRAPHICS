#include <iostream>
#include <graphics.h>


// Define constants for the region codes
const int INSIDE = 0; // Inside the clip window
const int LEFT = 1;   // To the left of the clip window
const int RIGHT = 2;  // To the right of the clip window
const int BOTTOM = 4; // Below the clip window
const int TOP = 8;    // Above the clip window


// Define the clipping region
const int xMin = 100;
const int xMax = 400;
const int yMin = 100;
const int yMax = 300;


// Function to compute the region code for a point (x, y)
int computeRegionCode(int x, int y) {
    int code = INSIDE;


    if (x < xMin)
        code |= LEFT;
    else if (x > xMax)
        code |= RIGHT;


    if (y < yMin)
        code |= BOTTOM;
    else if (y > yMax)
        code |= TOP;


    return code;
}


// Function to clip a line using the Cohen-Sutherland algorithm
void cohenSutherlandClip(int x1, int y1, int x2, int y2) {
    int regionCode1 = computeRegionCode(x1, y1);
    int regionCode2 = computeRegionCode(x2, y2);
    bool accept = false;


    while (true) {
        if ((regionCode1 == 0) && (regionCode2 == 0)) {
            // Both endpoints are inside the clip window
            accept = true;
            break;
        } else if (regionCode1 & regionCode2) {
            // Both endpoints are outside the same region
            break;
        } else {
            // Clip the line to the intersection point of the clip window
            int x, y;


            // Select the region code that is outside the clip window
            int outsideCode = (regionCode1 != 0) ? regionCode1 : regionCode2;


            // Compute the intersection point based on the region code
            if (outsideCode & TOP) {
                x = x1 + (x2 - x1) * (yMax - y1) / (y2 - y1);
                y = yMax;
            } else if (outsideCode & BOTTOM) {
                x = x1 + (x2 - x1) * (yMin - y1) / (y2 - y1);
                y = yMin;
            } else if (outsideCode & RIGHT) {
                y = y1 + (y2 - y1) * (xMax - x1) / (x2 - x1);
                x = xMax;
            } else if (outsideCode & LEFT) {
                y = y1 + (y2 - y1) * (xMin - x1) / (x2 - x1);
                x = xMin;
            }


            // Update the endpoint coordinates and region codes
            if (outsideCode == regionCode1) {
                x1 = x;
                y1 = y;
                regionCode1 = computeRegionCode(x1, y1);
            } else {
                x2 = x;
                y2 = y;
                regionCode2 = computeRegionCode(x2, y2);
            }
        }
    }


    if (accept) {
        // Draw the clipped line
        line(x1, y1, x2, y2);
    }
}


int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");


    // Set the color and line thickness
    setcolor(RED);
    setlinestyle(SOLID_LINE, 0, 2);


    // Draw the original line
    line(50, 200, 450, 200);


    setcolor(YELLOW);
    setlinestyle(SOLID_LINE, 2, 10);
    // Clip the line using the Cohen-Sutherland algorithm
    cohenSutherlandClip(50, 200, 450, 200);


    getch();
    closegraph();
    return 0;
}


