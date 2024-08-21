#include "square.h"
#pragma once

/*!
Check correctness of solving square equation and print if it's not correct
\param[in] number_of_test number of test
\param[in] a double a from square equation
\param[in] b double b from square equation
\param[in] c double c from square equation
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
\param[in] a double a from square equation
\param[in] b double b from square equation
\param[in] c double c from square equation
\param[in] expected_x_1 expected root of square equation
\param[in] received_x_1 received root of square equation
\param[in] expected_x_2 expected root of square equation
\param[in] received_x_2 received root of square equation
\param[in] expected_root_type expected type of root
\param[in] received_root_type expected type of root, returns from solve of square equation
*/
void print_results(int number_of_test, double a, double b, double c,
                             double *expected_x_1, double *received_x_1,
                             double *expected_x_2, double *received_x_2,
                             roots_type expected_root_type, roots_type received_root_type);

/*!
Write to x_1 and x_2 values
\param[in] x_1_real real value of x_1
\param[in] x_1_complex complex value of x_1
\param[in] x_2_real real value of x_2
\param[in] x_1_complex complex value of x_1
\param[out] x_1 expected root from x_1
\param[out] x_2 expected root from x_2
*/
void expected_values_creator(double x_1_real, double x_1_complex, double x_2_real, double x_2_complex, double *x_1, double *x_2);

/*!
Creates full test
\param[in] number_of_test number of test
\param[in] a double a from square equation
\param[in] b double b from square equation
\param[in] c double c from square equation
\param[in] x_1_real real value of expected_x_1
\param[in] x_1_complex complex value of expected_x_1
\param[in] x_2_real real value of expected_x_2
\param[in] x_1_complex complex value of expected_x_1
\param[in] x_1 expected root from x_1
\param[in] x_2 expected root from x_2
\param[in] expected_x_1 expected root of square equation
\param[in] expected_x_2 expected root of square equation
\param[in] expected_root_type expected type of root
\return correctness of test
*/
int full_test(int number_of_test, double a, double b, double c, double x_1_real, double x_1_complex, double x_2_real, double x_2_complex,
              double *expected_x_1, double *expected_x_2, roots_type expected_root_type);

/*!
Running all the created tests
\return correctness of tests
*/
int run_all_tests();
