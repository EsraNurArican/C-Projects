/*
** hw4_lib.c:
**
** The source file implementing library functions.
**
** Author: Yakup Genc. (c) 2018
**
** Revision: 2018.03.27.08.19
** 
*/

#include "hw4_lib.h"
#include <stdio.h>

double integral(double f(double x), double xs, double xe, double delta);

double integral2(double f(double x, double y), double xs, double xe, double ys, double ye, double delta);

int derivatives(double f(double a), double x, double eps, double * d1, double * d2);

int compare_derivatives(double f(double a), double d1(double b), double d2(double b), double x, double eps, double * e1, double *e2);

int find_roots(double f(double x), double * x1, double * x2, double * x3, double * x4);


/*Function that calculates the integral the function that given as parameter.
 *Function uses riemann sum to calculate the integral.
 *Given range is defined as xs and xe
 */
double integral(double f(double x), double xs, double xe, double delta){
   
    double integral,n,sum=0.0;
    int i;
    
    /*n is the upper limit for addition.Founded by using xs,xe and delta inputs. */
    n= (xe-xs)/delta;
    
    /*Loop for adding values from 1 to upper limit.*/
    for(i=1; i<=n; i++){
        sum= sum + (delta*f(xs + (i*(xe-xs)/n)));
    }
    
    /*According to riemann sum formula;our integral value is equal to summary.*/
    integral=sum;
    printf("***Integral1 is: %f***\n",integral);
    
    return integral;    
}

/*Function that calculates double integral of a two input function 
 *within the given range [xs,xe] and [ys,ye].
 *Function uses the same idea as the previous funcion integral;difference is ye and ys
 *This function makes two addition according to x and y limits.For these additions i used nested loops.
 */
double integral2(double f(double x, double y), double xs, double xe, double ys, double ye, double delta){

    double integral,nx,ny;
    double sum=0.0;
    int i,j;
    
    nx= (xe-xs) / delta;
    ny= (ye-ys) / delta;
    for(i=1; i<= nx; i++){
        for(j=1; j<=ny; j++ ){
            sum = sum +f(xs + (i*(xe-xs)/nx), ys + (j*(ye-ys)/ny))*delta*delta;
        }
        
    }
    integral=sum;
    printf("***Double integral is: %f***\n",integral);
    
    return integral;

}


int derivatives(double f(double a), double x, double eps, double * d1, double * d2){
    /*The function will return -1 if there is division by 0*/
    if (eps==0){
        return -1;
    }
    
    /*"*d1" is first derivative and calculated by the formula given as below.
     *"*d2" is the second derivative and calculated by the formula given as below.
     */
    else{
    *d1= (f(x + eps) - f(x - eps)) / (2*eps);
    *d2= (f(x + eps) -2*f(x) + f(x - eps)) / (eps*eps);
    }
    
    /*The function will return 1 if there is no problem*/
    return 1;
}

/*Tests the error in numeric calculation of derivatives vs. actual derivatives given by functions d1 and d2.
  *It returns the absolute difference between the calculated derivatives and analytically provided ones in arguments e1
  *and e2.*/
int compare_derivatives(double f(double a), double d1(double b), double d2(double b), double x, double eps, double * e1, double *e2){
    double derrivative1, derrivative2;
    /*Calling the derivative function to find calculated derivatives*/
    derivatives(f,x,eps,&derrivative1,&derrivative2);
    *e1 = d1(x) - derrivative1;
    *e2 = d2(x) - derrivative2;
    printf("***Absolute difference for first derrivative:%f***\n",*e1);
    printf("***Absolute difference for second derrivative:%f***\n",*e2);
    return 0;
}

