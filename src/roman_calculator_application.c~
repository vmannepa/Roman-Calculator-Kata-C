#include <include/roman_calculator.h>
#include <include/roman_to_decimal.h>
#include <include/decimal_to_roman.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
	
	int dec1,dec2;
	
	char* roman1;
	char* roman2;
	roman1=(char*) calloc(20,sizeof(char));
	roman2=(char*) calloc(20,sizeof(char));
	char *result_roman;
	char symbol;
	printf("enter your mode of operation + or - \n");
	scanf("%c",&symbol);
	printf("Enter the first roman number\n");
	
	scanf("%s",roman1);
	dec1= romtodec(roman1);
	if(dec1 == INVALID_NUMERAL){
	printf("Contains invalid numeral\n");
	free(roman1);
	free(roman2);
	return 0;
	}	

	printf("Enter thr second roman number\n");
	scanf("%s",roman2);
	
	dec2= romtodec(roman2);
	if(dec2 == INVALID_NUMERAL){
	printf("Contains invalid numeral\n");
	free(roman1);
	free(roman2);
	return 0;
	}

	result_roman=roman_calculator(dec1,dec2,symbol);
	printf("Result : %s\n",result_roman);
	free(roman1);
	free(roman2);

	return 0;
}
