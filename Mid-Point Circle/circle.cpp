#include <graphics.h>
#include <conio.h>

int main() {
    int gd = DETECT, gm;
    int x, y, r, p;

    
    initgraph(&gd, &gm, "");

    // Circle parameters
    int xc = 200, yc = 200; 
    r = 100;                

    // Starting point
    x = 0;
    y = r;
    p = 1 - r; // Decision parameter

    while (x <= y) {
        // Draw points in all 8 octants
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);
        putpixel(xc + y, yc + x, WHITE);
        putpixel(xc - y, yc + x, WHITE);
        putpixel(xc + y, yc - x, WHITE);
        putpixel(xc - y, yc - x, WHITE);

        x++;
        if (p < 0) {
            p = p + 2 * x + 1;
        } else {
            y--;
            p = p + 2 * (x - y) + 1;
        }
    }

    getch();
    closegraph();
    return 0;
}

