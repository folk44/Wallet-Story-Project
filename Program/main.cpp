#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <dos.h>
#include "income.h"
int main(void)
{
	int menu, balance = 0;
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
			case 1: Menu1(); break;
			case 2: printf("Go to menu 2.\n"); break;
			case 3: Menu3(); break;
			default: printf("Thank you.");
		}
	}while(menu != 0);
	return 0;
}
