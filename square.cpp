#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "square.h"

void complex_swap(double *x_1, double *x_2)
{
    double temp = x_1[0];
    x_1[0] = x_2[0];
    x_2[0] = temp;

    temp = x_1[1];
    x_1[1] = x_2[1];
    x_2[1] = temp;
}

void sort_complex(double *x_1, double *x_2)
{
    if (is_zero(x_1[0] - x_2[0]))
    {
        if (greater_zero(x_1[1] - x_2[1]))
        {
            complex_swap(x_1, x_2);
        } else
        {
            return;
        }
    } else if (greater_zero(x_1[0] - x_2[0]))
    {
        complex_swap(x_1, x_2);
    } else
    {
        return;
    }
}

double calculate_D(double a, double b, double c)
{
    return b * b - 4 * a * c;
}

double distance_between_complex(double *x_1, double *x_2)
{
    return sqrt((x_1[0] - x_2[0]) * (x_1[0] - x_2[0]) + (x_1[1] - x_2[1]) * (x_1[1] - x_2[1]));
}

bool complex_are_similar(double *x_1, double *x_2)
{
    if (is_zero(x_1[1] - x_2[1]))
    {
        return is_zero(x_1[0] - x_2[0]);
    } else
    {
        return is_zero(distance_between_complex(x_1, x_2));
    }
}

void clean_char_buffer()
{
    while(getchar() != '\n')
        continue;
}


bool is_zero(double a)
{
    return abs(a) < EPS;
}
bool greater_zero(double a)
{
    return a > EPS;
}
double double_rand()
{
    return (rand() % 20001 - 10000) / (100.0);
}

void standard()
{
    double a = 0, b = 0, c = 0;
    int next = square_equation_input(&a, &b, &c);

    if (next == SUCCESS)
    {
        double x_1[2] = {0, 0}, x_2[2] = {0, 0};
        int root_fl = solve(a, b, c, x_1, x_2);

        square_equation_printer(root_fl, x_1, x_2);
    } else
    {
        printf("Try next time\n");
    }
}

void many_equations()
{
    int equations = 0;
    printf("Input amount of random equations\n");
    scanf("%d", &equations);

    for (int i = 0; i < equations; ++i)
    {
        printf("\nHere is %d equation\n", i+1);

        double a = double_rand(),
               b = double_rand(),
               c = double_rand();
        printf("Your coefs: a = %.2lf, b = %.2lf, c = %.2lf\n", a, b, c);

        double x_1[2] = {0, 0}, x_2[2] = {0, 0};
        int root_fl = solve(a, b, c, x_1, x_2);

        square_equation_printer(root_fl, x_1, x_2);
    }

}

int square_equation_input(double *a, double *b, double *c)
{
    int counter = 0;
    bool fl = 0;
    while (counter < NUMBER_OF_TRIES and !fl)
    {
        printf("Enter coef in square equation\n");

        if (scanf("%lf %lf %lf", a, b, c) < 3)
        {
            printf("Wrong input, try again \n");
            clean_char_buffer();
            ++counter;
        } else
        {
            fl = 1;
        }
    }

    if (counter == NUMBER_OF_TRIES)
    {
        return FAILURE;
    }

    return SUCCESS;
}

void square_equation_printer(int root_fl, double x_1[], double x_2[])
{
    switch (root_fl)
    {
        case ZERO:
            printf("No roots\n");
            break;
        case ONE:
            printf("Only one real root\n");
            printf("%.2lf", x_1[0]);
            break;
        case TWO:
            printf("Two unique real roots\n");
            printf("First root  %.2lf\nSecond root %.2lf\n", x_1[0], x_2[0]);
            break;
        case INFINITE:
            printf("Infinite amount of roots\n");
            break;
        case TWO_SIMILAR:
            printf("Two similar real roots\n");
            printf("Similar roots %.2lf and %.2lf", x_1[0], x_2[0]);
            break;
        case COMPLEX:
            printf("Two complex roots\n");
            printf("First root  %.2lf + %.2lf i\nSecond root %.2lf - %.2lf i\n",
                    x_1[0], abs(x_1[1]), x_2[0], abs(x_2[1]));
            break;
        default:
            printf("Unsupported case");
            break;
    }
}

roots_type linear_case(double b, double c, double x[])
{
    if (is_zero(b))
    {
        if (is_zero(c))
        {
            return INFINITE;
        } else
        {
            return ZERO;
        }
    } else
    {
        x[0] = (-c / b);

        return ONE;
    }
}
roots_type square_case(double a, double b, double c, double x_1[], double x_2[])
{
    double D = calculate_D(a, b, c);
    double sqrtD = sqrt(abs(D));

    if (is_zero(D))
    {
        x_1[0] = (-b) / (2 * a);
        x_2[0] = x_1[0];
        return TWO_SIMILAR;
    } else if (greater_zero(D))
    {
        x_1[0] = (-b + sqrtD) / (2 * a);
        x_2[0] = (-b - sqrtD) / (2 * a);
        return TWO;
    } else
    {
        x_1[0] = (-b) / (2 * a);
        x_1[1] = (sqrtD) / (2 * a);
        x_2[0] = x_1[0];
        x_2[1] = -x_1[1];
        return COMPLEX;
    }
}

roots_type solve(double a, double b, double c, double x_1[], double x_2[])
{
    assert(isfinite(a));
    assert(isfinite(b));
    assert(isfinite(c));

    assert(x_1 != NULL);
    assert(x_2 != NULL);
    assert(x_1 != x_2);

    roots_type root_fl = NON_ROOT_TYPE;

    if (is_zero(a))
    {
        root_fl = linear_case(b, c, x_1);
    } else
    {
        root_fl = square_case(a, b, c, x_1, x_2);
    }

    return root_fl;
}
