#include "income.h"
//For input many times. Only string. text for constant string not variable, input for input string variable.
void UserInput(const char* text,char* input){
	printf("%s : ",text);
	fflush(stdin);
	gets(input);//Input.
	if(strcmp(input,"\0") == 0) strcpy(input,"-");//When input nothing.
	//Make first alphabet to uppercase.
	*input = toupper(*input);
}
//To check invalid input. text for constatn string, input for press number, min_con for the min number, max_con for the max number,texterror for text.
int InvalidInput_Int(const char* text, int min_con, int max_con,const char* texterror){
	int input, chk; 
	do{
		//Check input error.
		chk = 1;
	    // To read input 
	    char value[100] = ""; 
	  
	    // To store numeric value of input if a  
	    // number (float or integer) 
	    double temp;  
	  
	    // Precision for integer checking 
	    double val = 1e-12; 
	  	
	  	//Input.
	    printf("%s",text);
		fflush(stdin);
		gets(value);
	  
	    // Check for integers. 
	    if (sscanf(value, "%lf", &temp) == 1)  
	    { 
	        input = (int)temp; // typecast to int.
	        //Check float.
	        if (fabs(temp - input) / temp > val)  
	            chk = 0;   
	    } 
	   
	    else chk = 0;
	
		//Check valid choice.
		if(!chk || input < min_con || input > max_con) printf("%s \n",texterror); //Inform user.//Invalid choice. Please try again.
	}while(!chk || input < min_con || input > max_con);
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
