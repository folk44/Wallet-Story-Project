#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <dos.h>
#include "income.h"
void UserInput(char*);//For many input
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
	printf("Name : ");
	UserInput(name);
	//Input type.(Separate income and expense)
	
	//Input detail.
	printf("Detail(If not want, press Enter.) : ");
	UserInput(detail);
	//Input amount.
	printf("Amount : ");
	scanf("%d",&amount);
	
	printf("Name : %s\n",name);
	printf("Detail : %s\n",detail);
	printf("Amount : %d\n",amount);
}
void UserInput(char* input){
	fflush(stdin);
	gets(input);//Input.
	if(strcmp(input,"\0") == 0) strcpy(input,"-");//When input nothing.
	
	//Make text to Uppercase.
	for(int i = 0; i < strlen(input); i++){
		input[i] = toupper(input[i]);
	}
}
