#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define lp 1000

double c_od, c_do;

/*
double f1(double x)
{
    return 0.23*x*x*x+2*x-99;
}
double f2(double x)
{
    double y;
    y=sin(2*x)+cos(3*x)-1;
    return y;
}
*/
double f3_kamil(double x)
{
        return x * x + 3;
}
double f4_kamil(double x)
{
        return exp(1) * x + sin(2 * x);
}

double prostokaty(double (*f)(double))
{
        double step, i, sum = 0;
        step = (c_do - c_od) / lp;
        for (i = c_do; i > c_od; i -= step)
                sum += (*f)(i)*step;
        return sum;
}

double trapezy(double (*f)(double))
{
        return 1;
}

double mc(double (*f)(double))
{
        return 1;
}
