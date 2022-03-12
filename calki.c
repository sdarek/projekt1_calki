#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#define lp 1000
#define MAX(a,b) (a>b)?a:b

double c_od,c_do;

double f3(double x)
{
        return -1;      
}      
double f4(double x) 
{
        return 1;
}


double prostokaty(double( *f)(double))
{
       double krok, p, suma=0;
       krok=(c_do-c_od)/lp;
       for(p=c_od; p<c_do; p+=krok)
               suma+=(*f)(p)*krok;
       return suma;      
}

double trapezy(double (*f)(double))
{
        return 1;
}
       
double mc(double(*f)(double))
{
        srand(time(NULL));
        int dokladnosc = lp*100; //liczba losowanych punktow pomnozona przez 100
        int i;  //zmienna iteracyjna na potrzeby petli
        double suma_wartosci = 0;
        double a;
        for(i = 0; i < dokladnosc; i++)
        {
                a = c_od + (double)rand() / (double)(dokladnosc + 1) * (c_do - c_od);
                suma_wartosci += (*f)(a);
        }
        double pole = fabs(c_do - c_od) * suma_wartosci / dokladnosc;
        return pole;
}

