#include "income.h"
void Type_list(int*);
void Menu1(){
	//inex: income or expense.
	//type: type of item.
	//amount: amount of money.
	//name: name of item.
	//detail: detail of item.
	struct list input;
	
	//Select menu.
	int menu;
	do{
		//Clear screen.
		system("cls");
		
		//Interface menu1.
		printf("1. Add item to list.\n");
		printf("0. Exit\n");
		InvalidInput("Press : ",&menu,0,1);
		
		//If press 0, exit.
		if(menu == 0) break;
		
		
		system("cls");
		//Input Income of Expense.
		InvalidInput("Income(Press 1) or Expense(Press 0) : ",&input.inex,0,1);
		
		//Input each list.
		//Input name.
		UserInput("Name",input.name);
		
		//Input type.(Separate income and expense)
		Type_list(&input.type);
		
		//Input detail.
		UserInput("Detail(If not want, press Enter.)",input.detail);
		//Input amount.
		printf("Amount : ");
		scanf("%d",&input.amount);
		
		if(input.inex == 1) printf("\nIncome.\n");
		else printf("\nExpense.\n");
		printf("Name : %s\n",input.name);
		printf("Type : %d\n",input.type);
		printf("Detail : %s\n",input.detail);
		printf("Amount : %d\n",input.amount);
		
		delay(1000);
	}while(menu != 0);
}

void Type_list(int* type_){
	char list_type [7][20] = {"Food","Transport","Accommodation","Groceries","Services","Utilities","Others"};
	printf("Type: \n");
	for(int i = 0; i < 7; i++){
		printf("%d. %s\n",i+1,list_type[i]);
	}
	InvalidInput("Press : ",type_,1,8);
}
