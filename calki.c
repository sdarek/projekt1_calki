#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#define lp 1000
#define MAX(a,b) (a>b)?a:b

double c_od,c_do;

double f3_darek(double x)
{
    return (x*x*x-x*x-2*x+15);
}
double f4_darek(double x) {

    return (2*sin(x) - cos(x)*x + 10);
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
        int dokladnosc = lp * 1000;
        double x_przedzial = fabs(c_do - c_od); //dlugosc przedzialu calkowania
        double krok = x_przedzial / dokladnosc;
        double y_min = 0, y_max = 0;
        double calka;   //wartosc koncowa obliczonego pola podcalkowego
        double count = 0;   //licznik punktow pod wykresem (+) i nad (-)
        double pom;
        double x;       //wylosowane x
        double y;       //wylosowane y
        double i;       //zmienna na potrzeby petli
        
//szukanie wartosci najwiekszej i najmniejszej funkcji w danym przedziale calkowania
        for(i = c_od; i < c_do; i += krok)
        {
                pom = (*f)(i);

                if(pom > y_max) y_max = pom;
                else if(pom < y_min) y_min = pom;
        }
        if(y_max > 0 && y_min > 0) y_min = 0;
        if(y_max < 0 && y_min < 0) y_max = 0;

        double y_przedzial = fabs(y_max - y_min);
        double P = x_przedzial * y_przedzial;   //pole prostokata

        for(i = 0; i < dokladnosc; i++)
        {
                x = ((double)rand() / RAND_MAX * x_przedzial) + c_od;
                y = ((double)rand() / RAND_MAX * y_przedzial) + y_min;

                pom = (*f)(x);

                if(pom > 0 && pom >= y) count++; 
                else if(pom < 0 && pom <= y) count--;
        }

        calka = (P * count) / dokladnosc;
        return calka;
}

