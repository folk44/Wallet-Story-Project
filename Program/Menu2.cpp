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
		
		printf("%s\n",file_in);
		printf("%s\n",file_out);
		
		//Set outcome file name following by input date.
		strcat(file_out,table.date);
		strcat(file_out,".txt");
		
		//Set income file name following by input date.
		strcat(file_in,table.date);
		strcat(file_in,".txt");
		
		printf("%s\n",file_in);
		printf("%s\n",file_out);
		
		delay(5000);
		
		/*
		File *fp
		if((fp = fopen()))
		*/
	}while(menu!=1);
	
}
