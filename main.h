#ifndef choosing
#define choosing
/*!
    Enum of all program action types
*/
typedef enum {EXIT = 5, INPUT_UNIT_TEST = 4, UNIT_TESTS = 3, MANY_EQUATIONS = 2, STANDARD = 1, NON_TYPE = 0} choose_type;

/*!
    Enum of all console action types
*/
typedef enum {CLEAN_CONSOLE = 100, MENU = 4, FILE_FLAG = 3, RAND_COLOR = 2, HELP = 1, NOTHING = 0, EXIT_FLAG = -1} flags_type;

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
\param[in] files mas of all file of flag compile
\param[in] files_size size of files
\param[in] files_uk pointer of current file
*/
void file_flag(char ** files, int files_size, int files_uk);

/*!
Use all flags actions and after free dinamic memory
\param[in] files mas of all file of flag compile
\param[in] queue mas of all "-" flags
\param[in] argc size of queue
\param[in] files_size size of files
*/
void flag_actions(char **files, int *queue, int argc, int files_size);

/*!
Handle all flag cases
\param[out] files mas of file names
\param[in] argv mas of flags
\param[out] queue mas of handled flags
\param[in] argc size of argv, files, queue
\param[out] file_uk pointer of number of files
*/
void flag_handler(char **files, char **argv, int *queue, int argc, int *files_uk);

/*!
Compare for qsort
\param[in] a const addredd of first
\param[in] b const addredd of first
\return compare rule
*/
int compare(const void *a, const void *b);

#endif
