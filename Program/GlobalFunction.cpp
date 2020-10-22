#include "GlobalFunction.h"
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
void InvalidInput(const char* text, int* input, int min_con, int max_con){
	do{
		printf("%s",text);
		scanf("%d",input);
		//Check valid choice.
		if(*input < min_con || *input > max_con) printf("Invalid choice. Please try again.\n"); //Inform user.
	}while(*input < min_con || *input > max_con);
}
