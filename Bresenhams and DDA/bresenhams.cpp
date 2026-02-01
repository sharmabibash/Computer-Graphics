#include <graphics.h>
#include <conio.h>
#include <iostream>
#include <cmath>

using namespace std;

void bresenham(int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);

    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;

    int x = x1;
    int y = y1;

    // Case 1: |slope| <= 1
    if (dx >= dy) {
        int p = 2 * dy - dx;

        for (int i = 0; i <= dx; i++) {
            putpixel(x, y, WHITE);
            delay(50);

            x += sx;
            if (p < 0) {
                p += 2 * dy;
            } else {
                y += sy;
                p += 2 * dy - 2 * dx;
            }
        }
    }
    // Case 2: |slope| > 1
    else {
        int p = 2 * dx - dy;

        for (int i = 0; i <= dy; i++) {
            putpixel(x, y, WHITE);
            delay(50);

            y += sy;
            if (p < 0) {
                p += 2 * dx;
            } else {
                x += sx;
                p += 2 * dx - 2 * dy;
            }
        }
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");

    int x1, y1, x2, y2;

    cout << "Enter first coordinate (x1 y1): ";
    cin >> x1 >> y1;

    cout << "Enter second coordinate (x2 y2): ";
    cin >> x2 >> y2;

    float slope = (float)(y2 - y1) / (float)(x2 - x1);
    cout << "Slope = " << slope << endl;

    bresenham(x1, y1, x2, y2);

    getch();
    closegraph();
    return 0;
}

