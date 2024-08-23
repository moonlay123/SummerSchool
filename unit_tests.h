#ifndef unit_tests
#define unit_tests
#include "square.h"

/*!
Struct defining unit_test
*/
struct unit_test
{
    /*@{*/
    int number_of_test; /*!< number of this test */
    coefficients coefs; /*!< coefs of square equation*/
    complex expected_x_1, expected_x_2; /*!< expected complex roots of square equation*/
    roots_type expected_root_type; /*!< exprected root type of square equation*/
    /*@}*/
};

const int MAX_TESTS = 100;

struct test_bufer
{
    int size;
    unit_test tests[MAX_TESTS];
};

/*!
Check test solve correctness
\param[in] data unit_test data
\param[in] received_x_1 received root of square equation
\param[in] received_x_2 received root of square equation
\param[in] received_root_type expected type of root, returns from solve of square equation
\return bool value of test correctness
*/
bool check_test_correctness(unit_test data,
                            complex received_x_1, complex received_x_2, roots_type received_root_type);

/*!
print all received and expected values of incorrect test
\param[in] data unit_test data
\param[in] received_x_1 received root of square equation
\param[in] received_x_2 received root of square equation
\param[in] received_root_type expected type of root, returns from solve of square equation
*/
void print_results(unit_test data,
                    complex received_x_1, complex received_x_2, roots_type received_root_type);


/*!
Creates full test
\param[in] data unit_test data
\return correctness of test
*/
int full_test(unit_test data);

/*!
Running all the created tests
\return correctness of tests
*/
int run_all_tests();

/*!
Input your test to specified file
\param[in] data unit_test putting to file
*/
void put_test_to_file(unit_test data);

/*!
Read file
\return test_bufer of tests in file
*/
test_bufer read_file();

/*!
Create unit_test from input data
*/
unit_test create_test_from_input();

/*!
Input expected root type from console
\param[in] expected_root_type address of expected root type
*/
void input_roots_type(roots_type *expected_root_type);

/*!
Convert expected root type from int format
\param[in]  expected_root_int int format of expected_root_type
\param[out] expected_root_type roots_type format
*/
void convert_roots_type(int expected_root_int, roots_type *expected_root_type);

/*!
Input expected roots from console
\param[in] x_1 address of expected root
\param[in] x_2 address of expected root
*/
void input_roots(complex *x_1, complex *x_2);

#endif
