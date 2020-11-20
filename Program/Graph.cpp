#include<math.h>
#include<conio.h>
#include<iostream>
#include "income.h"
using namespace std;

int graph()
{
	initwindow(1500,800);
	int x,y;
	char month[12][4]={"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
	//x-axis
	line(100,700,1400,700);
	//y-axis
	line(100,100,100,700);
	//Month mark on x-axis
	for(int i=0;i<12;i++)
	{
		line((i+2)*100,685,(i+2)*100,715);
		outtextxy(((i+2)*100)-15,735,month[i]);
	}
	
	//Input Data
	
	

	
	/*float pi=3.1415;
	for(int i=-360;i<=360;i++)
	{
		x=(int)400+i;
		y=(int)300-sin(i*pi/100)*25;
		putpixel(x,y,WHITE);
	}*/
	getch();
	closegraph();
	return 1;
}
