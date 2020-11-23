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
int InvalidInput(const char* text, int min_con, int max_con){
	int input;
	do{
		printf("%s",text);
		fflush(stdin);
		scanf("%d",&input);
		//Check valid choice.
		if(input < min_con || input > max_con) printf("Invalid choice. Please try again.\n"); //Inform user.
	}while(input < min_con || input > max_con);
	return input;
}
//Get date. All of these parameter are pointer.
void getDate(char* date){
	char day[3],month[3],year[5];
	
	//Get date, in the form of integer.
	time_t now = time(NULL);
	struct tm *local = localtime(&now);
	
	//Convert integer to string.
	sprintf(date,"%02d-%02d-%d",local->tm_mday,local->tm_mon+1,local->tm_year+1900);
}

bool FindElement(int element,int* arr,int arr_size){
	for(int i = 0; i < arr_size; i++){
		if(element == *arr) return true;
		arr++;
	}
	return false;
}
bool Valid_daymonth(int day_,int month_){
	int month1[] = {1,3,5,7,8,10,12};
	int month2[] = {4,6,9,11};
	if(FindElement(month_,month1,7) && day_ > 31) return false;
	if(FindElement(month_,month2,4) && day_ > 30) return false;
	if(month_ == 2 && day_ > 28) return false;
	return true;
}
