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
		printf("\n Date : %s\n",date);
		//Show Balance
		printf(" Balance : %.2f\n",balance);
		
		//Display Menu
		printf("\n Press any choice.\n\n");
		printf(" 1: Note the income/expense menu.\n");
		printf(" 2: Show the table.\n");
		printf(" 3: Summary.\n");
		printf(" 0: Exit.\n");
		
		//Check valid menu. If invalid, inform to user.
		menu = InvalidInput_Int("\nEnter your choice: ",0,3,"Invalid choice! Please input again.");
		
		//Go to selected menu.
		switch(menu){
			case 1: Menu1(); break;
			case 2: Menu2(); break;
			case 3: Menu3(); break;
			default: printf("Thank you.");
		}
	}while(menu != 0);
	
	return 0;
}
