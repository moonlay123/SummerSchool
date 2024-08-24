#ifndef square
#define square
#include "console_painting.h"
#include "complex.h"

/*!
Struct defining coefs of square equation
*/
struct coefficients
{
    double a, /*!< a of square equation*/
    b, /*!< b of square equation*/
    c; /*!< c of square equation*/
};

/*!
    Enum of all root types in square equation
*/
typedef enum {TWO_SIMILAR = 6, INFINITES = 5, COMPLEX = 4, ZERO = 3, ONE = 2, TWO = 1, NON_ROOT_TYPE = 0} roots_type;

/*!
    Enum of SUCCESS and FAILURE program tags
*/
enum {SUCCESS = 0, FAILURE = 1};

/*!
Clean char buffer
*/
void clean_char_buffer();

/*!
Do random value double type
\return double random value
*/
double double_rand();
/*!
Calculating Discriminant of square equation
\param[in]  a double a from square equation
\param[in]  b double b from square equation
\param[in]  c double c from square equation
\return calculated discriminant
*/
double calculate_Discriminant(coefficients coefs);
/*!
Provide linear case of square equation
\param[in]  b double b from square equation
\param[in]  c double c from square equation
\param[out] x root from this case
\return type of amount of roots
*/
roots_type linear_case(coefficients coefs, complex *x_1, complex *x_2);

/*!
Provide square case of square equation
\param[in]  b double b from square equation
\param[in]  c double c from square equation
\param[out] x_1 root from this case
\param[out] x_2 root from this case
\return type of roots
*/
roots_type square_case(coefficients coefs, complex *x_1, complex *x_2);

/*!
Provide square case of square equation
\param[in]  b double b from square equation
\param[in]  c double c from square equation
\param[out] x_1 root from this case
\param[out] x_2 root from this case
\return type of roots
*/
roots_type solve(coefficients coefs, complex *x_1, complex *x_2);

/*!
Print roots
\param[in]  root_fl info about type of roots
\param[in]  x_1 double c from square equation
\param[in]  x_2 double c from square equation
\param[in] coefs coefs of square equation
*/
void square_equation_printer(int root_fl, complex x_1, complex x_2, coefficients coefs);

/*!
Input roots
\param[in]  a double a from square equation
\param[in]  b double b from square equation
\param[in]  c double c from square equation
*/
int square_equation_input(coefficients *coefs);

/*!
Action with many randomly generated solves of square equation
*/
void many_equations();

/*!
Action with user-specified coefficients
*/
void standard();

/*!
Function takes coefs of square equation and print solution
\param[in] coefs coefs of square equation
*/
void solve_with_print(coefficients coefs);
#endif
