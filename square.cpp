#include<stdio.h>
#include<math.h>
#include<assert.h>

/*
--Идеальное решение квадратного уравнения--
*/

typedef enum {TWO_SIMILAR, INFINITE, COMPLEX, ZERO, ONE, TWO, NOPE} roots ;
typedef enum {Many_equations = 2, Standard = 1, Nope = 0} choose_type;

const int  PATIENCE = 10;
const double EPS = 0.000001;

void pass_string();

bool is_zero(double a);
bool greater_zero(double a);
double double_rand();

roots linear_case(double b, double c, double x_1[]);
roots square_case(double a, double b, double c, double x_1[], double x_2[]);
roots solve(double a, double b, double c, double x_1[], double x_2[]);

void square_equation_printer(int root_fl, double x_1[], double x_2[]);
int square_equation_input(double *a, double *b, double *c);

choose_type choose_variant();
void many_equations();
void standard();

int main()
{
    choose_type chosen = choose_variant();

    switch (chosen)
    {
        case Standard:
            standard();
            break;
        case Many_equations:
            many_equations();
            break;
        default:
            printf("Unknown command\n");
            break;
    }
    return 0;
}

void pass_string()
{
    while(getchar()!='\n')
        continue;
}

choose_type choose_variant()
{
    choose_type choose = Nope;
    int fl = 0;
    while (choose != 1 and choose != 2 and !fl)
    {
        printf("Choose what you want\n1) Standard input\n2) Random input\n");
        fl = scanf("%d", &choose);

        if (choose != 1 and choose != 2 and !fl)
        {
            printf("Wrong input, try again\n");
            pass_string();
        }
    }

    return choose;
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

    if (next)
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
    while (counter < PATIENCE and !fl)
    {
        printf("Enter coef in square equation\n");

        if (scanf("%lf %lf %lf", a, b, c) < 3)
        {
            printf("Wrong input, try again \n");
            pass_string();
            ++counter;
        } else
        {
            fl = 1;
        }
    }

    if (counter == PATIENCE)
    {
        return 0;
    }

    return 1;
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

roots linear_case(double b, double c, double x_1[])
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
        x_1[0] = (-c / b);

        return ONE;
    }
}
roots square_case(double a, double b, double c, double x_1[], double x_2[])
{
    double D = b * b - 4 * a * c;
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
        x_1[1] =  (sqrtD) / (2 * a);
        x_2[0] = x_1[0];
        x_2[1] =  -x_1[1];
        return COMPLEX;
    }
}

roots solve(double a, double b, double c, double x_1[], double x_2[])
{

    assert(isfinite(a));
    assert(isfinite(b));
    assert(isfinite(c));

    assert(x_1 != NULL);
    assert(x_2 != NULL);
    assert(x_1 != x_2);

    roots root_fl = NOPE;

    if (is_zero(a))
    {
        root_fl = linear_case(b, c, x_1);
    } else
    {
        root_fl = square_case(a, b, c, x_1, x_2);
    }

    return root_fl;
}
