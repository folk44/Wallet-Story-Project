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
int Menu1();
//Go to Menu3
void Menu3();
void UserInput(const char*,char*);
int InvalidInput(const char*, int, int);
void getDate(char*);
bool FindElement(int,int*,int);

struct list{
	int type;
	double amount;
	char name[50], detail[100], date[15];
};
