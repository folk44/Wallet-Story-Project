#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <dos.h>
#include "income.h"
void Type_list(int*);
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
	Type_list(&type);
	
	//Input detail.
	UserInput("Detail(If not want, press Enter.) : ",detail);
	//Input amount.
	printf("Amount : ");
	scanf("%d",&amount);
	
	printf("%d",type);
}
void Type_list(int* type_){
	char list_type [7][20] = {"Food","Transport","Accommodation","Groceries","Services","Utilities","Others"};
	printf("Type: \n");
	for(int i = 0; i < 7; i++){
		printf("%d. %s\n",i+1,list_type[i]);
	}
	InvalidInput("Press : ",type_,1,8);
}
