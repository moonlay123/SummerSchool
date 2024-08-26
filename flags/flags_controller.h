#ifndef choosing
#define choosing
#include "../unit_tests/unit_tests.h"
/*!
    Enum of all program action types
*/
typedef enum {EXIT = 5, INPUT_UNIT_TEST = 4, UNIT_TESTS = 3, MANY_EQUATIONS = 2, STANDARD = 1, NON_TYPE = 0} choose_type;

const int MAX_FILES = 100;
/*!
Struct defining console flags info
*/
struct console_flags
{
    /*@{*/
    bool menu_flag = false; /*!< contains bool of menu flag info */
    bool clean_flag = false; /*!< contains bool of clean flag info */
    bool rand_flag = false; /*!< contains bool of rand flag info */
    bool help_flag = false; /*!< contains bool of help flag info */
    bool exit_flag = false; /*!< contains bool of exit flag info */

    int file_num = 0; /*!< contains int info of number of -test flags */
    int filenames_size = 0; /*!< contains int info of console entered filenames num*/
    int filenames_uk = 0; /*!< Pointer to current filenames position*/
    int filenames[MAX_FILES] = {}; /*!<mas of argv indexes of files*/
    /*@}*/
};
/*!
Function for choosing program actions
\return the selected program action
*/
choose_type choose_variant();

/*!
Function using with -menu flag
*/
void menu();

/*!
Print help docs
*/
void help();

/*!
Solve square root equation from getted file
\param[in] filename name of file
*/
void file_flag(char *filename);

/*!
Handle all flag cases
\param[in] flags all flags info
\param[in] argc number of flags
\param[in] argv all console flags
*/
void flag_handler(console_flags *flags, int argc, char **argv);

/*!
Open file and put pointer to it
\param[out] fp file pointer
\param[int] filename path to need file
\return SUCCESS or FAILURE
*/
int file_open(FILE **fp, char *filename);

/*!
Close file by pointer
\param[in\out] fp pointer of file
*/
void file_close(FILE **fp);

/*!
Handle correct amount of files
\param[in] flags all info about flags
\param[in] argv all console flags
*/
void files_handler(console_flags *flags, char **argv);

#endif
