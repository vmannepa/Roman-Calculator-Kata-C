#include <include/roman_calculator.h>
#include <include/roman_to_decimal.h>
#include <include/decimal_to_roman.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* roman_calculator(int dec1,int dec2, char symbol){
	int number;
	char *result_roman;
	//result_roman = (char*) malloc(10*sizeof(char));
	if(symbol == '+'){
	    number= dec1+dec2;
	    printf("%d\n",number);
	    result_roman = dectorom(number);
	}
	else if(symbol == '-'){
		if(dec1>=dec2)
			number = dec1-dec2;
		else if(dec1 < dec2)
			number = dec2-dec1;
		else 
			return 0;
	result_roman = dectorom(number);
	}
	else{;;}
return result_roman;
//free(result_roman);
}

