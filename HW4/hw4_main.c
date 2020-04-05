/*
** main.c:
**
** The test program for the homework.
**
** Author: Yakup Genc. (c) 2018
**
** Revision: 2018.03.27.08.14
** 
*/


#include <stdio.h>


#include "hw4_lib.h"
#include "hw4_io.h"



/*
** Testing derivative calculations..
**
*/
double f(double x) { return x*x; }
double d1(double x) { return 2.0*x; }
double d2(double x) { return 2.0; }

void test_compare_derivatives() {
	double e1, e2;
	int res = compare_derivatives(f, d1, d2, 1.0, 0.0001, &e1, &e2);
	printf("%f %f\n",e1,e2);
}

/*Testing polynomial3*/
/*Calls the read_polynomial3 function,takes values from user as coefficient of 3-degree polynomial
  Calls the write_polynomial3 function and prints on screen 3-degree polynomial equation as an output */

void test_polynomial3 () {
    double a0,a1,a2,a3;
    read_polynomial3(&a0,&a1,&a2,&a3);
    write_polynomial3(a0,a1,a2,a3);
    
}

/*Testing read polynomial4*/
/*Calls the read_polynomial4 function,takes values from user as coefficient of 4-degree polynomial
  Calls the write_polynomial4 function and prints on screen 4-degree polynomial equation as an output */

void test_polynomial4 () {
    double a0,a1,a2,a3,a4;
    read_polynomial4(&a0,&a1,&a2,&a3,&a4);
    write_polynomial4(a0,a1,a2,a3,a4);
}

/*Testing integral function*/

void test_integral () {
    
    /*calls the integral function with patameters*/
	integral(f,  2,  5,  0.001);
    
}

/*Testing double integral function*/


void test_double_integral () {

    /*Definig the double f function with parameters x and y */
    double f2(double x,double y) { return x*x + y*y; }
    
    /*Calling double integral function with parameters*/
    integral2(f2,0,1,0,1,0.001);
   
}

/*Testing derrivatives funcion*/

void test_derivatives () {

    double d1,d2;
    derivatives(f, 2.0, 0.001,  &d1, &d2);
    printf("***First derivative:%f***\n***Second derivative:%f***\n",d1,d2);
}



/*
** main function for testing the functions...
**
*/
int main(void) {
	
	
	test_integral();
	test_double_integral();
	test_derivatives();
    test_compare_derivatives();
    test_polynomial3();
	test_polynomial4();
	
	return (0);
} /* end main */



