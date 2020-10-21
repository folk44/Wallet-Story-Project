#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <dos.h>
#include "income.h"
void Menu1(){
	//Clear screen.
	system("cls");
	
	//inex: income or expense.
	//type: type of item.
	//amount: amount of money.
	//name: name of item.
	//detail: detail of item.
	int inex, type, amount;
	char name[50], detail[100];
	
	printf("\nAdd item to list.\n\n");
	
	//Input Income of Expense.
	do{
		printf("Income(Press 1) or Expense(Press 0) : ");
		scanf("%d",&inex);
		//Check valid choice.
		if(inex != 1 && inex != 0) printf("Invalid choice. Please try again.\n"); //Inform user.
	}while(inex != 1 && inex != 0);
	
	//Input each list.
	//Input name.
	UserInput("Name",name);
	//Input type.(Separate income and expense)
	
	//Input detail.
	UserInput("Detail(If not want, press Enter.) : ",detail);
	//Input amount.
	printf("Amount : ");
	scanf("%d",&amount);
	
	//For check variable.
	/*
	printf("Name : %s\n",name);
	printf("Detail : %s\n",detail);
	printf("Amount : %d\n",amount);
	*/
}
