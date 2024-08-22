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

#endif
