#include <graphics.h>
#include <conio.h>
#include<iostream>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");

    line(100, 100, 300, 100);
    rectangle(100, 150, 300, 250);
    rectangle(100, 150, 300, 250);
    rectangle(100, 150, 300, 250);
    circle(200, 350, 50);
    circle(200, 350, 80);
    circle(200, 350, 100);
    circle(200, 350, 150);

    getch();
    closegraph();
    return 0;
}

