#ifndef PAINT
#define PAINT
#define TX_COMPILED
#include "../TXLib/TXLib.h"

/*!
Create random console color attribute
*/
void random_color();

/*!
Create console color for errors
*/
void error_color();

/*!
Create console color for unexpected behavior
*/
void unexpected_color();
/*!
Create console color for success
*/
void success_color();

/*!
Create console color for failures
*/
void failure_color();

/*!
Create basic console color
*/
void basic_color();

#endif
