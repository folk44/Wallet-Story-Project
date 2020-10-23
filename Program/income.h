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
//For input many times. Only string. text for constant string not variable, input for input string variable.
void UserInput(const char*,char*);
//To check invalid input. text for constatn string, input for press number, min_con for the min number, max_con for the max number.
void InvalidInput(const char*, int*, int, int);
struct list{
	int inex, type, amount;
	char name[50], detail[100];
};
