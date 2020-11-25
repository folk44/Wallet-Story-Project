#include "income.h"
//For input type according to income or expense.
int Input_Type_list(int);
//Save to dd-mm-yy(in or out).txt
void Save_inout(struct list);
//Save to mm-yytotal.txt and yytotal.txt for save income and expense.
void Save_total(struct list);
//Save to mm-yy.txt and yytotal.txt for save income and expense.
void Save_result(struct list);
void Menu1(){
	FILE *fp;
	struct list input;
	char type_income [8][20] = {"Refund","Special","Revenue","Free","Business income","Withdraw","Borrow","Other"};
	char type_expense [7][20] = {"Food","Transport","Accommodation","Groceries","Services","Utilities","Others"};
	
	//Select menu.
	int menu;
	float balance;//all_amount for save amount while do in funciotn, balance for save
	do{
		//Clear screen.
		system("cls");
		
		//Interface menu1.
		printf("\n");
		printf(" Note the income/expense menu.\n");
		printf("\nPress any choice.\n\n");
		printf(" 1. Add item to list.\n");
		printf(" 0. Exit\n");
		menu = InvalidInput("\nPress : ",0,1);
		
		//If press 0, exit.
		if(menu == 0){
			printf("Back to Main Menu \n");
			delay(1000);
			break;
		}
		
		int sub_menu,chk_exit = 0;//For check user continue to input.
		do{
			system("cls");
			
			printf("\nNote : \n\n");
			//Input Income of Expense.
			input.inout = InvalidInput("  Income(Press 1) or Expense(Press 0) : ",0,1);
			
			//Input name.
			UserInput("  Name",input.name);
			
			//Input type.(Separate income and expense)
			input.type = Input_Type_list(input.inout);
			
			//Input amount.
			printf("  Amount : ");
			scanf("%f",&input.amount);
			
			//Input detail.
			UserInput("  Detail(If not want, press Enter.)",input.detail);
			
			//Ask input date. If not, fill date.
			int chk_date;
			char date[15] = "\0";
			getDate(date);
			printf("\nSave in current date(%s)?\n",date);
			chk_date = InvalidInput("Press 1(Yes),0(No) : ",0,1);
			if(chk_date == 0){
				
				//Fill date.
				int day,month,year;
				printf("  Input only number:\n");
				do{
					day = InvalidInput("  Day  :",1,31);
					month = InvalidInput("  Month : ",1,12);
					if(!(Valid_daymonth(day,month))) printf("Invalid choice. Please try again.\n");
				}while(!(Valid_daymonth(day,month)));
				year = InvalidInput("  Year  : ",0,INT_MAX);
				sprintf(input.date,"%02d-%02d-%d",day,month,year);
			}
			else{
				getDate(input.date);
			}
			
			//Make sure user input correctly.
			system("cls");
			printf("\nList : ");
			if(input.inout == 1) printf("\n  Income.\n");
			else printf("\n  Expense.\n");
			printf("  Name : %s\n",input.name);
			if(input.inout == 1) printf("  Type : %s\n",type_income[input.type]);
			else printf("  Type : %s\n",type_expense[input.type]);
			printf("  Amount : %.2f\n",input.amount);
			printf("  Detail : %s\n",input.detail);
			printf("  Date : %s\n",input.date);
			
			sub_menu = InvalidInput("Save?(Press 1(Yes),0(No)) : ",0,1);
			if(sub_menu == 0 && InvalidInput("Exit this page?(Press 1(Yes),0(No)) : ",0,1) == 1){
				chk_exit = 1;
				break;
			}
		}while(sub_menu == 0);
		
		if(chk_exit == 1) continue;
		
		Save_inout(input);
		Save_total(input);
		if(input.inout == 0) Save_result(input);
		
		//Read file balance.txt
		fp = fopen("storage/balance.txt","r");
		fscanf(fp,"%f",&balance);
		fclose(fp);
		
		//Save balance into balance.txt.
		fp = fopen("storage/balance.txt","w+");
		if(input.inout == 1) fprintf(fp,"%f",balance+input.amount);
		else fprintf(fp,"%f",balance-input.amount);
		
		fclose(fp);
		
		printf("Save successfully.\n");
		
		delay(1000);
	}while(menu != 0);
}

