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
           "Expected values: root_type = %d, x_1 = %lf + %lf i, x_2 = %lf + %lf i\n"
           "Received values: root_type = %d, x_1 = %lf + %lf i, x_2 = %lf + %lf i\n\n",
            data.number_of_test, data.coefs.a, data.coefs.b, data.coefs.c,
            data.expected_root_type, data.expected_x_1.real, data.expected_x_1.complex,
            data.expected_x_2.real, data.expected_x_2.complex,
            received_root_type, received_x_1.real, received_x_1.complex, received_x_2.real, received_x_2.complex);
}

int run_all_tests()
{
    int fl = SUCCESS;

    fl = !(full_test({1, {1, 2, 1}, {-1, 0}, {-1, 0}, TWO_SIMILAR}) == SUCCESS);

    fl = !(full_test({2, {1, 2, 3}, {-2.0/2, -sqrt(8.0)/2}, {-2.0/2, sqrt(8.0)/2}, COMPLEX}) == SUCCESS);

    fl = !(full_test({3, {5, -4, -1}, {1, 0}, {-1.0/5, 0}, TWO}) == SUCCESS);

    fl = !(full_test({4, {0.5, -2, 1.5}, {1, 0}, {3, 0}, TWO}) == SUCCESS);

    fl = !(full_test({5, {0, 0, 0}, {0, 0}, {0, 0}, INFINITES}) == SUCCESS);

    fl = !(full_test({6, {0.000000000000000001, 0, 1.15125161717}, {0, 0}, {0, 0}, ZERO}) == SUCCESS);

    fl = !(full_test({7, {0, 2, 1}, {0, 0}, {-1/2.0, 0}, ONE}) == SUCCESS);

    fl = !(full_test({8, {1.3, 7.1, -17.157}, {1.8139852069763645, 0}, {-7.275523668514825, 0}, TWO}) == SUCCESS);

    fl = !(full_test({9, {1, 0, 0}, {0, 0}, {0, 0}, TWO_SIMILAR}) == SUCCESS);

    fl = !(full_test({10, {1.00000000000000000001, 0, 0.99999999999999999999999999999}, {0, 1}, {0, -1}, COMPLEX}) == SUCCESS);

    fl = !(full_test({11, {1, 1650.73138, -28606.9796525}, {17.151616, 0}, {-1667.8883, 0}, TWO}) == SUCCESS);

    fl = !(full_test({12, {1, 2, 2}, {-1, -1}, {-1, 1}, COMPLEX}) == SUCCESS);

    fl = !(full_test({13, {13.515, -0.627, 15.632}, {0.023196448391, 1.07522216044}, {0.023196448391, -1.07522216044}, COMPLEX}) == SUCCESS);

    fl = !(full_test({14, {0, 2, 125}, {0, 0}, {-1/2.0, 0}, ONE}) == SUCCESS);

    return fl;
}
