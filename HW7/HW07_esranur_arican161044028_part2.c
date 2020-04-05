/*ESRA NUR ARICAN*/
/*161044028*/
/*HW07 PART 2*/

#include<stdio.h>

/*Declaration of the functions that will be use*/
int if_year_is_leap(int year);
int change_write_dates(void);
void create_dates(void);
int convert_date_to_day(int day,int month,int year);

/*Main function calls the functions which are gives dates and converts dates to day*/
int main(){

    create_dates();
    change_write_dates();
    

return 0;
}
/*This function checks if the year is leap or not*/
/*if_year_is_leap function will be use for calculations*/
int if_year_is_leap(int year){
    if(year %400 == 0){
        return 1;
    }
    else if(year %4== 0 && year %100 != 0){
        return 1;
    }
    else
        return 0;
}
/*This function reads lines from the file input.txt and 
 *calls the convert day function to print converted dates to new_date.txt file*/
int change_write_dates(void){
    
    FILE *input;
    int day = 0,month = 0,year=0;

    int fscanf_output = 0;

    input = fopen("input_date.txt","r");
    if (input == NULL)
    {
        printf ("Error opening the file\n\n'");
        return -1;
    }
    fscanf_output= fscanf(input, "%d/%d/%d\n", &day,&month,&year);
    while (fscanf_output != EOF)
    {
        
        convert_date_to_day(day,month,year);
        fscanf_output = fscanf(input, "%d/%d/%d\n", &day,&month,&year);
    }
    fclose(input);

}

/*This function takes two date from user and generates all dates (day by day) between these two dates.
 * Prints those dates to the file input.txt*/
