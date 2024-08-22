#include <stdio.h>
#include <assert.h>
#include <math.h>
#include "complex.h"
#include "square.h"


double calculate_Discriminant(coefficients coefs)
{
    return coefs.b * coefs.b - 4 * coefs.a * coefs.c;
}

void clean_char_buffer()
{
    while(getchar() != '\n')
        continue;
}

double double_rand()
{
    return (rand() % 20001 - 10000) / (100.0);
}

void standard()
{
    coefficients coefs = {0, 0, 0};
    int next = square_equation_input(&coefs);

    if (next == SUCCESS)
    {
        complex x_1 = {0, 0}, x_2 = {0, 0};
        int root_fl = solve(coefs, &x_1, &x_2);

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

        coefficients coefs = {double_rand(), double_rand(), double_rand()};
        printf("Your coefs: a = %.2lf, b = %.2lf, c = %.2lf\n", coefs.a, coefs.b, coefs.c);

        complex x_1 = {0, 0}, x_2 = {0, 0};
        int root_fl = solve(coefs, &x_1, &x_2);

        square_equation_printer(root_fl, x_1, x_2);
    }

}

int square_equation_input(coefficients *coefs)
{
    int counter = 0;
    bool fl = 0;
    while (!fl)
    {
        printf("Enter coef in square equation\n");

        if (scanf("%lf %lf %lf", &coefs->a, &coefs->b, &coefs->c) < 3)
        {
            printf("Wrong input, try again \n");
            clean_char_buffer();
            ++counter;
        } else
        {
            fl = 1;
        }
    }

    return SUCCESS;
}

void square_equation_printer(int root_fl, complex x_1, complex x_2)
{
    switch (root_fl)
    {
        case ZERO:
            printf("No roots\n");
            break;
        case ONE:
            printf("Only one real root\n");
            printf("%.2lf", x_1.real);
            break;
        case TWO:
            printf("Two unique real roots\n");
            printf("First root  %.2lf\nSecond root %.2lf\n", x_1.real, x_2.real);
            break;
        case INFINITES:
            printf("Infinite amount of roots\n");
            break;
        case TWO_SIMILAR:
            printf("Two similar real roots\n");
            printf("Similar roots %.2lf and %.2lf", x_1.real, x_2.real);
            break;
        case COMPLEX:
            printf("Two complex roots\n");
            printf("First root  %.2lf + %.2lf i\nSecond root %.2lf - %.2lf i\n",
                    x_1.real, abs(x_1.imaginary), x_2.real, abs(x_2.imaginary));
            break;
        default:
            printf("Unsupported case");
            break;
    }
}

roots_type linear_case(coefficients coefs, complex *x)
{
    if (is_zero(coefs.b))
    {
        if (is_zero(coefs.c))
        {
            return INFINITES;
        } else
        {
            return ZERO;
        }
    } else
    {
        x->real = (-coefs.c / coefs.b);

        return ONE;
    }
}
roots_type square_case(coefficients coefs, complex *x_1, complex *x_2)
{
    double D = calculate_Discriminant(coefs);
    double sqrtD = sqrt(abs(D));

    if (is_zero(D))
    {
        x_1->real = (-coefs.b) / (2 * coefs.a);
        x_2->real = x_1->real;
        return TWO_SIMILAR;
    } else if (greater_zero(D))
    {
        x_1->real = (-coefs.b + sqrtD) / (2 * coefs.a);
        x_2->real = (-coefs.b - sqrtD) / (2 * coefs.a);
        return TWO;
    } else
    {
        x_1->real = (-coefs.b) / (2 * coefs.a);
        x_1->imaginary = (sqrtD) / (2 * coefs.a);
        x_2->real = x_1->real;
        x_2->imaginary = -x_1->imaginary;
        return COMPLEX;
    }
}

roots_type solve(coefficients coefs, complex *x_1, complex *x_2)
{
    assert(isfinite(coefs.a));
    assert(isfinite(coefs.b));
    assert(isfinite(coefs.c));

    assert(x_1 != NULL);
    assert(x_2 != NULL);
    assert(x_1 != x_2);

    roots_type root_fl = NON_ROOT_TYPE;

    if (is_zero(coefs.a))
    {
        root_fl = linear_case(coefs, x_1);
    } else
    {
        root_fl = square_case(coefs, x_1, x_2);
    }

    return root_fl;
}
