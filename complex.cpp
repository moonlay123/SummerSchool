#include <math.h>
#include "complex.h"

void complex_swap(complex *x_1, complex *x_2)
{
    double temp = x_1->real;
    x_1->real = x_2->real;
    x_2->real = temp;

    temp = x_1->imaginary;
    x_1->imaginary = x_2->imaginary;
    x_2->imaginary = temp;
}

void sort_complex(complex *x_1, complex *x_2)
{
    if (is_zero(x_1->real - x_2->real))
    {
        if (greater_zero(x_1->imaginary - x_2->imaginary))
        {
            complex_swap(x_1, x_2);
        } else
        {
            return;
        }
    } else if (greater_zero(x_1->real - x_2->real))
    {
        complex_swap(x_1, x_2);
    } else
    {
        return;
    }
}

double distance_between_complex(complex x_1, complex x_2)
{
    return sqrt((x_1.real - x_2.real) * (x_1.real - x_2.real) +
                (x_1.imaginary - x_2.imaginary) * (x_1.imaginary - x_2.imaginary));
}

bool complex_are_similar(complex x_1, complex x_2)
{
    if (is_zero(x_1.imaginary- x_2.imaginary))
    {
        return is_zero(x_1.real - x_2.real);
    } else
    {
        return is_zero(distance_between_complex(x_1, x_2));
    }
}

bool is_zero(double a)
{
    return abs(a) < EPS;
}
bool greater_zero(double a)
{
    return a > EPS;
}