void create_dates(void){

    FILE *input,*output;


    int day1,day2,month1,month2,year1,year2;
    char slash1,slash2,slash3,slash4;
    /*i=day, j=month, k=year*/
    int i,j,k;

    input=fopen("input_date.txt","w");
    if (input == NULL)
    {
        printf ("Error opening the file\n\n'");
    }
    output=fopen("new_date.txt","w");
    if (output == NULL)
    {
        printf ("Error opening the file\n\n'");
    }
    fclose(output);

    printf("Enter your start date in format dd/MM/yyyy\n");
    scanf("%d %c %d %c %d",&day1,&slash1,&month1,&slash2,&year1);
    printf("Enter your end date in format dd/MM/yyyy\n");
    scanf("%d %c %d %c %d",&day2,&slash3,&month2,&slash4,&year2);

    /*General for loop includes 3 for loop as control years,months and days(with if statements to control month's days(30,31,28))*/
    for(i=year1; i<=year2; i++){
        
        if(i == year1 && year1!=year2){

            for(j=month1; j<=12; j++){

                /*Months which has 31 day*/
                if(j==1 || j==3 || j==5 || j==7 || j==8 || j==10 || j==12){
                    for(k=day1; k<=31; k++){
                        printf("%d/%d/%d\n",k,j,i);        /*prints on the screen*/
                        fprintf(input,"%d/%d/%d\n",k,j,i); /*prints on the file*/
                    }
                }
                /*The number of days in the month of February should be check by using if_year_is_leap function*/
                else if(j==2){
                    if(if_year_is_leap(i)==1){
                        for(k=day1; k<=29; k++){
                            printf("%d/%d/%d\n",k,j,i);
                            fprintf(input,"%d/%d/%d\n",k,j,i);
                        }
                    }
                    else if(if_year_is_leap(i)==0){
                        for(k=day1; k<=28; k++){
                            printf("%d/%d/%d\n",k,j,i);
                            fprintf(input,"%d/%d/%d\n",k,j,i);
                        }
                    }

                }
                else{
                    for(k=day1; k<=30; k++){
                            printf("%d/%d/%d\n",k,j,i);
                            fprintf(input,"%d/%d/%d\n",k,j,i);
                    }
                }
            day1=1;
            }
        }
        /*This statement controls if the year is not end and start year,it prints between years as starting 1'th month to 12'th month*/
        else if(i!= year1 && i!= year2){
            for(j=1; j<=12; j++){

                /*Months which has 31 day*/
                if(j==1 || j==3 || j==5 || j==7 || j==8 || j==10 || j==12){
                    for(k=1; k<=31; k++){
                        printf("%d/%d/%d\n",k,j,i);        /*prints on the screen*/
                        fprintf(input,"%d/%d/%d\n",k,j,i); /*prints on the file*/
                    }
                }
                /*The number of days in the month of February should be check by using if_year_is_leap function*/
                else if(j==2){
                    if(if_year_is_leap(i)==1){
                        for(k=1; k<=29; k++){
                            printf("%d/%d/%d\n",k,j,i);
                            fprintf(input,"%d/%d/%d\n",k,j,i);
                        }
                    }
                    else if(if_year_is_leap(i)==0){
                        for(k=1; k<=28; k++){
                            printf("%d/%d/%d\n",k,j,i);
                            fprintf(input,"%d/%d/%d\n",k,j,i);
                        }
                    }
                }
                else{
                    for(k=1; k<=30; k++){
                            printf("%d/%d/%d\n",k,j,i);
                            fprintf(input,"%d/%d/%d\n",k,j,i);
                    }
                }
            day1=1;
            }
        }

        /*This statement has been written to ensure loops work until the end date entered by user*/
        /*To enter the last month that the user entered, not to the 12th*/
        else if(i == year2 && year1!=year2){

            for(j=1; j<month2; j++){
                if(j==1 || j==3 || j==5 || j==7 || j==8 || j==10 || j==12){
                    for(k=day1; k<=31; k++){
                        printf("%d/%d/%d\n",k,j,i);        /*prints on the screen*/
                        fprintf(input,"%d/%d/%d\n",k,j,i); /*prints on the file*/
                    }
                }
                else if(j==2){
                    if(if_year_is_leap(i)==1){
                        for(k=day1; k<=29; k++){
                            printf("%d/%d/%d\n",k,j,i);
                            fprintf(input,"%d/%d/%d\n",k,j,i);
                        }
                    }
                    else if(if_year_is_leap(i)==0){
                        for(k=day1; k<=28; k++){
                            printf("%d/%d/%d\n",k,j,i);
                            fprintf(input,"%d/%d/%d\n",k,j,i);
                        }
                    }
                }
                else{
                    for(k=day1; k<=30; k++){
                            printf("%d/%d/%d\n",k,j,i);
                            fprintf(input,"%d/%d/%d\n",k,j,i);
                    }
                }
            day1=1;
            }
            /*This statement checks if the month is end month,it prints until the end day*/
            if(j==month2){
                for(k=day1;k<=day2;k++){
                    printf("%d/%d/%d\n",k,j,i);
                    fprintf(input,"%d/%d/%d\n",k,j,i);
                }
            }
        }
        else if(year1 == year2 ){

            for(j=month1; j<month2; j++){
                if(j==1 || j==3 || j==5 || j==7 || j==8 || j==10 || j==12){
                    for(k=day1; k<=31; k++){
                        printf("%d/%d/%d\n",k,j,i);        /*prints on the screen*/
                        fprintf(input,"%d/%d/%d\n",k,j,i); /*prints on the file*/
                    }
                }
                else if(j==2){
                    if(if_year_is_leap(i)==1){
                        for(k=day1; k<=29; k++){
                            printf("%d/%d/%d\n",k,j,i);
                            fprintf(input,"%d/%d/%d\n",k,j,i);
                        }
                    }
                    else if(if_year_is_leap(i)==0){
                        for(k=day1; k<=28; k++){
                            printf("%d/%d/%d\n",k,j,i);
                            fprintf(input,"%d/%d/%d\n",k,j,i);
                        }
                    }
                }
                else{
                    for(k=day1; k<=30; k++){
                            printf("%d/%d/%d\n",k,j,i);
                            fprintf(input,"%d/%d/%d\n",k,j,i);
                    }
                }
            day1=1;
            }
            /*This statement checks if the month is end month,it prints until the end day*/
            if(j==month2){
                for(k=day1;k<=day2;k++){
                    printf("%d/%d/%d\n",k,j,i);
                    fprintf(input,"%d/%d/%d\n",k,j,i);
                }
            }
        }
    }

    fclose(input);
  
}/*end of the create date function.*/

