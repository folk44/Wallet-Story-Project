#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <dos.h>
#include "income.h"
int balance;
int main()
{
	//Check file "balance.txt". If not, create one and set balance = 0.
	FILE *fp;
	if((fp = fopen("storage/balance.txt","r")) == NULL){
		fp = fopen("storage/balance.txt","w");
		fprintf(fp,"%d",0);
		fclose(fp);
	}
	
	//Open file balance.txt for getting balance.
	fp = fopen("storage/balance.txt","r");
	fscanf(fp,"%d",&balance);
	fclose(fp);
	
	int menu;
	char date[15] = {"\0"};
	do{
		system("cls");
		//Show date.
		getDate(date);
		printf("Date : %s\n",date);
		//Show Balance
		printf("Balance : %d\n",balance);
		
		//Display Menu
		printf("1: \n");
		printf("2: \n");
		printf("3: \n");
		printf("0: Exit\n");
		
		//Check valid menu. If invalid, inform to user.
		InvalidInput("\nEnter your choice: ",&menu,0,3);	
		
		//Go to selected menu.
		switch(menu){
			case 1: balance+=Menu1(); break;
			case 2: printf("Go to menu 2.\n"); break;
			case 3: Menu3(); break;
			default: printf("Thank you.");
		}
	}while(menu != 0);
	
	//Save balance into balance.txt.
	fp = fopen("storage/balance.txt","w+");
	fprintf(fp,"%d",balance);
	fclose(fp);
	
	return 0;
}
