#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#define lp 10000
#define MAX(a,b) (a>b)?a:b

double c_od, c_do;

double f3_kamil(double x)
{
        return x * x + 3;
}
double f4_kamil(double x)
{
        return exp(1) * x + sin(2 * x);
}
double f3_kuba(double x)
{
        return log(x*x + 2) - 3;   
}      
double f4_kuba(double x) 
{
        return exp(-sin(x))*cos(x);
}
double f3_darek(double x)
{
    return (x*x*x-x*x-2*x+15);
}
double f4_darek(double x) 
{
    return (2*sin(x) - cos(x)*x + 10);
}

double prostokaty(double(*f)(double))
{
        double step, i, sum = 0;
        step = (c_do - c_od) / lp;
        for (i = c_do; i > c_od; i -= step)
                sum += (*f)(i)*step;
        return sum;
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

double mc(double (*f)(double))
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
