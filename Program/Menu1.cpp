#include "income.h"
int Input_Type_list(int);
bool Valid_daymonth(int,int);
int Menu1(){
	//inex: income or expense.
	//type: type of item.
	//amount: amount of money.
	//name: name of item.
	//detail: detail of item.
	struct list input;
	
	//Select menu.
	int menu,inex;
	float all_amount = 0;
	do{
		char filename[25] = "storage/";
		//Clear screen.
		system("cls");
		
		//Interface menu1.
		printf("1. Add item to list.\n");
		printf("0. Exit\n");
		menu = InvalidInput("Press : ",0,1);
		
		//If press 0, exit.
		if(menu == 0){
			printf("Back to Main Menu \n");
			delay(1000);
			break;
		}
		
		int sub_menu,chk_exit = 0;//For check user continue to input.
		do{
			system("cls");
			
			//Input Income of Expense.
			inex = InvalidInput("Income(Press 1) or Expense(Press 0) : ",0,1);
			
			//Input name.
			UserInput("Name",input.name);
			
			//Input type.(Separate income and expense)
			input.type = Input_Type_list(inex);
			
			//Input amount.
			printf("Amount : ");
			scanf("%f",&input.amount);
			
			//Input detail.
			UserInput("Detail(If not want, press Enter.)",input.detail);
			
			//Ask input date. If not, fill date.
			int chk_date;
			char date[15] = "\0";
			getDate(date);
			printf("Save in current date(%s)?\n",date);
			chk_date = InvalidInput("Press 1(Yes),0(No) : ",0,1);
			if(chk_date == 0){
				
				//Fill date.
				int day,month,year;
				printf("Input only number:\n");
				do{
					day = InvalidInput("Day  :",1,31);
					month = InvalidInput("Month : ",1,12);
					if(!(Valid_daymonth(day,month))) printf("Invalid choice. Please try again.\n");
				}while(!(Valid_daymonth(day,month)));
				year = InvalidInput("Year  : ",0,INT_MAX);
				sprintf(input.date,"%02d-%02d-%d",day,month,year);
			}
			else{
				getDate(input.date);
			}
			
			//Make sure user input correctly.
			system("cls");
			if(inex == 1) printf("\nIncome.\n");
			else printf("\nExpense.\n");
			printf("Name : %s\n",input.name);
			printf("Type : %d\n",input.type);
			printf("Amount : %.2f\n",input.amount);
			printf("Detail : %s\n",input.detail);
			printf("Date : %s\n",input.date);
			
			sub_menu = InvalidInput("Save?(Press 1(Yes),0(No)) : ",0,1);
			if(sub_menu == 0 && InvalidInput("Exit this page?(Press 1(Yes),0(No)) : ",0,1) == 1){
				chk_exit = 1;
				break;
			}
		}while(sub_menu == 0);
		
		if(chk_exit == 1) continue;
		
		//Set file name for putting input & Adding calculating balance.
		if(inex == 1){
			all_amount+=input.amount;
			strcat(filename,"in");
		}
		else{
			all_amount-=input.amount;
			strcat(filename,"out");
		}
		strcat(filename,input.date);
		strcat(filename,".txt");
		
		//Move into the file
		FILE *fp;
		fp = fopen(filename,"a+");
		fprintf(fp,"%s %d %f %s\n",input.name,input.type,input.amount,input.detail);
		fclose(fp);
		printf("Save successfully.\n");
		
		delay(1000);
	}while(menu != 0);
	
	return all_amount;
}

int Input_Type_list(int inex){
	int type_;
	char list_type_income [8][20] = {"Refund","Special","Revenue","Free","Business income","Withdraw","Borrow","Other"};
	char list_type_expense [7][20] = {"Food","Transport","Accommodation","Groceries","Services","Utilities","Others"};
	printf("Type: \n");
	if(inex == 1){
		for(int i = 0; i < 8; i++){
			printf("%d. %s\n",i+1,list_type_income[i]);
		}
		type_ = InvalidInput("Press : ",1,8);
	}
	else{
		for(int i = 0; i < 7; i++){
			printf("%d. %s\n",i+1,list_type_expense[i]);
		}
		type_ = InvalidInput("Press : ",1,7);
	}
	return type_;
}
bool Valid_daymonth(int day_,int month_){
	int month1[] = {1,3,5,7,8,10,12};
	int month2[] = {4,6,9,11};
	if(FindElement(month_,month1,7) && day_ > 31) return false;
	if(FindElement(month_,month2,4) && day_ > 30) return false;
	if(month_ == 2 && day_ > 28) return false;
	return true;
}
