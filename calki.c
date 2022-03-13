#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define lp 10000

double c_od,c_do;

double f3_kuba(double x)
{
        return log(x*x + 2) - 3;   
}      
double f4_kuba(double x) 
{
        return exp(-sin(x))*cos(x);
}


double prostokaty(double(*f)(double))
{
       double krok, p, suma=0;
       krok=(c_do-c_od)/lp;
       for(p=c_od; p<c_do; p+=krok)
               suma+=(*f)(p)*krok;
       return suma;      
}

double trapezy(double (*f)(double))
{
        double krok, suma=0;
        krok=(c_do-c_od)/lp;
        double wart_lewo = 0.0,wart_prawo = 0.0;
        for(double i = c_od;i < c_do; i+= krok)
        {
                if(i == c_od) wart_lewo = (*f)(i);
                else wart_lewo = wart_prawo;
                wart_prawo = (*f)(i+krok);
                suma+=((wart_lewo + wart_prawo)*krok)/2;
        }
        return suma;
}
       
double mc(double(*f)(double))
{
        return 1;
}