int Input_Type_list(int inout){
	int type_;
	char list_type_income [8][20] = {"Refund","Special","Revenue","Free","Business income","Withdraw","Borrow","Other"};
	char list_type_expense [7][20] = {"Food","Transport","Accommodation","Groceries","Services","Utilities","Others"};
	printf("  Type: \n");
	if(inout == 1){
		for(int i = 0; i < 8; i++){
			printf("  %d. %s\n",i+1,list_type_income[i]);
		}
		type_ = InvalidInput("  Press : ",1,8);
	}
	else{
		for(int i = 0; i < 7; i++){
			printf("  %d. %s\n",i+1,list_type_expense[i]);
		}
		type_ = InvalidInput("  Press : ",1,7);
	}
	return type_-1;
}

void Save_inout(struct list input){
	FILE *fp;
	char filename[25] = "storage/";	
	
	strcat(filename,input.date);
	
	//Check income or expense.
	if(input.inout == 1) strcat(filename,"in");
	else strcat(filename,"out");
	
	strcat(filename,".txt");
	
	//Save into the income or expense file.
	fp = fopen(filename,"a+");
	fprintf(fp,"%s| %d %f %s|\n",input.name,input.type,input.amount,input.detail);
	fclose(fp);
}

void Save_total(struct list input){
	FILE *fp;
	//Income and expense.
	float in = 0,out = 0;
	char filename[25] = "storage/";
	
	//mm-yytotal.txt
	for(int i = 3; i < strlen(input.date); i++) strncat(filename,&input.date[i],1);
	
	strcat(filename,"total.txt");
	
	if((fp = fopen(filename,"r")) != NULL){
		fscanf(fp,"%f %f",&in,&out);
	}
	
	fp = fopen(filename,"w");
	if(input.inout == 1) fprintf(fp,"%f %f",in+input.amount,out);
	else fprintf(fp,"%f %f",in,out+input.amount);
	fclose(fp);
	
	
	//Reset income and expense for save to newfile
	in = 0; out = 0;
	strcpy(filename,"storage/");
	
	//yytotal.txt
	for(int i = 6; i < strlen(input.date); i++) strncat(filename,&input.date[i],1);
	strcat(filename,"total.txt");
	
	if((fp = fopen(filename,"r")) != NULL){
		fscanf(fp,"%f %f",&in,&out);
	}
	
	fp = fopen(filename,"w");
	if(input.inout == 1) fprintf(fp,"%f %f",in+input.amount,out);
	else fprintf(fp,"%f %f",in,out+input.amount);
	fclose(fp);
	
}

void Save_result(struct list input){
	FILE *fp;
	//Amount of each type(First set to zero).
	float amount[7] = {0};
	char filename[25] = "storage/";
	
	//mm-yyresult.txt
	for(int i = 3; i < strlen(input.date); i++) strncat(filename,&input.date[i],1);
	strcat(filename,"result.txt");
	
	//If file exist, get amount of each type.
	if((fp = fopen(filename,"r")) != NULL){
		for(int i = 0; i < 7; i++) fscanf(fp,"%f ",&amount[i]);
	}
	fclose(fp);
	
	//Save to mm-yyresult.txt
	fp = fopen(filename,"w");
	for(int i = 0; i < 7; i++){
		if(i == input.type) fprintf(fp,"%f ",amount[i]+input.amount);
		else fprintf(fp,"%f ",amount[i]);
	}
	fclose(fp);
	
	
	//Reset for save to new file.
	strcpy(filename,"storage/");
	for(int i = 0; i < 7; i++) amount[i] = 0;
	
	//mm-yytotal.txt
	for(int i = 6; i < strlen(input.date); i++) strncat(filename,&input.date[i],1);
	strcat(filename,"result.txt");
	
	//If file exist, get amount of each type.
	if((fp = fopen(filename,"r")) != NULL){
		for(int i = 0; i < 7; i++) fscanf(fp,"%f ",&amount[i]);
	}
	fclose(fp);
	
	//Save to mm-yyresult.txt
	fp = fopen(filename,"w");
	for(int i = 0; i < 7; i++){
		if(i == input.type) fprintf(fp,"%f ",amount[i]+input.amount);
		else fprintf(fp,"%f ",amount[i]);
	}
	fclose(fp);
}
