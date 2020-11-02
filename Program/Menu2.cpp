#include "income.h"
void Menu2(){
	
	struct list table;
	int menu;
	
	do{
		char file_in[30] = "storage/in";
		char file_out[30] = "storage/out";
		system("cls");
		
		//Choose option.
		printf("1. Show table.\n");
		printf("0. Exit\n");
		menu = InvalidInput("Press : ",0,1);
		
		//If press 0. Exit
		if(menu == 0){
			printf("Back to Main Menu \n");
			delay(1000);
			break;
		}
		
		system("cls");
		//Get date that want to show data.
		int day,month,year;
		printf("Input date(only number):\n");
		do{
			day = InvalidInput("Day  :",1,31);
			month = InvalidInput("Month : ",1,12);
			if(!(Valid_daymonth(day,month))) printf("Invalid choice. Please try again.\n");
		}while(!(Valid_daymonth(day,month)));
		year = InvalidInput("Year  : ",0,INT_MAX);
		sprintf(table.date,"%02d-%02d-%d",day,month,year);
		
		//Set outcome file name following by input date.
		strcat(file_out,table.date);
		strcat(file_out,".txt");
		
		//Set income file name following by input date.
		strcat(file_in,table.date);
		strcat(file_in,".txt");		
		
		
		//Display table.
		system("cls");
		
		printf("Date : %s\n",table.date);
		
		FILE *fp;
		//Check income or expense file exist.
		if((fp = fopen(file_in,"r")) == NULL && (fp = fopen(file_out,"r")) == NULL){
			printf("\nNo information to display.\n");
		}
		
		char type_income [8][20] = {"Refund","Special","Revenue","Free","Business income","Withdraw","Borrow","Other"};
		char type_expense [7][20] = {"Food","Transport","Accommodation","Groceries","Services","Utilities","Others"};
		
		//If income file exist.
		if((fp = fopen(file_in,"r")) != NULL){
			fp = fopen(file_in,"r");
			while(!feof(fp)){
				
				char type[8];
				fscanf(fp,"%s %d %f %s\n",&table.name,&table.type,&table.amount,&table.detail);				
				printf("%s %s %.2f %s\n",table.name,type_income[table.type - 1],table.amount,table.detail);
			}			
		}
		
		//If expense file exist.
		if((fp = fopen(file_out,"r")) != NULL){
			fp = fopen(file_out,"r");
			while(!feof(fp)){
				fscanf(fp,"%s %d %f %s\n",&table.name,&table.type,&table.amount,&table.detail);
				printf("%s %s -%.2f %s\n",table.name,type_expense[table.type - 1],table.amount,table.detail);
			}			
		}
		
		delay(5000);
		
		
	}while(menu!=1);
	
}
