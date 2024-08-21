#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "unit_tests.h"


void expected_values_creator(double x_1_real, double x_1_complex, double x_2_real, double x_2_complex, double *x_1, double *x_2)
{
    x_1[0] = x_1_real, x_1[1] = x_1_complex;
    x_2[0] = x_2_real, x_2[1] = x_2_complex;
}

int unit_test(int number_of_test, double a, double b, double c,
              double *expected_x_1, double *expected_x_2, roots_type expected_root_type)
{
    double received_x_1[2] = {0, 0}, received_x_2[2] = {0, 0};
    roots_type received_root_type = solve(a, b, c, received_x_1, received_x_2);

    sort_complex(expected_x_1, expected_x_2);
    sort_complex(received_x_1, received_x_2);

    if (check_test_correctness(expected_x_1, received_x_1,
                               expected_x_2, received_x_2,
                               expected_root_type, received_root_type) == FAILURE)
    {
        print_results(number_of_test, a, b, c,
                                expected_x_1, received_x_1,
                                expected_x_2, received_x_2,
                                expected_root_type, received_root_type);

        return FAILURE;
    }

    return SUCCESS;
}

int full_test(int number_of_test, double a, double b, double c, double x_1_real, double x_1_complex, double x_2_real, double x_2_complex,
              double *expected_x_1, double *expected_x_2, roots_type expected_root_type)
{
    expected_values_creator(x_1_real, x_1_complex, x_2_real, x_2_complex, expected_x_1, expected_x_2);
    return unit_test(number_of_test, a, b, c, expected_x_1, expected_x_2, expected_root_type);
}

bool check_test_correctness(double *expected_x_1, double *received_x_1,
                            double *expected_x_2, double *received_x_2,
                            roots_type expected_root_type, roots_type received_root_type)
{
    if (expected_root_type == received_root_type)
    {
        if (complex_are_similar(expected_x_1, received_x_1) and complex_are_similar(expected_x_2, received_x_2))
        {
            return SUCCESS;
        }
        else
        {
            return FAILURE;
        }
    } else
    {
        return FAILURE;
    }
}

void print_results(int number_of_test, double a, double b, double c,
                             double *expected_x_1, double *received_x_1,
                             double *expected_x_2, double *received_x_2,
                             roots_type expected_root_type, roots_type received_root_type)
{
    printf("\nTest %d with coefs a = %lf, b = %lf, c = %lf\n"
           "Expected values: root_type = %d, x_1 = %lf + %lf i, x_2 = %lf + %lf i\n"
           "Received values: root_type = %d, x_1 = %lf + %lf i, x_2 = %lf + %lf i\n\n",
            number_of_test, a, b, c,
            expected_root_type, expected_x_1[0], expected_x_1[1], expected_x_2[0], expected_x_2[1],
            received_root_type, received_x_1[0], received_x_1[1], received_x_2[0], received_x_2[1]);
}

int run_all_tests()
{
    int fl = 0;

    double excepted_x_1[2] = {0, 0}, excepted_x_2[2] = {0, 0};

    fl = !(full_test(1, 1, 2, 1, -1, 0, -1, 0, excepted_x_1, excepted_x_2, TWO_SIMILAR) == SUCCESS);

    fl = !(full_test(2, 1, 2, 3, -2.0/2, -sqrt(8.0)/2, -2.0/2, sqrt(8.0)/2,
                    excepted_x_1, excepted_x_2, COMPLEX) == SUCCESS);

    fl = !(full_test(3, 5, -4, -1, 1, 0, -1.0/5, 0,
                    excepted_x_1, excepted_x_2, TWO) == SUCCESS);

    fl = !(full_test(4, 0.5, -2, 1.5, 1, 0, 3, 0,
                    excepted_x_1, excepted_x_2, TWO) == SUCCESS);

    fl = !(full_test(4, 0.5, -2, 1.5, 1, 0, 3, 0,
                    excepted_x_1, excepted_x_2, TWO) == SUCCESS);

    fl = !(full_test(5, 0, 0, 0, 0, 0, 0, 0,
                    excepted_x_1, excepted_x_2, INFINITE) == SUCCESS);

    fl = !(full_test(6, 0.000000000000000001, 0, 1.15125161717, 0, 0, 0, 0,
                     excepted_x_1, excepted_x_2, ZERO) == SUCCESS);

    fl = !(full_test(7, 0, 2, 1, 0, 0, -1/2.0, 0,
                    excepted_x_1, excepted_x_2, ONE) == SUCCESS);

    fl = !(full_test(8, 1.3, 7.1, -17.157, 1.8139852069763645, 0, -7.275523668514825, 0,
                    excepted_x_1, excepted_x_2, TWO) == SUCCESS);

    fl = !(full_test(9, 1, 0, 0, 0, 0, 0, 0,
                    excepted_x_1, excepted_x_2, TWO_SIMILAR) == SUCCESS);

    fl = !(full_test(10, 1.00000000000000000001, 0, 0.99999999999999999999999999999, 0, 1, 0, -1,
                    excepted_x_1, excepted_x_2, COMPLEX) == SUCCESS);

    fl = !(full_test(11, 1, 1650.73138, -28606.9796525, 17.151616, 0, -1667.8883, 0,
                    excepted_x_1, excepted_x_2, TWO) == SUCCESS);

    fl = !(full_test(12, 1, 2, 2, -1, -1, -1, 1,
                    excepted_x_1, excepted_x_2, COMPLEX) == SUCCESS);

    fl = !(full_test(13, 13.515, -0.627, 15.632, 0.023196448391, 1.07522216044, 0.023196448391, -1.07522216044,
                    excepted_x_1, excepted_x_2, COMPLEX) == SUCCESS);

    return fl;
}
