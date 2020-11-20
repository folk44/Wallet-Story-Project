#include<math.h>
#include<conio.h>
#include<iostream>
#include "income.h"
using namespace std;

int graph(int Year)
{
	initwindow(1500,800);
	int x,y,i;
	char month[12][4]={"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
	
	//x-axis
	line(100,700,1400,700);
	
	//y-axis
	line(100,100,100,700);
	
	
	//Month mark on x-axis
	for(i=0;i<12;i++)
	{
		line((i+2)*100,685,(i+2)*100,715);
		outtextxy(((i+2)*100)-15,725,month[i]);
	}
	
	//Get data to put in graph
	float in[12],out[12],max=0;
	int n=0;
	char Filename[30],date[8],tempc[30];
	FILE *fp;
	//find max
	for(i=0;i<12;i++)
	{
		sprintf(date,"%02d-%d",i+1,Year);
		strcat(strcat(strcpy(Filename,"storage/"),date),"total.txt");
		if((fp = fopen(Filename,"r"))==NULL)
		{
			out[i]=-1;	
		}
		else 
		{
			fscanf(fp,"%f %f",&in[i],&out[i]);
			fclose(fp);
			if(max<=out[i])
			{
				max=out[i];
			}
		}
	}
	
	
	//draw graph
	for(i=0;i<12;i++)
	{
		if(out[i]!=-1)
		{
			circle(200+(i*100),700-((int)(out[i]*550/max)),5); //draw dot
			//print value of money
			sprintf(tempc,"%.2f",out[i]);
			outtextxy(150+(i*100),650-((int)(out[i]*550/max)),tempc);
			n+=1;
			if(n==2)
			{
				line(200+((i-1)*100),700-(int)(out[i-1]*550/max),200+(i*100),700-(int)(out[i]*550/max));
				n=1;
			}
			
		}
		else n=0;
	}
	//Header
	settextstyle(9,0,5);
	outtextxy(550,50,"Expenses Graph");
	settextstyle(9,1,2);
	outtextxy(50,450,"Value (Baht)");
	settextstyle(9,0,2);
	outtextxy(710,760,"Month");
	getch();
	closegraph();
	return 1;
}
