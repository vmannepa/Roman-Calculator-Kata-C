#include<include/roman_to_decimal.h>

int romtodec_convert(char num){
    
    if(num == 'I'){
       
            return 1;
        }
        else if(num == 'V'){
            return 5;
        }
         else if(num == 'X'){
            return 10;
        }
         else if(num == 'L'){
            return 50;
        }
         else if(num == 'C'){
            return 100;
        }
         else if(num == 'D'){
            return 500;
        }
        else if(num == 'M'){
            return 1000;
        }
        else{
            return INVALID_NUMERAL;//cout << "invalid roman number\n"<<endl;
            
        }
       
}

int romtodec(char* rom){
     int a,b;
     int i=0,sum=0;
     while(rom[i] !='\0'){
	a=romtodec_convert(rom[i]);

         if(a == INVALID_NUMERAL){
		printf("INVALID NUMERAL \"%c\"\n",rom[i]);
		return INVALID_NUMERAL;
	}
        if(i==0)
            sum=sum+a;
        else {
            b= romtodec_convert(rom[i-1]);
            if(a<=b)
                sum=sum+a;
            else if(a>b){
                sum=sum+a;
                sum=sum-2*b;
            }
            else {;;}
           
            }
             i++;
        }
        return sum;
}
