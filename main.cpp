#include "unit_tests.h"
#include "main.h"

int main(int argc, char *argv[])
{
    ++argv; --argc;
    int *queue = (int *) calloc(argc, sizeof(int));

    int files_uk = 0;
    char **files = (char **) calloc(argc, sizeof(char *));

    flag_handler(files, argv, queue, argc, &files_uk);

    flag_actions(files, queue, argc, files_uk);

    txSetConsoleAttr (0x00);

    return SUCCESS;
}

void flag_handler(char **files, char **argv, int *queue, int argc, int *files_uk)
{
    assert(files != NULL);
    assert(queue !=NULL);
    assert(files_uk != NULL);

    int file_flag_counts = 0;

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
            files[(*files_uk)++] = argv[i];
            queue[i] = NOTHING;
        } else if(!strcmp(argv[i], "-clean"))
        {
            queue[i] = CLEAN_CONSOLE;
        } else if(!strcmp(argv[i], "-exit"))
        {
            queue[i] = EXIT_FLAG;
        } else if(!strcmp(argv[i], "-help"))
        {
            queue[i] = HELP;
        }
        else
        {
            unexpected_color();
            printf("No such flag");
            basic_color();

            queue[i] = NOTHING;
        }
    }

    assert(*files_uk == file_flag_counts);

    qsort(queue, argc, sizeof(int), compare);
}


int compare(const void *a, const void *b)
{
    assert(a != NULL);
    assert(b != NULL);

    int l = *((const int *) a);
    int r = *((const int *) b);
    return l-r;
}

void flag_actions(char **files, int *queue, int argc, int files_size)
{
    assert(files != NULL);
    assert(queue !=NULL);

    int files_uk = 0;
    if (argc == 0)
        help();
    for(int i = 0; i < argc; ++i)
    {
        switch (queue[i])
        {
            case NOTHING:
                break;
            case EXIT_FLAG:
                free(queue);
                free(files);
                return;
                break;
            case HELP:
                help();
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

void file_flag(char **files, int files_size, int files_uk)
{
    assert(files != NULL);
    assert(files_uk < files_size);
    assert(files[files_uk] != NULL);

    FILE *fp;
    if ((fp = fopen(files[files_uk], "r")) == NULL)
    {
        error_color();
        printf("No file with path %s", files[files_uk]);
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
    printf("Solve of square equation from file with path %s", files[files_uk]);
    solve_with_print(coefs);
}

void help()
{
    unexpected_color();
    printf("Usage: ./main [flags] [files] in any order\n"
           "-rand\t Create random color setup for console for once\n"
           "-help\t open help tips\n"
           "-menu\t open choosing menu\n"
           "-file\t choose file with quadratic coefs and get solve\n"
           "-clean\t Clear console window after program end\n");
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