/*Function read lines from input.txt file and converts 
 *any given date to its day,using some mathematical formulas.*/
int convert_date_to_day(int day,int month,int year){
    int i;
    FILE *output;
    if (output == NULL)
    {
        printf ("Error opening the file\n\n'");
        return -1;
    }
    output= fopen("new_date.txt","a");
    
    int date_key = day;                              /*the date code equals the day of the desired date.*/
    int year_key = year%100;                         /*year code is the last two digits of the year, so mod is taken to 100*/
    char month_name[20];                             /*this string is defined to hold month names, ex:to write april instead of 4. month*/
    int day_key;
    /*ıf statements to determine month_key and its name*/
    if(month==1){
        i=1;
        char month_name[]="January";
    }
    else if(month==2){
        i=4;
        char month_name[]="February";
    }
    else if(month==3){
        i=4;
        char month_name[]="March";
    }
    else if(month==4){
        i=7;
        char month_name[]="April";
    }
    else if(month==5){
        i=2;
        char month_name[]="May";
    }
    else if(month==6){
        i=5;
        char month_name[]="June";
    }
    else if(month==7){
        i=7;
        char month_name[]="July";
    }
    else if(month==8){
        i=3;
        char month_name[]="August";
    }
    else if(month==9){
        i=6;
        char month_name[]="September";
    }
    else if(month==10){
        i=1;
        char month_name[]="October";
    }
    else if(month==11){
        i=4;
        char month_name[]="November";
    }
    else if(month==12){
        i=6;
        char month_name[]="December";
   }
   /*The formula which converts the date to day*/
   /*This formula is taken from the link: 
    *http://www.webtekno.com/herhangi-bir-tarihin-hangi-gune-denk-geldigini-hesaplayabileceginiz-harika-yontem-h39742.html*/
    day_key = (date_key%7)+i+(year_key/7)+ ((year_key/4)%7) ;
    /*while(day_key > 14){
        day_key=day_key%7;
    }*/
    while(day_key > 7){
        day_key=day_key-7;
    }

    /*The day of the given date is determined by the value of the day_key variable.*/
    /*Switch case used to print day according to day_key value.*/
    switch(day_key){
        case(1):
            fprintf(output,"sunday,%s %d,%d\n",month_name,day,year);
            printf("sunday,%s %d,%d\n",month_name,day,year);
            break;
        case(2):
            fprintf(output,"monday,%s %d,%d\n",month_name,day,year);
            printf("monday,%s %d,%d\n",month_name,day,year);
            break;
        case(3):
            fprintf(output,"tuesday,%s %d,%d\n",month_name,day,year);
             printf("tuesday,%s %d,%d\n",month_name,day,year);
            break;
        case(4):
            fprintf(output,"wednesday,%s %d,%d\n",month_name,day,year);
            printf("wednesday,%s %d,%d\n",month_name,day,year);
            break;
        case(5):
            fprintf(output,"thursday,%s %d,%d\n",month_name,day,year);
            printf("thursday,%s %d,%d\n",month_name,day,year);
            break;
        case(6):
            fprintf(output,"friday,%s %d,%d\n",month_name,day,year);
            printf("friday,%s %d,%d\n",month_name,day,year);
            break;
        case(7):
            fprintf(output,"saturday,%s %d,%d\n",month_name,day,year);
            printf("saturday,%s %d,%d\n",month_name,day,year);
            break;
        default:
            break;

    }
    fclose(output);
    return day_key;
/*End of convert date to day function*/
}


