#include<math.h>
#include<conio.h>
#include<iostream>
#include "income.h"


int graph(int Year,int menu)
{
	initwindow(1500,800);
	int x,y,i;
	char month[12][4]={"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
	
	//x-axis
	line(100,700,1400,700);
	
	//y-axis
	line(100,100,100,700);
	
	outtextxy(5,775,"**press Enter to close this window** ");
	//Month mark on x-axis
	for(i=0;i<12;i++)
	{
		line((i+2)*100,685,(i+2)*100,715);
		outtextxy(((i+2)*100)-15,725,month[i]);
	}
	
	//Get data to put in graph
	float in[12],out[12],maxo=0,maxi=0;
	char Filename[30],date[8];
	FILE *fp;
	//find max
	for(i=0;i<12;i++)
	{
		sprintf(date,"%02d-%d",i+1,Year);
		strcat(strcat(strcpy(Filename,"storage/"),date),"total.txt");
		if((fp = fopen(Filename,"r"))==NULL)
		{
			out[i]=-1;
			in[i]=-1;	
		}
		else 
		{
			fscanf(fp,"%f %f",&in[i],&out[i]);
			fclose(fp);
			if(maxo<=out[i])
			{
				maxo=out[i];
			}
			if(maxi<=in[i])
			{
				maxi=in[i];
			}
		}
	}
	// Header & plot data
	if(menu==1){
		plotdata (maxi,in);
		settextstyle(9,0,5);
		outtextxy(550,50,"Income Graph");
	}
	else 
	{
		plotdata (maxo,out);
		settextstyle(9,0,5);
		outtextxy(550,50,"Expenses Graph");
	}

	settextstyle(9,1,2);
	outtextxy(50,450,"Value (Baht)");
	settextstyle(9,0,2);
	outtextxy(710,760,"Month");
	getch();
	closegraph();
	return 1;
}

//plot data on graph
void plotdata (float max, float data[])
{
	char value[30];
	int i,n=0;
	for(i=0;i<12;i++)
	{
		if(data[i]!=-1)
		{
			circle(200+(i*100),700-((int)(data[i]*550/max)),5); //draw dot
			//print value of money
			sprintf(value,"%.2f",data[i]);
			outtextxy(150+(i*100),650-((int)(data[i]*550/max)),value);
			n+=1;
			if(n==2)
			{
				//draw connection line
				line(200+((i-1)*100),700-(int)(data[i-1]*550/max),200+(i*100),700-(int)(data[i]*550/max));
				n=1;
			}				
		}
		else n=0;
	}
}
