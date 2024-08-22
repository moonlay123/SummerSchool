#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "unit_tests.h"


int full_test(unit_test data)
{
    complex received_x_1 = {0, 0}, received_x_2 = {0, 0};
    roots_type received_root_type = solve(data.coefs, &received_x_1, &received_x_2);

    sort_complex(&data.expected_x_1, &data.expected_x_2);
    sort_complex(&received_x_1, &received_x_2);

    if (check_test_correctness(data, received_x_1, received_x_2, received_root_type) == FAILURE)
    {
        print_results(data, received_x_1, received_x_2, received_root_type);

        return FAILURE;
    }
    printf("Test %d end with SUCCESS \n\n", data.number_of_test);
    return SUCCESS;
}

bool check_test_correctness(unit_test data,
                            complex received_x_1, complex received_x_2, roots_type received_root_type)
{
    if (data.expected_root_type == received_root_type)
    {
        if (complex_are_similar(data.expected_x_1, received_x_1) and
            complex_are_similar(data.expected_x_2, received_x_2))
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

void print_results(unit_test data, complex received_x_1, complex received_x_2, roots_type received_root_type)
{
    printf("\nTest %d with coefs a = %lf, b = %lf, c = %lf\n"
           "Expected values: root_type = %d, x_1 = %lf - %lf i, x_2 = %lf + %lf i\n"
           "Received values: root_type = %d, x_1 = %lf - %lf i, x_2 = %lf + %lf i\n\n",
            data.number_of_test, data.coefs.a, data.coefs.b, data.coefs.c,
            data.expected_root_type, data.expected_x_1.real, abs(data.expected_x_1.imaginary),
            data.expected_x_2.real, data.expected_x_2.imaginary,
            received_root_type, received_x_1.real, abs(received_x_1.imaginary),
            received_x_2.real, received_x_2.imaginary);
}

int run_all_tests()
{
    int fl = 0;

    test_bufer all_tests;

    for (int i = 0; i < all_tests.size; ++i)
    {
        fl += full_test(all_tests.tests[i]) == FAILURE ? FAILURE : SUCCESS;
    }

    printf("Tests ended with %d failure(s)", fl);
    return fl;
}
