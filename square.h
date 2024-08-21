#pragma once
/*!
    Enum of all root types in square equation
*/
typedef enum {TWO_SIMILAR, INFINITE, COMPLEX, ZERO, ONE, TWO, NON_ROOT_TYPE = 0} roots_type;

/*!
    Enum of all program action types
*/
typedef enum {MANY_EQUATIONS = 2, STANDARD = 1, NON_TYPE = 0} choose_type;

/*!
    Enum of SUCCESS and FAILURE program tags
*/
enum {SUCCESS = 0, FAILURE = 1};
const int NUMBER_OF_TRIES = 10;
const double EPS = 0.01;

/*!
Clean char buffer
*/
void clean_char_buffer();
/*!
Checks if a double value is zero
\param[in] a double value need to check
\return bool value zero of not
*/
bool is_zero(double a);

/*!
Checks if a double value is greater than zero
\param[in] a double value need to check
\return bool value greater than zero of not
*/
bool greater_zero(double a);

/*!
Counts distance between two complex numbers
\param[in] x_1 first complex number
\param[in] x_2 second complex number
\return double distance betwen x_1 and x_2
*/
double distance_between_complex(double *x_1, double *x_2);

/*!
Check if two complex numbers are similar
\param[in] x_1 first complex number
\param[in] x_2 second complex number
\return bool value of similarity
*/
bool complex_are_similar(double *x_1, double *x_2);

/*!
Sorting complex numbers by their real values and if their are equal sort by complex
\param[in] x_1 complex number
\param[in] x_2 complex number
*/
void sort_complex(double *x_1, double *x_2);

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
double calculate_D(double a, double b, double c);
/*!
Provide linear case of square equation
\param[in]  b double b from square equation
\param[in]  c double c from square equation
\param[out] x root from this case
\return type of amount of roots
*/
roots_type linear_case(double b, double c, double x[]);

/*!
Provide square case of square equation
\param[in]  b double b from square equation
\param[in]  c double c from square equation
\param[out] x_1 root from this case
\param[out] x_2 root from this case
\return type of roots
*/
roots_type square_case(double a, double b, double c, double x_1[], double x_2[]);

/*!
Provide square case of square equation
\param[in]  b double b from square equation
\param[in]  c double c from square equation
\param[out] x_1 root from this case
\param[out] x_2 root from this case
\return type of roots
*/
roots_type solve(double a, double b, double c, double x_1[], double x_2[]);

/*!
Print roots
\param[in]  root_fl info about type of roots
\param[in]  x_1 double c from square equation
\param[in]  x_2 double c from square equation
*/
void square_equation_printer(int root_fl, double x_1[], double x_2[]);

/*!
Input roots
\param[in]  a double a from square equation
\param[in]  b double b from square equation
\param[in]  c double c from square equation
*/
int square_equation_input(double *a, double *b, double *c);

/*!
Function for choosing program actions
\return the selected program action
*/
choose_type choose_variant();

/*!
Action with many randomly generated solves of square equation
*/
void many_equations();

/*!
Action with user-specified coefficients
*/
void standard();
