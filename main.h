#ifndef choosing
#define choosing
/*!
    Enum of all program action types
*/
typedef enum {UNIT_TESTS = 3, MANY_EQUATIONS = 2, STANDARD = 1, NON_TYPE = 0} choose_type;

/*!
Function for choosing program actions
\return the selected program action
*/
choose_type choose_variant();

#endif
