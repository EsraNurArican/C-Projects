/*ESRA NUR ARICAN*/
/*161044028*/
/*10.03.2018*/
/*CSE 102 HW02*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    
    int student_count=0 ,num_A=0 ,num_B=0 ,num_C=0 ,num_D=0 ,num_F=0;
    int grade=0, most_successful=0, most_unsuccessful=100, index1=0, index2=0;
    int i=0,selection,sum=0;
    double average_grade=0.0;
    srand(40);
    
    /*Student count is taken from the user*/
    printf("Enter the student count:\n"); 
    scanf("%d",&student_count);
    
    /*This while loop is written to control if the student count is in range or not*/
    while(student_count < 3 || student_count >50){ 
        printf("Not in range!\n");
        printf("Enter the student count:\n");
        scanf("%d",&student_count);
    }
    
    /*All informations will calculated in this loop*/
    for(i=1; i<= student_count; i++){
        
        /*Random function is called and the numbers are printed on the screen*/
        grade= rand()%101;
        printf("%d ",grade);
        
        /*To calculate current summary of all random numbers that generated*/
        sum =sum + grade;
       
        /*To calculate average grade;total sum is divided by the number of students*/
        average_grade= (double)sum/student_count;
       
        /*With else if statements each letter grade's numbers calculated by increasing counters*/
        if(grade >= 90 && grade <=100 )
            num_A++;
        else if(grade >= 80 && grade <=89)
            num_B++;
        else if(grade >= 70 && grade <=79)
            num_C++;
        else if(grade >= 60 && grade <=69)
            num_D++;
        else if(grade >= 0 && grade <=59)
            num_F++; 
        
        /*To calculate most successful and unsucccessful students numbers and their index*/
        if(grade > most_successful){
            most_successful= grade;
            index1=i;
        }
        if(grade < most_unsuccessful){
            most_unsuccessful=grade;
            index2=i; 
        } 
        
 
    }
    
    /* This while loop displays the menu until the user enter -1*/
    while(selection != -1){
        
        printf("-----------------------------------------------------\n");
        printf("STUDENT SCORE CALCULATOR MENU for %d STUDENTS\n\n",student_count);
        printf("1) Most Successful Student\n");
        printf("2) Most Unsuccessful Student\n");
        printf("3) Letter Grade Statistics\n");
        printf("4) Calculate Average\n");
        printf("5) Show All Data\n");
        printf("\t\t\t\t\t\t\t Make Selection:");
        scanf("%d",&selection);

        /*Switch case statement is used to determine to functions of options in the menu*/
        switch(selection){
        
        /*Shows most successfull student*/
        case(1):
            printf("Most Successfully Student:\n");
            printf("Index: %d\n",index1);
            printf("Score: %d\n",most_successful);
            break;
        
        /*Shows most unsuccesfull student*/
        case(2):
            printf("Most Unsuccessfully Student:\n");
            printf("Index: %d\n",index2);
            printf("Score: %d\n",most_unsuccessful);
            break;
        
        /*Shows Letter grade statistics*/    
        case(3):
            printf("%d Student got letter grade 'A'\n",num_A);
            printf("%d Student got letter grade 'B'\n",num_B);
            printf("%d Student got letter grade 'C'\n",num_C);
            printf("%d Student got letter grade 'D'\n",num_D);
            printf("%d Student got letter grade 'F'\n",num_F);
            break;
        
        /*Shows average grade of students*/    
        case(4):
            printf("The Average Grade of %d Students is: %f \n",student_count,average_grade);
            break;
            
        /*Shows all informations*/    
        case(5):
            printf("Most Successfully Student:\n");
            printf("Index: %d\n",index1);
            printf("Score: %d\n\n\n",most_successful);
            printf("Most Unsuccessfully Student:\n");
            printf("Index: %d\n",index2);
            printf("Score: %d\n\n\n",most_unsuccessful);
            printf("%d Student got letter grade 'A'\n",num_A);
            printf("%d Student got letter grade 'B'\n",num_B);
            printf("%d Student got letter grade 'C'\n",num_C);
            printf("%d Student got letter grade 'D'\n",num_D);
            printf("%d Student got letter grade 'F'\n\n\n",num_F);
            printf("The Average Grade of %d Students is: %f \n",student_count,average_grade);
            break;
            
        /*Statement that will allows if user enters -1,will exit the program*/
        case(-1):
            return 0;
            
        default:
            printf("Wrong Selection!\n");
            
        }
    }
    return 0;
}
