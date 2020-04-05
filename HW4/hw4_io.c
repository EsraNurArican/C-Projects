/*
** hw4_io.c:
**
** The source file implementing input and output functions.
**
** Author: Yakup Genc. (c) 2018
**
** Revision: 2018.03.27.08.19
** 
*/


#include "hw4_io.h"
#include <stdio.h>

    /*Function that reads coefficients of a degree-3 polynomial */
    int read_polynomial3(double *a0,double *a1,double *a2,double *a3){
        printf("Please enter coefficients of a degree-3 polynomial ->>\n");
        scanf("%lf %lf %lf %lf",&*a0,&*a1,&*a2,&*a3);
        
        return 0;
    }
    
     /*Function that reads coefficients of a degree-4 polynomial */
    int read_polynomial4(double *a0,double *a1,double *a2,double *a3,double *a4){
        printf("Please enter coefficients of a degree-4 polynomial ->>\n");
        scanf("%lf %lf %lf %lf %lf",&*a0,&*a1,&*a2,&*a3,&*a4);
        return 0;
    }
    
    /*Function that writes the equation of polynomial of degree-3*/
    /*Writing should be with the format "a3x^3 +a2x^2 +a1x +a0"
     *(User entered coefficients from a0 to a3)
     */
    void write_polynomial3(double a0, double a1, double a2, double a3){
        double array[4]={a3,a2,a1,a0};/*Scanning is from a0 to a3 but writing will be from a3 to a0 thats way i put them in array reversed */
        int i;
        for(i=0; i<2; i++){
        
            /*If coefficient is 1,only x^n should be written(not 1x^n)*/ 
            if(array[i]==1)
                printf("+x^%d ",3-i);
            if(array[i]==-1)
                printf("-x^%d ",3-i);
            /*If number is negative,no sign should written*/
            if(array[i]<0 && array[i]!=-1)
                printf("%.2fx^%d ",array[i],3-i);
            /*If the number is pozitive,+ sign should written*/
            if(array[i]>0 && array[i]!=1)
                printf("+%.2fx^%d ",array[i],3-i);
            
        }
        
        /*If statements for writing x instead of x^1*/
        if(array[2]>0 && array[2]!=1)
            printf("+%.2fx ",array[2]);
            
        if(array[2]<0 && array[2]!=-1)
            printf("%.2fx ",array[2]);
            
        if(array[2]==1)
            printf("+x ");
            
        if(array[2]==-1)
            printf("-x ");
        /*If statements for writin the term a0(without x,because constant term.)*/   
        if(array[3]>0)
            printf("+%.2f ",array[3]);
            
        if(array[3]<0)
            printf("%.2f ",array[3]);
            
        printf("\n");
        
    }
    
    /*Function that writes the equation of polynomial of degree-4*/
    /*Writing should be with the format "a4x^4 +a3x^3 +a2x^2 +a1x +a0"
     *(User entered coefficients from a0 to a4)
     */
    void write_polynomial4(double a0, double a1, double a2, double a3,double a4){
        double array[5]={a4,a3,a2,a1,a0};
        int i;
        for(i=0; i<3; i++){
            /*If number is negative,no sign should written*/
            if(array[i]<0 && array[i]!=-1)
                printf("%.2fx^%d ",array[i],4-i);
            /*If the number is pozitive,+ sign should written*/    
            if(array[i]>0 && array[i]!=1)
                printf("+%.2fx^%d ",array[i],4-i);
            /*If coefficient is 1,only x^n should be written(not 1x^n)*/    
            if(array[i]==1)
                printf("+x^%d ",4-i);
            if(array[i]==-1)
                printf("-x^%d ",4-i);
        }
        
        /*If statements for writing x instead of x^1*/
        if(array[3]>0 && array[3]!=1)
            printf("+%.2fx ",array[3]);
            
        if(array[3]<0 && array[3]!=-1)
            printf("%.2fx ",array[3]);
            
        if(array[3]==1)
            printf("+x ");
            
        if(array[3]==-1)
            printf("-x ");
        /*If statements for writin the term a0(without x,because constant term.)*/    
        if(array[4]>0)
            printf("+%.2f ",array[4]);
            
        if(array[4]<0)
            printf("%.2f ",array[4]);
            
        printf("\n");
        
    }
    
