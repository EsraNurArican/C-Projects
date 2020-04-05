/*ESRA NUR ARICAN*/
/*161044028*/
/*CSE 102 HW03*/

/*The libraries that will used*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
    
    /*Function decleration*/
    void menu();
    int getInt(int mini,int maxi);
    int numberGeneratorBetweenRange(int min,int max);
    void horseRacingGame();
    void countOccurence();
    void triangleOfSequences();
    
    int main(){
    srand(time(NULL));
    
    menu();

    return 0;
    }
    
    void menu(){
        int selection;
        
        /*In the menu do while structure used because menu has to be shown at least one time*/
        do{
            printf("\n*****MENU*****\n\n");
            printf("1.Horse Racing Game\n");
            printf("2.Occurence Counter\n");
            printf("3.Triangle of Sequences\n");
            printf("0.Exit\n\n");
            printf("Make a selection:");
            scanf("%d",&selection);
            
            /*Switch case statement used for calling functions according to selections*/
            switch(selection){
            
            case(1):
                horseRacingGame();
                break;
                
            case(2):
                countOccurence();
                break;
                
            case(3):
                triangleOfSequences();
                break;
            /*If 0 is entered,program stops*/    
            case(0):
                break;
               
            default:
                break;
            }
        }
        /*Until the 0 entered,menu will display again*/ 
        while(selection !=0);
    }
    
    /*Function that will takes integer from the user*/
    int getInt(int mini,int maxi){
        int takenInt;
    
        do{
            scanf("%d",&takenInt);
        }
        
        /*If taken number is not in range,function will take value again*/
        while(takenInt < mini || takenInt > maxi);
       /* printf("%d\n",takenInt);*/
        
    return takenInt;    
    }
    
    /*Function that generates random numbers between a range*/
    int numberGeneratorBetweenRange(int min, int max){
        int generatedNum;
        
        do{
             generatedNum = rand()%(max+1);
        
        }
        while(generatedNum < min || generatedNum > max);
      
       
    return generatedNum;   
    }
    
    /*A sub program function, is a horse racing game*/
    void horseRacingGame(){
        int numberOfHorse, horseNumber;
        int i=0,j,winnerHorse,horseScore,holdValue;
        int winnerScore=21;/*I started winnerScore from 21 because it will decrease as smaller values came*/
        
        numberOfHorse = numberGeneratorBetweenRange(3,5);
        printf("Number Of Horse:%d\n",numberOfHorse); /*This line will print number of horses that generated randomly*/
        printf("Horse Number:");
        horseNumber = getInt(1,numberOfHorse);/*Takes integer from user to define horse number*/
        printf("Racing starts...\n");
        
        /*For loop gives random values each horse and determines the winner horse and its Score*/
        for(i=1;i <= numberOfHorse; i++){
        
            /*calling function to create random numbers*/
            horseScore = numberGeneratorBetweenRange(10,20);
            
            /*If i equals to users horse number,variable holdValue will hold the
              value of that horse to compare with the winnerScore later*/
            if(i==horseNumber){
                holdValue=horseScore;
            }   
            printf("Horse %d:",i);
            /*For loop to print "-" as equal to horse's score*/
            for(j=1; j<=horseScore;j++){
                printf("-");
            }
            printf("\n");
            
            /*If statement to determine the winner horse and its index*/    
            if(horseScore <= winnerScore){
                winnerScore = horseScore;
                winnerHorse = i;/*To determine index*/
                   
            }

        }
        
        /*If statements to display winning situation on screen*/  
        /*In the comparison part the important thing is comparing values,
        if value is equal to the winner value,index(horseNumber) is not important*/          
        if(holdValue == winnerScore ){
            printf("You Win!\n");
        }
        else if(holdValue != winnerScore) {
            printf("You Lose!The winner horse is %d\n",winnerHorse);
        }            
            
    }
    
    /*Sub program function that computes number of occurrences of searchNumber in bigNumber.*/
    void countOccurence(){
        int bigNumber,searchNumber,number,digit,digitOccurence,mod;
        int countForDigit=0,countOccurence=0,i;
        printf("Big number:");
        scanf("%d",&bigNumber);
        printf("Search number:");
        scanf("%d",&searchNumber);
        
        number=searchNumber;
        /*To make calculation,we need to find search number includes how much digit*/
        while(number>0){
            
            digit= number%10;
            countForDigit++;
            number= number/10;
        }
        
        /*Mode taking operation will be done by number of digits in search number
        For ex:if search num includes 2 digit,we need to use %100*/
        mod=pow(10,countForDigit);
        
       while(bigNumber>0){
            digitOccurence=bigNumber% mod;
            if(digitOccurence == searchNumber){
                countOccurence++;/*Count for occurence*/
            }
            bigNumber=bigNumber/10;
                  
      }
        printf("Occurence:%d",countOccurence);
        
                
    }
    
    /*Sub program function that will generates a triangle of sequences*/    
    void triangleOfSequences(){
        int line,i,j;
        /*To determine the line number randomly*/
        line = numberGeneratorBetweenRange(2,10);
        printf("\nTriangle will print for:%d\n\n",line);
        
        /*For loop to generate triangle of series*/
        for(i=1; i<=line; i++){
            for(j=1; j<=i; j++){
                printf("%d  ",j*i);
            }
        printf("\n");        
        }
            
    }
