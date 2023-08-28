/*
 * main.c
 *
 *  Created on: May 3, 2023
 *      Author: Aya farid
 */
#include "../Services/STD_types.h"
#include "../Services/errorState.h"
#include "../MCAL/DIO/DIO_int.h"
#include "../HAL/LCD/LCD_int.h"
#include "util/delay.h"
#define MAX_SIZE     15
void int_to_string(unsigned long num,char string[MAX_SIZE]);
int string_to_int(char * string);
int main(){
	DIO_enuInit();
	LCD_enuInit();
	Keypad_enuInit();
	while(1){
		u8 keyPressed=0xff,num1[MAX_SIZE],num2[MAX_SIZE],operation,count1=0,count2=0;
		double num11,num22,result=0;
		LCD_String("Type your clac:");
		LCD_Line_Column(2,1);
		while(1){
			do{
				KP_GetPressed(&keyPressed);
			}while(keyPressed==0xff);
			if(keyPressed=='/'||keyPressed=='+'||keyPressed=='x'||keyPressed=='-'){
				operation=keyPressed;
				LCD_enuDisplayChar(keyPressed);
				break;
			}
			if(keyPressed=='c')
				goto clear;
			num1[count1]=keyPressed;
			count1++;
			LCD_enuDisplayChar(keyPressed);
		}
		while(1){
			do{
				KP_GetPressed(&keyPressed);
			}while(keyPressed==0xff);
			if(keyPressed=='='){
				LCD_enuDisplayChar(keyPressed);
				break;
			}
			if(keyPressed=='c')
				goto clear;
			num2[count2]=keyPressed;
			count2++;
			LCD_enuDisplayChar(keyPressed);
		}
		num11=string_to_int(num1);
		num22=string_to_int(num2);
		switch(operation){
		case '-':
			result=num11-num22;
			break;
		case '+':
			result=num11+num22;
			break;
		case 'x':
			result=num11*num22;
			break;
		case '/':
			result=num11/num22;
		}
		u8* test="";
		if(result<0){
			result*=-1;
		}
		if(operation=='-'){
			if(num11<num22){
				LCD_String(" -");
			}
		}
		int_to_string(result,test);
		LCD_String(test);
		next:
		do{
			KP_GetPressed(&keyPressed);
		}while(keyPressed==0xff);
		if(keyPressed!='c'){
			goto next;
		}
		clear:
		LCD_Clear();
		for(int i=0;i<MAX_SIZE;i++){
			num1[i]=num2[i]=0;
		}


	}
}
void int_to_string(unsigned long num,char string[MAX_SIZE])
{
    unsigned long len = 0;
    unsigned  long rem ;
    unsigned long tnum = num;
    while (tnum != 0){
        tnum /= 10;
        len++;
    }
    for (int i = 0; i < len; i++){
        rem = num % 10;
        num = num / 10;
        string[len - (i + 1)] = rem + '0';
    }
    string[len] = '\0';

}
int string_to_int(char * string){
	int length=strlen(string),pro=1,num=0;
	for(int i=length-1;i>=0;i--){
		num+=(string[i]-'0')*pro;
		pro*=10;
	}
	return num;
}

