#include "flags_controller.h"

void files_handler(console_flags *flags, char **argv)
{
    for (int i = 0; i < min(flags->file_num, flags->filenames_size); ++i)
    {
        file_flag(argv[flags->filenames[flags->filenames_uk++]]);
    }
}

void flag_handler(console_flags *flags, int argc, char **argv)
{
    assert(flags != NULL);
    assert(argv  != NULL);

    basic_color();

    for (int i = 0; i < argc; ++i)
    {
        if (!strcmp(argv[i], "-menu"))
        {
            flags->menu_flag = true;
        } else if(!strcmp(argv[i], "-rand"))
        {
            flags->rand_flag = true;
        } else if(!strcmp(argv[i], "-test"))
        {
            flags->file_num++;
        } else if(argv[i][0] != '-')
        {
            flags->filenames[flags->filenames_size++] = i;
        } else if(!strcmp(argv[i], "-clean"))
        {
            flags->clean_flag = true;
        } else if(!strcmp(argv[i], "-exit"))
        {
            flags->exit_flag = true;
        } else if(!strcmp(argv[i], "-help"))
        {
            flags->help_flag = true;
        }
        else
        {
            unexpected_color();
            printf("No such flag %s", argv[i]);
            basic_color();
        }
    }

    if (flags->file_num != flags->filenames_size)
    {
        error_color();
        printf("You choosed %d file flags, but gave %d", flags->file_num, flags->filenames_size);
        basic_color();
        getchar();
    }
}

int file_open(FILE **fp, char *filename)
{
    if ((*fp = fopen(filename, "r")) == NULL)
    {
        error_color();
        perror("Open failed");
        basic_color();
        getchar();

        return FAILURE;
    }

    return SUCCESS;
}

void file_close(FILE **fp)
{
    if(fclose(*fp) != 0)
    {
        perror("Close failed");
    }
}

void file_flag(char *filename)
{
    assert(filename != NULL);

    FILE *fp = NULL;
    if (file_open(&fp, filename) == FAILURE)
        return;
    coefficients coefs = {0, 0, 0};
    if (fscanf(fp, "%lf %lf %lf", &coefs.a, &coefs.b, &coefs.c) < 3)
    {
        error_color();
        printf("Wrong file structure, it must looks like a b c of square equation");
        basic_color();
        getchar();
    }

    printf("Solve of square equation from file with path %s\n", filename);
    solve_with_print(coefs);
    getchar();

    file_close(&fp);
}

void help()
{
    unexpected_color();
    printf("Usage: ./proj [flags] [files] in any order\n"
           "-rand\t Create random color setup for console for once\n"
           "-help\t open help tips\n"
           "-menu\t open choosing menu\n"
           "-test\t choose file with quadratic coefs and get solve\n"
           "-clean\t Clear console window after program end\n");
    basic_color();
    getchar();
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
