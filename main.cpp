#include "unit_tests.h"
#include "main.h"

int compare(const void *a, const void *b)
{
    int l = *((const int *) a);
    int r = *((const int *) b);
    return l-r;
}

int main(int argc, char *argv[])
{
    ++argv; --argc;
    int *queue = (int *) calloc(argc, sizeof(int));

    int files_uk = 0, file_flag_counts = 0;
    char **files = (char **) calloc(argc, sizeof(char *));

    basic_color();
    for (int i = 0; i < argc; ++i)
    {
        if (!strcmp(argv[i], "-menu"))
        {
            queue[i] = MENU;
        } else if(!strcmp(argv[i], "-rand"))
        {
            queue[i] = RAND_COLOR;
        } else if(!strcmp(argv[i], "-file"))
        {
            queue[i] = FILE_FLAG;
            ++file_flag_counts;
        } else if(argv[i][0] != '-')
        {
            files[files_uk++] = argv[i];
            queue[i] = NOTHING;
        } else if(!strcmp(argv[i], "-clean"))
        {
            queue[i] = CLEAN_CONSOLE;
        }
        else
        {
            queue[i] = NOTHING;
        }
    }

    assert(files_uk == file_flag_counts);

    qsort(queue, argc, sizeof(int), compare);

    flag_actions(files, queue, argc, files_uk);

    txSetConsoleAttr (0x00);


    return SUCCESS;
}

void flag_actions(char **files, int *queue, int argc, int files_size)
{
    int files_uk = 0;
    for(int i = 0; i < argc; ++i)
    {
        switch (queue[i])
        {
            case NOTHING:
                break;
            case EXIT_FLAG:
                break;
            case HELP:
                break;
            case RAND_COLOR:
                random_color();
                break;
            case FILE_FLAG:
                file_flag(files, files_size, files_uk++);
                break;
            case MENU:
                menu();
                break;
            case CLEAN_CONSOLE:
                txClearConsole();
                break;
            default:
                help();
                break;
        }
    }

    free(queue);
    free(files);
}

void file_flag(char ** files, int files_size, int files_uk)
{
    assert(files_uk < files_size);
    assert(files[files_uk] != NULL);

    FILE *fp;
    if ((fp = fopen(files[files_uk], "r")) == NULL)
    {
        error_color();
        printf("No file with name %s", files[files_uk]);
        basic_color();

        return;
    }

    coefficients coefs = {0, 0, 0};
    if (fscanf(fp, "%lf %lf %lf", &coefs.a, &coefs.b, &coefs.c) < 3)
    {
        error_color();
        printf("Wrong file structure, it must looks like a b c of square equation");
        basic_color();
    }

    solve_with_print(coefs);
}

void help()
{
    unexpected_color();
    printf("I'm too lazy to write it, see in new versions");
    basic_color();
}

void menu()
{
    bool fl = 0;

    while (!fl)
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
            case INPUT_UNIT_TEST:
                put_test_to_file(create_test_from_input());
                break;
            case NON_TYPE:
                error_color();
                printf("No choose");
                basic_color();
                break;
            case EXIT:
                fl = 1;
                break;
            default:
                unexpected_color();
                printf("Unknown command");
                basic_color();
                break;
        }
    }
}

choose_type choose_variant()
{
    int choose = NON_TYPE;
    int fl = 0;
    while (choose != STANDARD and choose != MANY_EQUATIONS and choose != UNIT_TESTS
                                                and choose != INPUT_UNIT_TEST and choose != EXIT and !fl)
    {
        printf("Choose what you want\n1) Standard input\n2) Random input\n3) Unit tests\n4) Input your unit test\n5) Exit program\n");
        fl = scanf("%d", &choose);

        if (choose != STANDARD and choose != MANY_EQUATIONS and choose != UNIT_TESTS
                                                and choose != INPUT_UNIT_TEST and choose != EXIT and !fl)
        {
            failure_color();
            printf("Wrong input, try again");
            basic_color();
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
