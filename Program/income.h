#include <graphics.h>
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <dos.h>
#include <limits.h>
// Go to Menu1
void Menu1();
//Go to Menu2
//void Menu2();
//Go to Menu3
void Menu3();
void UserInput(const char*,char*);
int InvalidInput(const char*, int, int);
void getDate(char*);
bool FindElement(int,int*,int);
bool Valid_daymonth(int,int);

struct list{
	//inex: income or expense.
	//type: type of item.
	//amount: amount of money.
	//name: name of item.
	//detail: detail of item.
	int type,inout;
	float amount;
	char name[50], detail[100], date[15];
};
