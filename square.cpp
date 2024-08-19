#include<stdio.h>
#include<math.h>

/*
--Идеальное решение квадратного уравнения--
*/

const double EPS = 0.00001;

int solve(double a, double b, double c, double x_1[], double x_2[]);
void printer(int root_fl, double x_1[], double x_2[]);
int inputer(double *a, double *b, double *c);

int main()
{
    double a=0,b=0,c=0;

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

    return 0;
}

int inputer(double *a, double *b, double *c)
{
    int timer = 0, correct = -1;

    while (timer < 10 and correct != 3)
    {
        printf("Enter coef in square equation\n");

        correct = scanf("%lf %lf %lf", a, b, c);

        if (correct < 3)
        {
            printf("Wrong input, try again \n");
            ++timer;
        }
    }

    if (timer == 10)
    {
        return 0;
    }

    return 1;
}

void printer(int root_fl, double x_1[], double x_2[])
{
    switch (root_fl)
    {
        case -1:
            printf("Infinite amount of roots\n");
            break;
        case 0:
            printf("No roots\n");
            break;
        case 1:
            printf("Only one real root\n");
            printf("%.2lf", x_1[0]);
            break;
        case 2:
            printf("Two similar real roots\n");
            printf("%.2lf", x_1[0]);
            break;
        case 3:
            printf("Two unique real roots\n");
            printf("First root  %.2lf \nSecond root %.2lf\n", x_1[0], x_2[0]);
            break;
        case 4:
            printf("First root  %.2lf + %.2lf i \nSecond root %.2lf - %.2lf i\n", x_1[0], x_1[1], x_2[0], x_2[1]);
            break;
        default:
            printf("Unsupported case");
            break;
    }
}

int solve(double a, double b, double c, double x_1[], double x_2[])
{
    int root_fl = 0;

    double D = b * b - 4 * a * c;
    double sqrtD = sqrt(abs(D));

    if (abs(a) < EPS)
    {
        if (abs(b) < EPS)
        {
            if (abs(c) < EPS)
            {
                root_fl = -1;
            } else
            {
                root_fl = 0;
            }
        } else
        {
            x_1[0] = (-c / b);

            root_fl = 1;
        }
    } else
    {
        if (abs(D) < EPS)
        {
            x_1[0] = (-b) / (2 * a);
            x_2[0] = (-b) / (2 * a);

            root_fl = 2;
        } else if (D > 0)
        {
            x_1[0] = (-b + sqrtD) / (2 * a);
            x_2[0] = (-b - sqrtD) / (2 * a);

            root_fl = 3;
        } else
        {
            x_1[0] = (-b) / (2 * a);
            x_1[1] =  (sqrtD) / (2 * a);

            x_2[0] = (-b) / (2 * a);
            x_2[1] =  (sqrtD) / (2 * a);

            root_fl = 4;
        }
    }

    return root_fl;
}
