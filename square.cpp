#include<stdio.h>
#include<math.h>

/*
--Идеальное решение квадратного уравнения--
*/

const int TWO_SIMILAR = 11;
const int INFINITE = -1;
const int COMPLEX = 22;
const int ZERO = 0;
const int ONE = 1;
const int TWO = 2;
const int PATIENCE = 10;
const double EPS = 0.00001;

void basic(double b, double c, double x_1[], int *root_fl);
void advanced(double a, double b, double c, double x_1[], double x_2[], int *root_fl);
int solve(double a, double b, double c, double x_1[], double x_2[]);

void printer(int root_fl, double x_1[], double x_2[]);
int inputer(double *a, double *b, double *c);

void a_lot_of_equations();
void standard();

int main()
{
    int choose = 0, fl = 0;
    while (!fl)
    {
        printf("Choose what you want\n1) Standard input\n2) Random input\n");
        fl = scanf("%d", &choose);

        if (!fl)
        {
            printf("Wrong input, try again\n");
        }
    }

    switch (choose)
    {
        case 1:
            standard();
            break;
        case 2:
            a_lot_of_equations();
            break;
        default:
            printf("Unknown command\n");
            break;
    }
    return 0;
}

void standard()
{
    double a = 0, b = 0, c = 0;
    int next = inputer(&a, &b, &c);

    if (next)
    {
        double x_1[2] = {0, 0}, x_2[2] = {0, 0};
        int root_fl = solve(a, b, c, x_1, x_2);

        printer(root_fl, x_1, x_2);
    } else
    {
        printf("Try next time\n");
    }
}

void a_lot_of_equations()
{
    int equations = 0;
    printf("Input amount of random equations\n");
    scanf("%d", &equations);

    for (int i = 0; i < equations; ++i)
    {
        printf("\nHere is %d's equation\n", i+1);

        double a = (rand() % 20001 - 10000) / (100.0),
               b = (rand() % 20001 - 10000) / (100.0),
               c = (rand() % 20001 - 10000) / (100.0);
        printf("Your coefs: a = %.2lf, b = %.2lf, c = %.2lf\n", a, b, c);

        double x_1[2] = {0, 0}, x_2[2] = {0, 0};
        int root_fl = solve(a, b, c, x_1, x_2);

        printer(root_fl, x_1, x_2);
    }

}

int inputer(double *a, double *b, double *c)
{
    int counter = 0;
    bool fl = 0;

    while (counter < PATIENCE and !fl)
    {
        printf("Enter coef in square equation\n");

        if (scanf("%lf %lf %lf", a, b, c) < 3)
        {
            printf("Wrong input, try again \n");
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

void printer(int root_fl, double x_1[], double x_2[])
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
            printf("First root  %.2lf \nSecond root %.2lf\n", x_1[0], x_2[0]);
            break;
        case INFINITE:
            printf("Infinite amount of roots\n");
            break;
        case TWO_SIMILAR:
            printf("Two similar real roots\n");
            printf("%.2lf", x_1[0]);
            break;
        case COMPLEX:
            printf("First root  %.2lf + %.2lf i \nSecond root %.2lf - %.2lf i\n", x_1[0], abs(x_1[1]), x_2[0], abs(x_2[1]));
            break;
        default:
            printf("Unsupported case");
            break;
    }
}

void basic(double b, double c, double x_1[], int *root_fl)
{
    if (abs(b) < EPS)
    {
        if (abs(c) < EPS)
        {
            *root_fl = INFINITE;
        } else
        {
            *root_fl = ZERO;
        }
    } else
    {
        x_1[0] = (-c / b);

        *root_fl = ONE;
    }
}
void advanced(double a, double b, double c, double x_1[], double x_2[], int *root_fl)
{
    double D = b * b - 4 * a * c;
    double sqrtD = sqrt(abs(D));

    if (abs(D) < EPS)
    {
        x_1[0] = (-b) / (2 * a);
        x_2[0] = x_1[0];
        *root_fl = TWO_SIMILAR;
    } else if (D > 0)
    {
        x_1[0] = (-b + sqrtD) / (2 * a);
        x_2[0] = (-b - sqrtD) / (2 * a);
        *root_fl = TWO;
    } else
    {
        x_1[0] = (-b) / (2 * a);
        x_1[1] =  (sqrtD) / (2 * a);
        x_2[0] = (-b) / (2 * a);
        x_2[1] =  (sqrtD) / (2 * a);
        *root_fl = COMPLEX;
    }
}

int solve(double a, double b, double c, double x_1[], double x_2[])
{
    int root_fl = 0;

    if (abs(a) < EPS)
    {
        basic(b, c, x_1, &root_fl);
    } else
    {
        advanced(a, b, c, x_1, x_2, &root_fl);
    }

    return root_fl;
}
