#include <graphics.h>
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <dos.h>
// Go to Menu1
void Menu1();
//Go to Menu3
void Menu3();
void UserInput(const char*,char*);
void InvalidInput(const char*, int*, int, int);
void getDate(int*, int*,int*);

struct list{
	int type, amount, day, month, year;
	char name[50], detail[100];
};
