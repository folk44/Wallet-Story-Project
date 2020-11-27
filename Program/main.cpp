#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <dos.h>
#include "income.h"
float balance;
int main()
{
	walletstory();
	//Check file "balance.txt". If not, create one and set balance = 0.
	FILE *fp;
	if((fp = fopen("storage/balance.txt","r")) == NULL){
		fp = fopen("storage/balance.txt","w");
		fprintf(fp,"%f",0);
		fclose(fp);
	}
	
	int menu;
	char date[15] = {"\0"};
	do{
		system("cls");
		//Open file balance.txt for getting balance.
		fp = fopen("storage/balance.txt","r");
		fscanf(fp,"%f",&balance);
		fclose(fp);
		//Show date.
		getDate(date); 
		Title();
		printf("\t\t\t\t\t\t\t  Main Menu\n");
		printf("\t\t\t\t\t--------------------------------------------\n");
		printf("\n\t\t\t\t\t Date : %s\n",date);
		//Show Balance
		printf("\t\t\t\t\t Balance : %.2f\n",balance);
		printf("\t\t\t\t\t********************************************\n");
		
		//Display Menu
		printf("\n\t\t\t\t\t Press any choice.\n\n");
		printf("\t\t\t\t\t 1: Note the income/expense menu.\n"); 
		printf("\t\t\t\t\t 2: Shows daily income & expense history.\n");
		printf("\t\t\t\t\t 3: Summary.\n");
		printf("\t\t\t\t\t 0: Exit.\n");
		
		//Check valid menu. If invalid, inform to user.
		menu = InvalidInput_Int("\n\t\t\t\t\t Enter your choice: ",0,3,"\t\t\t\t\t Invalid choice! Please input again.");
		
		//Go to selected menu.
		switch(menu){
			case 1: Menu1(); break;
			case 2: Menu2(); break;
			case 3: Menu3(); break;
			default: goodluck();
		}
	}while(menu != 0);
	
	return 0;
}
