#ifndef complexer
#define complexer

/*!
Struct defining complex numbers
*/
struct complex
{
    /*@{*/
    double real;        /*!< contains real value of complex number  */
    double imaginary;   /*!< contains imaginary value of complex number  */
    /*@}*/
};

const double EPS = 0.01;

/*!
swap complex numbers
\param[in] x_1 first complex number
\param[in] x_2 second complex number
*/
void complex_swap(complex *x_1, complex *x_2);

/*!
Sorting complex numbers by their real values and if their are equal sort by complex
\param[in] x_1 complex number
\param[in] x_2 complex number
*/
void sort_complex(complex *x_1, complex *x_2);

/*!
Counts distance between two complex numbers
\param[in] x_1 first complex number
\param[in] x_2 second complex number
\return double distance betwen x_1 and x_2
*/
double distance_between_complex(complex x_1, complex x_2);

/*!
Check if two complex numbers are similar
\param[in] x_1 first complex number
\param[in] x_2 second complex number
\return bool value of similarity
*/
bool complex_are_similar(complex x_1, complex x_2);

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

#endif
