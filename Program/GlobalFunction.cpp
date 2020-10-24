#include "income.h"
//For input many times. Only string. text for constant string not variable, input for input string variable.
void UserInput(const char* text,char* input){
	printf("%s : ",text);
	fflush(stdin);
	gets(input);//Input.
	if(strcmp(input,"\0") == 0) strcpy(input,"-");//When input nothing.
	
	//Make text to Uppercase.
	for(int i = 0; i < strlen(input); i++){
		input[i] = toupper(input[i]);
	}
}
//To check invalid input. text for constatn string, input for press number, min_con for the min number, max_con for the max number.
void InvalidInput(const char* text, int* input, int min_con, int max_con){
	do{
		printf("%s",text);
		scanf("%d",input);
		//Check valid choice.
		if(*input < min_con || *input > max_con) printf("Invalid choice. Please try again.\n"); //Inform user.
	}while(*input < min_con || *input > max_con);
}
//Get date. All of these parameter are pointer.
void getDate(int* day, int* month,int* year){
	time_t now = time(NULL);
	struct tm *local = localtime(&now);
	*day = local->tm_mday;
	*month = local->tm_mon+1;
	*year = local->tm_year+1900;
}
