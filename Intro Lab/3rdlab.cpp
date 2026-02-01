#include<iostream>
#include<graphics.h>
using namespace std;

int main()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,(char*)"");
	line(100,100,100,100);
	arc(100,200,0,90,80);
	circle(200,200,80);
	clearviewport();
	getch();
	closegraph();
	return 0;
}
