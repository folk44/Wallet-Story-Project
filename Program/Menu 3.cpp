#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "income.h"

void Menu3()
{
	int menu3;
	do{
	system("cls");
	
	//Display Menu3
	printf("1: Monthly summary \n");
	printf("2: Annual summary\n");
	printf("0: Back to Main Menu\n");
	
	//Check valid menu. If invalid, inform to user.
	do{
		printf("\nEnter your choice: ");
		scanf("%d",&menu3);
		if(menu3<0 || menu3>2) printf("Invalid choice. Please try again.\n");
	}while(menu3<0 || menu3>2);
	
	//Go to selected menu.
		switch(menu3){
			case 1: printf("Go to Monthly Summary \n"); break;
			case 2: printf("Go to Annual Summary \n"); break;
			default: printf("Back to Main Menu \n"); break;
		}
		delay(1000);
	}while(menu3 != 0);
	
}
