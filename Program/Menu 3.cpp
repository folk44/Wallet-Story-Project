#include "income.h"
void Menu3()
{
	int menu3;
	do{
	system("cls");
	
	//Display Menu3
	printf("   Summary Menu\n\n");
	printf("1: Monthly Summary \n");
	printf("2: Annual Summary\n");
	printf("0: Back to Main Menu\n");
	
	//Check valid menu. If invalid, inform to user.
	menu3 = InvalidInput_Int("\nEnter your choice: ",0,2,"Invalid choice! Please input again.");
	
	//Go to selected menu.
		switch(menu3){
			case 1: MonthlySum(); break;
			case 2: AnnualSum(); break;
			default: printf("Back to Main Menu \n"); break;
		}
		delay(1000);
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
	printf("\t  Monthly Summary\n\n");
	//Input Month Year
	do{
		Month=InvalidInput_Int("Input Month (back to MENU press 0): ",0,12,"Invalid Month! Please input again.");
		if(Month==0){printf("\nBack to Menu \n");return;}
		Year=InvalidInput_Int("Input Year  (back to MENU press 0): ",0,9999,"Invalid Year! Please input again.");
		if(Year==0){printf("\nBack to Menu \n");return;}
		//change input to mm-yyyy
		sprintf(date,"%02d-%d",Month,Year);
		
		//openfile mouth-yeartotal.txt
		strcat(strcat(strcpy(Filename,"storage/"),date),"total.txt");
		if((fp = fopen(Filename,"r"))==NULL)
		{
			//clear screen, show title and input again
			system("cls");
			printf("\t  Monthly Summary\n\n");
			printf("Not Found!!\n");
			printf("Please input again.\n");
			i=0;
		}
		else i=1;
	}while(i==0);
	
	system("cls");
	//show Title 
	printf("   Monthly Summary [%s %d]\n",month[Month-1],Year);
	//read and show income,expense
	fscanf(fp,"%f %f",&in,&out);
    printf("\nIncome Total  : %.2f Baht \n",in);
    printf("Expense Total : %.2f Baht \n",out);
    fclose(fp);
    
    //To show Ranking
    float Cost[7],tempn;
    char Type[7][20]={"Food","Transport","Accommodation","Groceries","Services","Utilities","Others"},temps[20];
    //open file month-yearresult.txt
	strcat(strcat(strcpy(Filename,"storage/"),date),"result.txt");
	fp = fopen(Filename,"r");
	//title
	printf("\nRanking of Expense \n");
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
		printf("%d. [%-13s] %-10.2f Baht\n",i+1,Type[i],Cost[i]);
	printf("\n");
	//show Alternative
	printf("\n1: Show another month \n");
	printf("0: Back to Menu\n");
	//input choice
	int menu = InvalidInput_Int("\nEnter your choice: ",0,1,"Invalid choice! Please input again.");
	switch(menu){
			case 1: MonthlySum(); break;
			default: {printf("Back to Menu \n"); 
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
	//show Title
	printf("\t  Annual Summary\n\n");
	//Input Year
	do{
	Year=InvalidInput_Int("Input Year  (back to MENU press 0): ",0,9999,"Invalid Year! Please input again.");
	if(Year==0) return;
	//open yeartotle.txt
	sprintf(date,"%d",Year);
	strcat(strcat(strcpy(Filename,"storage/"),date),"total.txt");
	if((fp = fopen(Filename,"r"))==NULL)
	{
		//clear screen, show title and input again
		system("cls");
		printf("\t  Annual Summary\n\n");
		printf("Not Found!!\n");
		printf("Please input again.\n");
		i=0;
	}
	else i=1;
	}while(i==0);
	
	int menugraph;
	do{
		system("cls");
		//title
		printf("     Annual Summary [%d]\n",Year);
		//To show income,expense
		fscanf(fp,"%f %f",&in,&out);
	    printf("\nIncome Total  : %.2f Baht \n",in);
	    printf("Expense Total : %.2f Baht \n",out);
	    fclose(fp);
	    
	    //To show Ranking
	    float Cost[7],tempn;
	    char Type[7][20]={"Food","Transport","Accommodation","Groceries","Services","Utilities","Others"},temps[20];
	    //Open yearresult.txt
		strcat(strcat(strcpy(Filename,"storage/"),date),"result.txt");
	    fp = fopen(Filename,"r");
		//title
		printf("\nRanking of Expense \n");
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
			printf("%d. [%-13s] %-10.2f Baht\n",i+1,Type[i],Cost[i]);
		
		//Alternative
		printf("\n1: Show Income graph \n");
		printf("2: Show Expenses graph\n");
		printf("0: Back to Menu\n");
		//input choice
		menugraph = InvalidInput_Int("\nEnter your choice: ",0,2,"Invalid choice! Please input again.");
		switch(menugraph){
				case 1: graph(Year,1); break;
				case 2: graph(Year,2); break;
				default: {printf("Back to Menu \n"); 
							delay(1000);}break;
			}	
	}while(menugraph != 0);	
}
