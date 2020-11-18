#include "income.h"
void Menu3()
{
	int menu3;
	do{
	system("cls");
	
	//Display Menu3
	printf("1: Monthly summary \n");
	printf("2: Annual summary\n");
	printf("0: Back to Main Menu\n");
	
	//Check valid menu. If invalid, inform to user.
	menu3 = InvalidInput("\nEnter your choice: ",0,2);
	
	//Go to selected menu.
		switch(menu3){
			case 1: MonthlySum(); break;
			case 2: AnnualSum(); break;
			default: printf("Back to Main Menu \n"); break;
		}
		delay(1000);
	}while(menu3 != 0);
	
}
void MonthlySum()
{
	int i,j,Month,Year;
	float in,out;
	char Filename[20],date[8];
	FILE *fp;
	
	//Input Month Year
	do{
	printf("Input Month/Year (back to MENU press 0/0): ");
	scanf("%d/%d",&Month,&Year);
	if(Month==0&&Year==0){
	return;}
	//change to mm-yyyy
	sprintf(date,"%02d-%d",Month,Year);
	
	//openfile
	strcat(strcat(strcpy(Filename,"storage/"),date),"total.txt");
	if((fp = fopen(Filename,"r"))==NULL)
	{
		printf("Not Found!!\n");
		printf("Please input again.\n");
		i=0;
	}
	else i=1;
	}while(i==0);
	
	//To show income,expense
	fscanf(fp,"%d %d",&in,&out);
    printf("Income Total  : %.2f Baht \n",in);
    printf("Expense Total : %.2f Baht \n",out);
    fclose(fp);
    
    //To show Ranking
    float Cost[7],tempn;
    char Type[7][20],temps[20];
    strcat(strcat(strcpy(Filename,"storage/"),date),"result.txt");
    fp = fopen(Filename,"r");
	printf("Ranking of Expense \n");
	i=0;
	while(!feof(fp))
    {
		fscanf(fp,"%s %d",Type[i],&Cost[i]);
        i++;
    }
    fclose(fp);
    for(i=1;i<7;i++)
    {	j=i;
    	for(;j-1==0;j--)
		if(Cost[j]>Cost[j-1])
		{
			tempn=Cost[j];
            Cost[j]=Cost[j-1];
            Cost[j-1]=tempn;
	
			strcpy(temps,Type[j]);
            strcpy(Type[j],Type[j-1]);
            strcpy(Type[j-1],temps);
		}}
	for(i=0;i<7;i++)
		printf("%d. [%-10s] %-10d \n",i+1,Type[i],Cost[i]);
	printf("press any key to back to Menu");
	system("pause");
	
}

void AnnualSum()
{
	int Year,i=0,j;
	float in,out;
	char Filename[20],date[8];
	FILE *fp;
	
	//Input Year
	do{
	printf("Input Year (back to MENU press 0): ");
	scanf("%d",&Year);
	if(Year==0) return;
	
	sprintf(date,"%d",Year);
	strcat(strcat(strcpy(Filename,"storage/"),date),"total.txt");
	if((fp = fopen(Filename,"r"))==NULL)
	{
		printf("Not Found!!\n");
		printf("Please input again.\n");
		i=0;
	}
	else i=1;
	}while(i==0);
	
	//To show income,expense
	fscanf(fp,"%d %d",&in,&out);
    printf("Income Total  : %.2f Baht \n",in);
    printf("Expense Total : %.2f Baht \n",out);
    fclose(fp);
    
    //To show Ranking
    float Cost[7],tempn;
    char Type[7][20],temps[20];
    strcat(strcat(strcpy(Filename,"storage/"),date),"result.txt");
    fp = fopen(Filename,"r");
	printf("Ranking of Expense \n");
	i=0;
	while(!feof(fp))
    {
		fscanf(fp,"%s %d",Type[i],&Cost[i]);
        i++;
    }
    fclose(fp);
    for(i=1;i<7;i++)
    	for(j=i;j-1==0;j--)
		if(Cost[j]>Cost[j-1])
		{
			tempn=Cost[j];
            Cost[j]=Cost[j-1];
            Cost[j-1]=tempn;
	
			strcpy(temps,Type[j]);
            strcpy(Type[j],Type[j-1]);
            strcpy(Type[j-1],temps);
		}
	for(i=0;i<7;i++)
		printf("%d. [%-10s] %-10d \n",i+1,Type[i],Cost[i]);
		
	//Show Graph
	
	
	printf("press any key to back to Menu");
	system("pause");
	return;
}
