#include "income.h"
void Showtable(struct list, char* ,char*);
void Menu2(){
	
	struct list table;
	int menu;
	
	do{
		system("cls");
		
		//Interface & Choose option.
		printf("\n");
		printf(" Show table menu.\n");
		printf("\nPress any choice.\n\n");
		printf(" 1. Show table.\n");
		printf(" 0. Exit.\n");
		menu = InvalidInput("\nPress : ",0,1);
		
		//If press 0. Exit
		if(menu == 0){
			printf("Back to Main Menu \n");
			delay(1000);
			break;
		}
		
		//Get day of this day.
		getDate(table.date);
		
		int sub_menu;
		do{
			//Setting file name.
			char file_in[30] = "storage/";
			char file_out[30] = "storage/";
			
			//Set outcome file name following by input date.
			strcat(file_out,table.date);
			strcat(file_out,"out.txt");
			
			//Set income file name following by input date.
			strcat(file_in,table.date);
			strcat(file_in,"in.txt");	
			
			//Display table.
			Showtable(table,file_in,file_out);
			
			sub_menu = InvalidInput("\nDo you want to see another date?(Press 1(Yes),0(No)) : ",0,1);
			
			//If not, exit this page.
			if(sub_menu == 0) break;
			
			//Get wanted date.
			int day,month,year;
			printf("Input only number:\n");
			do{
				day = InvalidInput("Day  :",1,31);
				month = InvalidInput("Month : ",1,12);
				if(!(Valid_daymonth(day,month))) printf("Invalid choice. Please try again.\n");
			}while(!(Valid_daymonth(day,month)));
			year = InvalidInput("Year  : ",0,INT_MAX);
			sprintf(table.date,"%02d-%02d-%d",day,month,year);				
		}while(sub_menu != 0);
			
		
	}while(menu!=0);
	
}
void Showtable(struct list table_,char* in, char* out){
	FILE *fp;
	float in_amount = 0, out_amount = 0;
	system("cls");
	
	printf("\nDate : %s\n",table_.date);
	
	//Check income or expense file exist.
	if((fp = fopen(in,"r")) == NULL && (fp = fopen(out,"r")) == NULL){
		printf("\nNo information to display.\n");
		return;
	}
	
	char type_income [8][20] = {"Refund","Special","Revenue","Free","Business income","Withdraw","Borrow","Other"};
	char type_expense [7][20] = {"Food","Transport","Accommodation","Groceries","Services","Utilities","Others"};
	
	//Show header.
	printf("\n%-20s %-10s %-10s %-50s\n","List","Income","Expense","Detail");
	//If income file exist.
	if((fp = fopen(in,"r")) != NULL){
		while(!feof(fp)){
			char text[20] = "[";//For [Type]Name
			char ch;//For character in Name.
			int exit = 0;
			
			//Get information
			//Get Name
			int i = 0;
			for( ; ;i++){
				ch = fgetc(fp);
				//Condition check all character
				if(ch == '|') break;
				//Check end of file.
				if(ch == EOF){
					exit = 1;
					break;
				}
				table_.name[i] = ch;
			}
			//End of file, then exit.
			if(exit == 1) break;
			
			//Make variable 'name' to string.
			table_.name[i] = '\0';
			
			//Get Type and Amount		
			fscanf(fp," %d %f ",&table_.type,&table_.amount);
			
			//Get Detail.
			i = 0;
			for( ; ;i++){
				ch = fgetc(fp);
				//Condition check all character
				if(ch == '|') break;
				table_.detail[i] = ch;
			}
			//Make variable 'detail' to string.
			table_.detail[i] = '\0';
			
			//Move cursor to next line.
			ch = fgetc(fp);
			
			//Increase total income.
			in_amount+=table_.amount;
			
			//Set text.
			strcat(text,type_income[table_.type]);
			strcat(text,"]");
			strcat(text,table_.name);
			
			//Display	
			printf("%-20s %-10.2f %-10s %-50s\n",text,table_.amount,"-",table_.detail);
		}
		fclose(fp);			
	}
	
	//If expense file exist.
	if((fp = fopen(out,"r")) != NULL){
		while(!feof(fp)){
			char text[20] = "[";//For [Type]Name
			char ch;//For character in Name.
			int exit = 0;
			
			//Get information
			//Get Name
			int i = 0;
			for( ; ;i++){
				ch = fgetc(fp);
				//Condition check all character
				if(ch == '|') break;
				//Check end of file.
				if(ch == EOF){
					exit = 1;
					break;
				}
				table_.name[i] = ch;
			}
			//End of file, then exit.
			if(exit == 1) break;
			
			//Make variable 'name' to string.
			table_.name[i] = '\0';
			
			//Get Type and Amount		
			fscanf(fp," %d %f ",&table_.type,&table_.amount);
			
			//Get Detail.
			i = 0;
			for( ; ;i++){
				ch = fgetc(fp);
				//Condition check all character
				if(ch == '|') break;
				table_.detail[i] = ch;
			}
			//Make variable 'detail' to string.
			table_.detail[i] = '\0';
			
			//Move cursor to next line.
			ch = fgetc(fp);
			
			//Increase total income.
			out_amount+=table_.amount;
			
			//Set text.
			strcat(text,type_expense[table_.type]);
			strcat(text,"]");
			strcat(text,table_.name);
			
			//Display	
			printf("%-20s %-10s %-10.2f %-50s\n",text,"-",table_.amount,table_.detail);
		}
		fclose(fp);
	}
	printf("\n%-20s %-10.2f %-10.2f\n","Total",in_amount,out_amount);
	printf("\nBalance = %.2f\n",in_amount-out_amount);
}
