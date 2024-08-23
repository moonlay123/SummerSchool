#include "unit_tests.h"
#include "main.h"

int main()
{
    bool fl = 0;

    basic_color();

    while (!fl)
    {
        basic_color();

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
            case INPUT_UNIT_TEST:
                put_test_to_file(create_test_from_input());
                break;
            case NON_TYPE:
                error_color();
                printf("No choose\n");
                break;
            case EXIT:
                fl = 1;
                break;
            default:
                unexpected_color();
                printf("Unknown command\n");
                break;
        }
    }

    txSetConsoleAttr(0x00);
    txClearConsole();

    return SUCCESS;
}

choose_type choose_variant()
{
    int choose = NON_TYPE;
    int fl = 0;
    while (choose != STANDARD and choose != MANY_EQUATIONS and choose != UNIT_TESTS
                                                and choose != INPUT_UNIT_TEST and choose != EXIT and !fl)
    {
        basic_color();

        printf("Choose what you want\n1) Standard input\n2) Random input\n3) Unit tests\n4) Input your unit test\n5) Exit program\n");
        fl = scanf("%d", &choose);

        if (choose != STANDARD and choose != MANY_EQUATIONS and choose != UNIT_TESTS
                                                and choose != INPUT_UNIT_TEST and choose != EXIT and !fl)
        {
            failure_color();

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
        case INPUT_UNIT_TEST:
            return INPUT_UNIT_TEST;
            break;
        case EXIT:
            return EXIT;
            break;
        default:
            return NON_TYPE;
            break;
    }
}
