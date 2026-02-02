#include <graphics.h>
#include <conio.h>
#include <math.h>
#include <stdio.h>

void drawPolygon(int x[], int y[], int n, int color)
{
    int i;
    setcolor(color);
    for(i = 0; i < n-1; i++)
        line(x[i], y[i], x[i+1], y[i+1]);

    line(x[n-1], y[n-1], x[0], y[0]); // close shape
}

int main()
{
    int gd = DETECT, gm;
    int n, i, ch, r;
    int x[20], y[20];
    int tx, ty;
    float sx, sy, shx, shy, angle;

    initgraph(&gd, &gm, "");

    printf("Enter number of vertices: ");
    scanf("%d",&n);

    printf("Enter coordinates (x y):\n");
    for(i=0;i<n;i++)
        scanf("%d %d",&x[i],&y[i]);

    // Draw original
    drawPolygon(x, y, n, WHITE);

    printf("\n--- 2D Transformations ---\n");
    printf("1. Translation\n");
    printf("2. Scaling\n");
    printf("3. Rotation\n");
    printf("4. Shearing\n");
    printf("5. Reflection\n");
    printf("Enter choice: ");
    scanf("%d",&ch);

    int x2[20], y2[20];

    switch(ch)
    {
        case 1: // Translation
            printf("Enter tx ty: ");
            scanf("%d %d",&tx,&ty);
            for(i=0;i<n;i++){
                x2[i] = x[i] + tx;
                y2[i] = y[i] + ty;
            }
            break;

        case 2: // Scaling
            printf("Enter sx sy: ");
            scanf("%f %f",&sx,&sy);
            for(i=0;i<n;i++){
                x2[i] = x[i] * sx;
                y2[i] = y[i] * sy;
            }
            break;

        case 3: // Rotation
            printf("Enter angle: ");
            scanf("%f",&angle);
            angle = angle * 3.14 / 180;
            for(i=0;i<n;i++){
                x2[i] = x[i]*cos(angle) - y[i]*sin(angle);
                y2[i] = x[i]*sin(angle) + y[i]*cos(angle);
            }
            break;

        case 4: // Shearing
            printf("Enter shx shy: ");
            scanf("%f %f",&shx,&shy);
            for(i=0;i<n;i++){
                x2[i] = x[i] + shx*y[i];
                y2[i] = y[i] + shy*x[i];
            }
            break;

        case 5: // Reflection
            printf("1.X-axis  2.Y-axis  3.Origin : ");
            scanf("%d",&r);
            for(i=0;i<n;i++){
                if(r==1){ x2[i]=x[i];  y2[i]=-y[i]; }
                else if(r==2){ x2[i]=-x[i]; y2[i]=y[i]; }
                else if(r==3){ x2[i]=-x[i]; y2[i]=-y[i]; }
            }
            break;
    }

    drawPolygon(x2, y2, n, RED);

    getch();
    closegraph();
    return 0;
}

