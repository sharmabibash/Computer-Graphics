//#include <stdio.h>
//#include <conio.h>
//#include <graphics.h>
//
//int main()
//{
//    int gd = DETECT, gm;
//
//    initgraph(&gd, &gm, (char*)"");
//
//    line(100, 100, 200, 200);   
//    ellipse(100,200,0,360,80,40);   
//
//    getch();                  
//    closegraph();             
//
//    return 0;
//}





#include <graphics.h>
#include <conio.h>
#include <stdio.h>
void drawEllipse(int xc, int yc, int a, int b)
{
    int x = 0;
    int y = b;
    long a2 = a * a;
    long b2 = b * b;
    long dx = 2 * b2 * x;
    long dy = 2 * a2 * y;
    long p1 = b2 - (a2 * b) + (a2 / 4);
    // for reg 1
    while (dx < dy)
    {
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);

        x++;
        dx = dx + (2 * b2);
        if (p1 < 0)
        {
            p1 = p1 + dx + b2;
        }
        else
        {
            y--;
            dy = dy - (2 * a2);
            p1 = p1 + dx - dy + b2;
        }
    }
    /* Decision parameter for Reg 2 */
    long p2 = (b2 * (x + 0.5) * (x + 0.5)) +
              (a2 * (y - 1) * (y - 1)) -
              (a2 * b2);

    /* Reg 2 */
    while (y >= 0)
    {
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);

        y--;
        dy = dy - (2 * a2);

        if (p2 > 0)
        {
            p2 = p2 + a2 - dy;
        }
        else
        {
            x++;
            dx = dx + (2 * b2);
            p2 = p2 + dx - dy + a2;
        }
    }
}

int main()
{
    int gd = DETECT, gm;
    int xc, yc, a, b;

    initgraph(&gd, &gm, (char*)"");
    printf("Enter center (xc yc): ");
    scanf("%d %d", &xc, &yc);
    printf("Enter major axis (a): ");
    scanf("%d", &a);
    printf("Enter minor axis (b): ");
    scanf("%d", &b);
    drawEllipse(xc, yc, a, b);
    getch();
    closegraph();
    return 0;
}

