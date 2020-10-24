#include "income.h"
void Type_list(int,int*);
void Menu1(){
	//inex: income or expense.
	//type: type of item.
	//amount: amount of money.
	//name: name of item.
	//detail: detail of item.
	struct list input;
	
	//Select menu.
	int menu,inex;
	do{
		//Clear screen.
		system("cls");
		
		//Interface menu1.
		printf("1. Add item to list.\n");
		printf("0. Exit\n");
		InvalidInput("Press : ",&menu,0,1);
		
		//If press 0, exit.
		if(menu == 0){
			printf("Back to Main Menu \n");
			delay(1000);
			break;
		}
		
		do{
			system("cls");
			//Input Income of Expense.
			InvalidInput("Income(Press 1) or Expense(Press 0) : ",&inex,0,1);
			
			//Input each list.
			//Input name.
			UserInput("Name",input.name);
			
			//Input type.(Separate income and expense)
			Type_list(inex,&input.type);
			
			//Input detail.
			UserInput("Detail(If not want, press Enter.)",input.detail);
			//Input amount.
			printf("Amount : ");
			scanf("%d",&input.amount);
			
			//Make sure user input correctly.
			if(inex == 1) printf("\nIncome.\n");
			else printf("\nExpense.\n");
			printf("Name : %s\n",input.name);
			printf("Type : %d\n",input.type);
			printf("Detail : %s\n",input.detail);
			printf("Amount : %d\n",input.amount);
			InvalidInput("Do you want to save?(Press 1(Yes),0(No)) : ",&menu,0,1);
		}while(menu == 0);
		
		/*
		//Set file name for putting input.
		if(input.inex == 1){
			
		}
		else{
			
		}
		
		//Move into the file
		*/
		
		printf("Save successfully.\n");
		
		delay(1000);
	}while(menu != 0);
}

void Type_list(int inex , int* type_){
	char list_type_income [8][20] = {"Refund","Special","Revenue","Free","Business income","Withdraw","Borrow","Other"};
	char list_type_expense [7][20] = {"Food","Transport","Accommodation","Groceries","Services","Utilities","Others"};
	printf("Type: \n");
	if(inex == 1){
		for(int i = 0; i < 8; i++){
			printf("%d. %s\n",i+1,list_type_income[i]);
		}
		InvalidInput("Press : ",type_,1,8);
	}
	else{
		for(int i = 0; i < 7; i++){
			printf("%d. %s\n",i+1,list_type_expense[i]);
		}
		InvalidInput("Press : ",type_,1,7);
	}
}
