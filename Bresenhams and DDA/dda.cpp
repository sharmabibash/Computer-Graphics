#include <iostream>
#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <math.h>

using namespace std;

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");

    int x1, y1, x2, y2;
    float dx, dy, xinc, yinc;
    int steps;

    printf("Enter the First Coordinate (X1,Y1): ");
    scanf("%d,%d", &x1, &y1);

    printf("Enter the Second Coordinate (X2,Y2): ");
    scanf("%d,%d", &x2, &y2);

    dx = x2 - x1;
    dy = y2 - y1;

    if (abs(dx) > abs(dy))
        steps = abs(dx);
    else
        steps = abs(dy);

    xinc = dx / steps;
    yinc = dy / steps;

    float x = x1;
    float y = y1;

    printf("\nGenerated Coordinates:\n");

    for (int i = 0; i <= steps; i++) {
        putpixel(round(x), round(y), WHITE);
        printf("Points (X1,Y1) = (%d, %d)\n", (int)round(x), (int)round(y));
        x = x + xinc;
        y = y + yinc;
        delay(50);
    }

    getch();
    closegraph();
    return 0;
}

