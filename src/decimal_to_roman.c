#include <include/decimal_to_roman.h>

char* dectorom(int num){
    int i=0;
    //char rom_1[10];
    char *rom;
    //rom=rom_1;
    char *ar1[10];
    ar1[1]="I";
    ar1[2]="II";
    ar1[3]="III";
    ar1[4]="IV";
    ar1[5]="V";
    ar1[6]="VI";
    ar1[7]="VII";
    ar1[8]="VIII";
    ar1[9]="IX";
	rom = (char*) calloc(10,sizeof(char));
    if(num == 0)
	return "INVALID";
    while(num != 0){
        if(num >=1000){
            rom[i]='M';
	    i++;
            num=num-1000;
        }
        else if(num >=900){
            strcat(rom,"CM");
	    i+=2;
            num=num-900;
        }
        else if(num >=500){
            rom[i]='D';
	i++;
            num=num-500;
        }
        else if(num >=400){
            strcat(rom,"CD");
	i+=2;
            num=num-400;
        }
        else if(num >=100){
            rom[i]='C';
		i++;
	
           num=num-100;
        }
        else if(num >=90){
            strcat(rom,"XC");
	i+=2;
            num=num-90;
        }
        else if(num >=50){
            rom[i]='L';
	i++;
            num=num-50;
        }
        else if(num >=40){
            strcat(rom,"XL");
	i+=2;
            num=num-40;
        }
        else if(num >=10){
            rom[i]='X';

	i++;
            num=num-10;
        }
        else{
            strcat(rom,ar1[num%10]);
            num=num-num%10;
	i+=2;
        }
        
    }
	printf("%s\n",rom);

    return rom;
free(rom);
    
}

