#include "income.h"
void Menu3()
{
	int menu3;
	do{
	system("cls");
	titlemenu3();
	//Display Menu3
	printf("\n\t\t\t\t\t Press any choice.\n\n");
	printf("\t\t\t\t\t 1: Monthly Summary \n");
	printf("\t\t\t\t\t 2: Annual Summary\n");
	printf("\t\t\t\t\t 0: Back to main menu\n");
	
	//Check valid menu. If invalid, inform to user.
	menu3 = InvalidInput_Int("\n\t\t\t\t\t Enter your choice: ",0,2,"\t\t\t\t\t Invalid choice! Please input again.");
	
	//Go to selected menu.
		switch(menu3){
			case 1: MonthlySum(); break;
			case 2: AnnualSum(); break;
			default: {printf("\n\t\t\t\t\t Back to main menu \n");delay(1000);} break;
		}
		
	}while(menu3 != 0);
	
}

//Monthly Summary Function
void MonthlySum()
{
	int i,j,Month,Year;
	float in,out;
	char Filename[30],date[8];
	char month[12][4]={"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
	FILE *fp;
	
	system("cls");
	titlemenu3();
	printf("\n\t\t\t\t\t\t Monthly Summary\n\n");
	//Input Month Year
	do{
		Month=InvalidInput_Int("\t\t\t\t\t Input Month (back to menu Press 0): ",0,12,"\t\t\t\t\t Invalid Month! Please input again.");
		if(Month==0){printf("\n\t\t\t\t\t Back to menu \n");return;}
		Year=InvalidInput_Int("\t\t\t\t\t Input Year  (back to menu Press 0): ",0,9999,"\t\t\t\t\t Invalid Year! Please input again.");
		if(Year==0){printf("\n\t\t\t\t\t Back to menu \n");return;}
		//change input to mm-yyyy
		sprintf(date,"%02d-%d",Month,Year);
		
		//openfile mouth-yeartotal.txt
		strcat(strcat(strcpy(Filename,"storage/"),date),"total.txt");
		if((fp = fopen(Filename,"r"))==NULL)
		{
			//clear screen, show title and input again
			system("cls");
			titlemenu3();
			printf("\n\t\t\t\t\t Monthly Summary\n\n");
			printf("\t\t\t\t\t Not Found!!\n");
			printf("\t\t\t\t\t Please input again.\n");
			i=0;
		}
		else i=1;
	}while(i==0);
	
	system("cls");
	titlemenu3();
	//show Title 
	printf("\n\t\t\t\t\t Monthly Summary [%s %d]\n",month[Month-1],Year);
	//read and show income,expense
	fscanf(fp,"%f %f",&in,&out);
    printf("\n\t\t\t\t\t Income Total  : %.2f Baht \n",in);
    printf("\t\t\t\t\t Expense Total : %.2f Baht \n",out);
    fclose(fp);
    
    //To show Ranking
    float Cost[7],tempn;
    char Type[7][20]={"Food","Transport","Accommodation","Groceries","Services","Utilities","Others"},temps[20];
    //open file month-yearresult.txt
	strcat(strcat(strcpy(Filename,"storage/"),date),"result.txt");
	fp = fopen(Filename,"r");
	//title
	printf("\n\t\t\t\t\t Ranking of Expense \n");
	//read and get in Cost[]
	i=0;
	while(!feof(fp))
    {
		fscanf(fp,"%f",&Cost[i]);
        i++;
    }
    fclose(fp);
    //sorting Cost[] (Insertion Sort) 
    for(i=1;i<7;i++)
    {	
    	for(j=i;j-1>=0;j--)
		if(Cost[j]>Cost[j-1])
		{
			tempn=Cost[j];
            Cost[j]=Cost[j-1];
            Cost[j-1]=tempn;
	
			strcpy(temps,Type[j]);
            strcpy(Type[j],Type[j-1]);
            strcpy(Type[j-1],temps);
		}}
	//Show ranking
	for(i=0;i<7;i++)
		printf("\t\t\t\t\t %d. [%-13s] %-10.2f Baht\n",i+1,Type[i],Cost[i]);
	printf("\n");
	//show Alternative
	printf("\t\t\t\t\t--------------------------------------------\n");
	printf("\n\t\t\t\t\t Press any choice.\n\n");
	printf("\n\t\t\t\t\t 1: Show another month \n");
	printf("\t\t\t\t\t 0: Back to menu\n");
	//input choice
	int menu = InvalidInput_Int("\n\t\t\t\t\t Enter your choice: ",0,1,"\t\t\t\t\t Invalid choice! Please input again.");
	switch(menu){
			case 1: MonthlySum(); break;
			default: {printf("\n\t\t\t\t\t Back to menu \n"); 
					delay(1000);}break;
			}	
}

//Annual Summary Function
void AnnualSum()
{
	int Year,i=0,j;
	float in,out;
	char Filename[30],date[8];
	FILE *fp;
	
	system("cls");
	titlemenu3();
	//show Title
	printf("\n\t\t\t\t\t Annual Summary\n\n");
	//Input Year
	do{
	Year=InvalidInput_Int("\t\t\t\t\t Input Year  (back to menu Press 0): ",0,9999,"\t\t\t\t\t Invalid Year! Please input again.");
	if(Year==0) return;
	//open yeartotle.txt
	sprintf(date,"%d",Year);
	strcat(strcat(strcpy(Filename,"storage/"),date),"total.txt");
	if((fp = fopen(Filename,"r"))==NULL)
	{
		//clear screen, show title and input again
		system("cls");
		titlemenu3();
		printf("\n\t\t\t\t\t Annual Summary\n\n");
		printf("\t\t\t\t\t Not Found!!\n");
		printf("\t\t\t\t\t Please input again.\n");
		i=0;
	}
	else i=1;
	}while(i==0);
	
	int menugraph;
	do{
		system("cls");
		titlemenu3();
		//title
		printf("\n\t\t\t\t\t Annual Summary [%d]\n",Year);
		//To show income,expense
		fscanf(fp,"%f %f",&in,&out);
	    printf("\n\t\t\t\t\t Income Total  : %.2f Baht \n",in);
	    printf("\t\t\t\t\t Expense Total : %.2f Baht \n",out);
	    fclose(fp);
	    
	    //To show Ranking
	    float Cost[7],tempn;
	    char Type[7][20]={"Food","Transport","Accommodation","Groceries","Services","Utilities","Others"},temps[20];
	    //Open yearresult.txt
		strcat(strcat(strcpy(Filename,"storage/"),date),"result.txt");
	    fp = fopen(Filename,"r");
		//title
		printf("\n\t\t\t\t\t Ranking of Expense \n");
		//read and get in Cost[]
		i=0;
		while(!feof(fp))
	    {
			fscanf(fp,"%f",&Cost[i]);
	        i++;
	    }
	    fclose(fp);
	    //sorting Cost[] (Insertion Sort)
	    for(i=1;i<7;i++)
	    	for(j=i;j-1>=0;j--)
			if(Cost[j]>Cost[j-1])
			{
				tempn=Cost[j];
	            Cost[j]=Cost[j-1];
	            Cost[j-1]=tempn;
		
				strcpy(temps,Type[j]);
	            strcpy(Type[j],Type[j-1]);
	            strcpy(Type[j-1],temps);
			}
		//show ranking
		for(i=0;i<7;i++)
			printf("\t\t\t\t\t %d. [%-13s] %-10.2f Baht\n",i+1,Type[i],Cost[i]);
		
		//Alternative
		printf("\t\t\t\t\t--------------------------------------------\n");
		printf("\n\t\t\t\t\t Press any choice.\n\n");
		printf("\n\t\t\t\t\t 1: Show Income graph \n");
		printf("\t\t\t\t\t 2: Show Expenses graph\n");
		printf("\t\t\t\t\t 0: Back to menu\n");
		//input choice
		menugraph = InvalidInput_Int("\n\t\t\t\t\t Enter your choice: ",0,2,"\t\t\t\t\t Invalid choice! Please input again.");
		switch(menugraph){
				case 1: graph(Year,1); break;
				case 2: graph(Year,2); break;
				default: {printf("\n\t\t\t\t\t Back to menu \n"); 
							delay(1000);}break;
			}	
	}while(menugraph != 0);	
}
