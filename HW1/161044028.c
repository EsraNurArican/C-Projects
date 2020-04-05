/*ESRA NUR ARICAN*/
/*161044028*/
/*CSE102 HOMEWORK #01 */

#include <stdio.h>
#include <math.h>
#define PI 3.14

/*Functions that will be used in the program*/
double circle_area(double radius);
double calc_hyponetenuse(int side1, int side2);
double calc_radius_of_smallest_circle(int side1,int side2);
double calc_radius_of_largest_circle(int side1,int side2);
double calc_area_of_smallest_circle(int side1,int side2);
double calc_area_of_largest_circle(int side1,int side2);
double calc_area_of_smallest_square(int side1,int side2);
double calc_area_of_largest_square(int side1,int side2);
double calc_area_of_square(int side);
void display_results(double largest_circle,double largest_square,double smallest_circle,double smallest_square);

/*In maın function the function display_results is called.*/
int main(){

    double largest_circle, largest_square,smallest_circle,smallest_square ;
    display_results(largest_circle, largest_square,smallest_circle,smallest_square);

}

/*This function calculates the area of a circle*/
double circle_area(double radius){
    double area;
    area = (PI)*(pow((radius),(2)));
    return area;
}

/*Calculates the hypotenuse of rectangle*/
double calc_hypotenuse(int side1, int side2){
    double hypotenuse;
    hypotenuse = sqrt (pow(side1,2) + pow(side2,2));
    return hypotenuse;
}

/*Calculates the radius of smallest circle that surrounds rectangle*/
double calc_radius_of_smallest_circle(int side1,int side2){
    double radius;
    radius = calc_hypotenuse(side1, side2) / 2.0 ;
    return radius;
    
}

/*Calculates the radius of largest circle inside the rectangle*/
double calc_radius_of_largest_circle(int side1,int side2){
    double radius;
    if(side1 > side2)
        radius = side2 / 2.0;
    else
        radius= side1 / 2.0;  
     
    return radius;          
}

/*Calculates the area of smallest circle that surrounds rectagle*/
double calc_area_of_smallest_circle(int side1, int side2){
    double radius, area;
    radius= calc_radius_of_smallest_circle(side1,side2); /*to determine the radius;
                      the function"calc_radius_of_smallest_circle" has to be used*/
    area= circle_area(radius);/*the function " circle_area" has to be used to calculate the area*/
    
    printf("The area of the smallest circle that surrounds the rectangle is:%.2f\n",area);
    return area; 
}

/*Calculates the area of largest circle that fits inside ractangle*/
double calc_area_of_largest_circle(int side1,int side2){
    double radius,area;
    radius = calc_radius_of_largest_circle(side1,side2);
    area = circle_area(radius);
    
    printf("The area of the largest circle that fits inside the rectangle is:%.2f\n",area);
    return area;
}

/*Calculates the area of a square*/
double calc_area_of_square(int side){
    double area;
    area = pow(side,2);/*To take square of one side,pow function called from math library.*/
    return area;
}

/*Calculates the area of smallest square that surrounds rectangle*/    
double calc_area_of_smallest_square(int side1,int side2){
    double area;
    if(side1 >= side2)
        area = calc_area_of_square(side1);
        
    else
        area = calc_area_of_square(side2);  
    
    printf("The area of the smallest square that surrounsd the rectangle is:%.2f\n",area);         
    return area;    
}    

/*Calculates the area of largest square that fits inside rectangle*/    
double calc_area_of_largest_square(int side1, int side2){
    double area;
    if (side1 <= side2)
        area = calc_area_of_square(side1);
    else 
        area = calc_area_of_square(side2);
    
    printf("The area of the largest square that fits inside the rectangle is:%2f\n",area);        
    return area;     
}    

/*This function takes the variables from the user,
  calls other functions and displays the results*/
void display_results(double largest_circle,double largest_square,double smallest_circle,double smallest_square){
    int side1,side2;
    
    /*This part takes side1 and side2 from the user*/
    printf("please enter the side1 of rectangle:\n");
    scanf("%d",&side1);
    printf("please enter the side2 of rectangle:\n");
    scanf("%d",&side2);
    
   
    smallest_circle = calc_area_of_smallest_circle(side1,side2);
    largest_circle = calc_area_of_largest_circle(side1,side2);
    smallest_square = calc_area_of_smallest_square(side1,side2);
    largest_square = calc_area_of_largest_square(side1,side2);
    
}
