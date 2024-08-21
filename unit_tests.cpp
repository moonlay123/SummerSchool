#include<stdio.h>
#include<math.h>
#include<assert.h>
#include"square.cpp"

/*!
Check correctness of solving square equation and print if it's not correct
\param[in] number_of_test number of test
\param[in] a double b from square equation
\param[in] b double c from square equation
\param[in] c double b from square equation
\param[in] expected_x_1 expected root of square equation
\param[in] expected_x_2 expected root of square equation
\param[in] expected_root_type expected type of root
\return correctness of test
*/
int unit_test(int number_of_test, double a, double b, double c,
              double *expected_x_1, double *expected_x_2, roots_type expected_root_type);


/*!
Check test solve correctness
\param[in] expected_x_1 expected root of square equation
\param[in] received_x_1 received root of square equation
\param[in] expected_x_2 expected root of square equation
\param[in] received_x_2 received root of square equation
\param[in] expected_root_type expected type of root
\param[in] received_root_type expected type of root, returns from solve of square equation
\return bool value of test correctness
*/
bool check_test_correctness(double *expected_x_1, double *received_x_1,
                            double *expected_x_2, double *received_x_2,
                            roots_type expected_root_type, roots_type received_root_type);

/*!
print all received and expected values of incorrect test
\param[in] number_of_test number of test
\param[in] a double b from square equation
\param[in] b double c from square equation
\param[in] c double b from square equation
\param[in] expected_x_1 expected root of square equation
\param[in] received_x_1 received root of square equation
\param[in] expected_x_2 expected root of square equation
\param[in] received_x_2 received root of square equation
\param[in] expected_root_type expected type of root
\param[in] received_root_type expected type of root, returns from solve of square equation
*/
void print_expected_received(int number_of_test, double a, double b, double c,
                             double *expected_x_1, double *received_x_1,
                             double *expected_x_2, double *received_x_2,
                             roots_type expected_root_type, roots_type received_root_type);

/*!
Running all the created tests
\return correctness of tests
*/
int run_all_tests();



int main()
{
    run_all_tests();
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
        print_expected_received(number_of_test, a, b, c,
                                expected_x_1, received_x_1,
                                expected_x_2, received_x_2,
                                expected_root_type, received_root_type);

        return FAILURE;
    }

    return SUCCESS;
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

void print_expected_received(int number_of_test, double a, double b, double c,
                             double *expected_x_1, double *received_x_1,
                             double *expected_x_2, double *received_x_2,
                             roots_type expected_root_type, roots_type received_root_type)
{
    printf("Test %d with coefs a = %lf, b = %lf, c = %lf\n"
           "Expected values: root_type = %d, x_1 = %lf + %lf i, x_2 = %lf + %lf i\n"
           "Received values: root_type = %d, x_1 = %lf + %lf i, x_2 = %lf + %lf i\n",
            number_of_test, a, b, c,
            expected_root_type, expected_x_1[0], expected_x_1[1], expected_x_2[0], expected_x_2[1],
            received_root_type, received_x_1[0], received_x_1[1], received_x_2[0], received_x_2[1]);
}

int run_all_tests()
{
    double excepted_x_1[2] = {-1, 0}, excepted_x_2[2] = {-1, 0};
    assert(unit_test(1, 1, 2, 1, excepted_x_1, excepted_x_2, TWO_SIMILAR) == SUCCESS);
    return 0;
}
