//#include "TXLib.h"
#include <stdio.h>
#include "unit_tests.h"
#include "main.h"


int main()
{
    choose_type note = choose_variant();

    switch (note)
    {
        case STANDARD:
            standard();
            break;
        case MANY_EQUATIONS:
            many_equations();
            break;
        case UNIT_TESTS:
            run_all_tests();
            break;
        case NON_TYPE:
            printf("No choose\n");
            break;
        default:
            printf("Unknown command\n");
            break;
    }
    return SUCCESS;
}

choose_type choose_variant()
{
    int choose = NON_TYPE;
    int fl = 0;
    while (choose != STANDARD and choose != MANY_EQUATIONS and choose != UNIT_TESTS and !fl)
    {
        printf("Choose what you want\n1) Standard input\n2) Random input\n3) Unit tests\n");
        fl = scanf("%d", &choose);

        if (choose != STANDARD and choose != MANY_EQUATIONS and choose != UNIT_TESTS and !fl)
        {
            printf("Wrong input, try again\n");
            clean_char_buffer();
        }
    }
    switch (choose)
    {
        case NON_TYPE:
            return NON_TYPE;
            break;
        case STANDARD:
            return STANDARD;
            break;
        case MANY_EQUATIONS:
            return MANY_EQUATIONS;
            break;
        case UNIT_TESTS:
            return UNIT_TESTS;
            break;
        default:
            return NON_TYPE;
            break;
    }
}
