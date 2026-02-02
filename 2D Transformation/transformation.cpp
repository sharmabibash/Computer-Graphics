#include <graphics.h>
#include <conio.h>
#include <math.h>
#include <stdio.h>

// Draw X and Y axes at the center
void drawAxes(int midX, int midY)
{
    setcolor(WHITE);
    // X-axis
    line(0, midY, getmaxx(), midY);
    // Y-axis
    line(midX, 0, midX, getmaxy());

    // Optional: Draw arrows
    line(getmaxx()-10, midY-5, getmaxx(), midY);
    line(getmaxx()-10, midY+5, getmaxx(), midY);
    line(midX-5, 10, midX, 0);
    line(midX+5, 10, midX, 0);
}

// Draw triangle with respect to the center
void drawTriangle(int x1,int y1,int x2,int y2,int x3,int y3,int color, int midX, int midY)
{
    setcolor(color);
    line(midX + x1, midY - y1, midX + x2, midY - y2);
    line(midX + x2, midY - y2, midX + x3, midY - y3);
    line(midX + x3, midY - y3, midX + x1, midY - y1);
}

int main()
{
    char choice;
    int gd = DETECT, gm;
    int x1, y1, x2, y2, x3, y3;
    int tx, ty, ch;
    float sx, sy, shx, shy, angle;

    printf("Enter the coordinates for the Triangle:\n");
    printf("Enter first vertex (x y): ");
    scanf("%d %d",&x1,&y1);
    printf("Enter second vertex (x y): ");
    scanf("%d %d",&x2,&y2);
    printf("Enter third vertex (x y): ");
    scanf("%d %d",&x3,&y3);

    initgraph(&gd, &gm, (char*)"");

    int midX = getmaxx() / 2; // for center X
    int midY = getmaxy() / 2; // for center Y

    drawAxes(midX, midY); // for Draw axes
    drawTriangle(x1, y1, x2, y2, x3, y3, WHITE, midX, midY); // Original triangle

do
{
    printf("\n--- 2D Transformations ---\n");
    printf("1. Translation\n");
    printf("2. Scaling\n");
    printf("3. Rotation\n");
    printf("4. Shearing\n");
    printf("5. Reflection\n");
    printf("Enter your choice: ");
    scanf("%d",&ch);

    switch(ch)
    {
        case 1: // for Translation
            printf("Enter tx ty: ");
            scanf("%d %d",&tx,&ty);
            drawTriangle(x1+tx, y1+ty, x2+tx, y2+ty, x3+tx, y3+ty, RED, midX, midY);
            break;

        case 2: // for Scaling
            printf("Enter sx sy: ");
            scanf("%f %f",&sx,&sy);
            drawTriangle(x1*sx, y1*sy, x2*sx, y2*sy, x3*sx, y3*sy, GREEN, midX, midY);
            break;

        case 3: // for Rotation
            printf("Enter angle in degrees: ");
            scanf("%f",&angle);
            angle = angle * M_PI / 180.0;
            drawTriangle(
                x1*cos(angle) - y1*sin(angle), y1*cos(angle) + x1*sin(angle),
                x2*cos(angle) - y2*sin(angle), y2*cos(angle) + x2*sin(angle),
                x3*cos(angle) - y3*sin(angle), y3*cos(angle) + x3*sin(angle),
                YELLOW, midX, midY
            );
            break;

        case 4: // for Shearing
            printf("Enter shx shy: ");
            scanf("%f %f",&shx,&shy);
            drawTriangle(
                x1 + shx*y1, y1 + shy*x1,
                x2 + shx*y2, y2 + shy*x2,
                x3 + shx*y3, y3 + shy*x3,
                CYAN, midX, midY
            );
            break;

        case 5: // for Reflection
        {
            int r;
            printf("1. X-axis\n2. Y-axis\n3. Origin\nEnter option: ");
            scanf("%d",&r);

            if(r == 1) // X-axis
                drawTriangle(x1, -y1, x2, -y2, x3, -y3, MAGENTA, midX, midY);
            else if(r == 2) // Y-axis
                drawTriangle(-x1, y1, -x2, y2, -x3, y3, MAGENTA, midX, midY);
            else if(r == 3) // Origin
                drawTriangle(-x1, -y1, -x2, -y2, -x3, -y3, MAGENTA, midX, midY);
            else
                printf("Invalid reflection!\n");
            break;
        }

        default:
            printf("Invalid choice!\n");
    }

    printf("\nDo you want to continue? (y/n): ");
    scanf(" %c", &choice);

} while(choice=='y' || choice=='Y');

    getch();
    closegraph();
    return 0;
}

