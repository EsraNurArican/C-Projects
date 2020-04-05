/*ESRA NUR ARICAN*/
/*161044028*/
/*CSE 102 HW02 PART2*/

#include<stdio.h>

    int main(){
        int number,counter=0;
        
        /*To find digit of a number,i used % operator*/
        /*Number is taken from the user*/
        printf("Please enter a number between 23 - 98760\n");
        scanf("%d",&number);
        
        /*If statement finds digits for 5-digit numbers*/
        if(number >= 10000 && number<=98760){
        
            printf("The fifth digit is:%d\n",((number/10000) %10));
            printf("The fourth digit is:%d\n",((number/1000)%10));
            printf("The third digit is:%d\n",((number/100)%10));
            printf("The second digit is:%d\n",((number/10)%10));
            printf("The first digit is:%d\n",(number%10));
        }
        
        /*If statement finds digits for 4-digit numbers*/
        else if(number >= 1000 && number <= 9999){
        
            printf("The fourth digit is:%d\n",((number/1000)%10));
            printf("The third digit is:%d\n",((number/100)%10));
            printf("The second digit is:%d\n",((number/10)%10));
            printf("The first digit is:%d\n",(number%10));
        }
        
        /*If statement finds digits for 3-digit numbers*/
        else if(number >= 100 && number <= 999){
            printf("The third digit is:%d\n",((number/100)%10));
            printf("The second digit is:%d\n",((number/10)%10));
            printf("The first digit is:%d\n",(number%10));
        }
        
        /*If statement finds digits for 2-digit numbers*/
        else if(number >= 23 && number <= 99){
           
            printf("The second digit is:%d\n",((number/10)%10));
            printf("The first digit is:%d\n",(number%10));
        }
        
        /*If user enters wrong number,this statement will gives an error message*/
        else {
        
            printf("Wrong number!Number must be between 23 and 98760\n");
        }
        
    return 0;
    }
