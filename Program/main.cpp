#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main( )
{
	int menu, balance = 0;
	do{
		system("cls");
		printf("Balance : %d\n",balance);
		printf("1: \n");
		printf("2: \n");
		printf("3: \n");
		printf("0: Exit\n");
		do{
			printf("\nEnter your choice: ");
			scanf("%d",&menu);
			if(menu < 0 || menu > 3) printf("Invalid choice. Please try again.\n");
		}while(menu < 0 || menu > 3);
		switch(menu){
			case 1: printf("Go to menu 1.\n"); break;
			case 2: printf("Go to menu 2.\n"); break;
			case 3: printf("Go to menu 3.\n"); break;
			default: printf("Thank you.");
		}
		delay(300);
	}while(menu != 0);
	return 0;
}
