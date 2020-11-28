#include "income.h"

int graph(int Year,int menu)
{
	initwindow(1500,800);
	int x,y,i;
	char month[12][4]={"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
	char text[100];
	
	//draw x-axis
	line(100,700,1400,700);
	
	//draw y-axis
	line(100,100,100,700);
	//show instruction
	strcpy(text,"**Press any key to close this window** ");
	outtextxy(5,775,text);
	//mark Month on x-axis
	for(i=0;i<12;i++)
	{
		line((i+2)*100,685,(i+2)*100,715);
		outtextxy(((i+2)*100)-15,725,month[i]);
	}
	
	//Get data to put in graph
	float in[12],out[12],maxo=0,maxi=0;
	char Filename[30],date[8];
	FILE *fp;
	
	//open flie (Jan - Dec) to read and get data
	for(i=0;i<12;i++)
	{
		sprintf(date,"%02d-%d",i+1,Year);
		strcat(strcat(strcpy(Filename,"storage/"),date),"total.txt");
		if((fp = fopen(Filename,"r"))==NULL)
		{
			//cannot open file
			out[i]=-1;
			in[i]=-1;	
		}
		else //can open file
		{	
			//read & get data
			fscanf(fp,"%f %f",&in[i],&out[i]);
			fclose(fp);
			//find maximum value of income & expenses in order to devide graph scale 
			if(maxo<=out[i])
			{
				//fine maximum of Expenses
				maxo=out[i];
			}
			if(maxi<=in[i])
			{
				//fine maximum of Income
				maxi=in[i];
			}
		}
	}
	//Show Income graph (if user choose 1)
	if(menu==1){
		//plot data on graph
		plotdata (maxi,in);
		//show graph title
		settextstyle(9,0,5);
		strcpy(text,"Income Graph");
		outtextxy(550,50,text);
	}
	else //Show Expenses graph (if user choose 2)
	{
		//plot data on graph
		plotdata (maxo,out);
		//show graph title
		settextstyle(9,0,5);
		strcpy(text,"Expenses Graph");
		outtextxy(550,50,text);
	}
	//show axis name
	settextstyle(9,1,2);
	strcpy(text,"Value (Baht)");
	outtextxy(50,450,text);
	settextstyle(9,0,2);
	strcpy(text,"Month");
	outtextxy(710,760,text);
	
	_getch();
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
			//calculate scale
			//x=200+(i*100)  //in Jan (x=200) in Fab (x=300) in ......
			//y=700-(value of money*550/Maximum of value of money)
			
			circle(200+(i*100),700-((int)(data[i]*550/max)),5); //draw dot on (x,y)
			
			//print value of money on graph
			sprintf(value,"%.2f",data[i]);
			outtextxy(150+(i*100),650-((int)(data[i]*550/max)),value);
			n+=1;
			if(n==2)
			{
				//draw connection line if two dots are adjacent
				line(200+((i-1)*100),700-(int)(data[i-1]*550/max),200+(i*100),700-(int)(data[i]*550/max));
				n=1;
			}				
		}
		else n=0;
	}
}
