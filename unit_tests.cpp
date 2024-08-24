#include "unit_tests.h"

void put_test_to_file(unit_test data)
{
    FILE *fp;
    if ((fp = fopen("files/tests", "a+")) == NULL)
    {
        exit(EXIT_FAILURE);
    }

    int lines_counter = 1;
    while (!feof(fp))
    {
        if (fgetc(fp) == '\n')
            lines_counter++;
    }
    fprintf(fp, "%d %lf %lf %lf %lf %lf %lf %lf %d\n", lines_counter,
                data.coefs.a, data.coefs.b, data.coefs.c,
                data.expected_x_1.real, data.expected_x_1.imaginary,
                data.expected_x_2.real, data.expected_x_2.imaginary,
                data.expected_root_type);
    fclose(fp);
}
test_bufer read_file()
{
    FILE *fp;
    if ((fp = fopen("files/tests", "r")) == NULL)
    {
        exit(EXIT_FAILURE);
    }

    int number_of_test = 0, test_counter = 0;

    coefficients coefs = {0, 0, 0};
    complex expected_x_1 = {0, 0}, expected_x_2 = {0, 0};

    roots_type expected_root_type = NON_ROOT_TYPE;
    int expected_root_int = NON_ROOT_TYPE;

    test_bufer tests;
    while (fscanf(fp, "%d %lf %lf %lf %lf %lf %lf %lf %d", &number_of_test,
                &coefs.a, &coefs.b, &coefs.c,
                &expected_x_1.real, &expected_x_1.imaginary,
                &expected_x_2.real, &expected_x_2.imaginary,
                &expected_root_int) == 9)
    {
        convert_roots_type(expected_root_int, &expected_root_type);

        unit_test input_unit_test = {number_of_test, coefs, expected_x_1, expected_x_2, expected_root_type};
        tests.tests[test_counter++] = input_unit_test;
    }

    tests.size = test_counter;

    fclose(fp);
    return tests;
}

void convert_roots_type(int expected_root_int, roots_type *expected_root_type)
{
    assert(expected_root_type != NULL);

    switch (expected_root_int)
    {
        case NON_ROOT_TYPE:
            *expected_root_type = NON_ROOT_TYPE;
            break;
        case TWO:
            *expected_root_type = TWO;
            break;
        case ONE:
            *expected_root_type = ONE;
            break;
        case ZERO:
            *expected_root_type = ZERO;
            break;
        case COMPLEX:
            *expected_root_type = COMPLEX;
            break;
        case INFINITES:
            *expected_root_type = INFINITES;
            break;
        case TWO_SIMILAR:
            *expected_root_type = TWO_SIMILAR;
            break;
        default:
            *expected_root_type = NON_ROOT_TYPE;
            break;
    }
}

void input_roots_type(roots_type *expected_root_type)
{
    assert(expected_root_type != NULL);

    int expected_root_int = NON_ROOT_TYPE;
    bool fl = 0;

    while (!fl)
    {
        printf("Enter excepted root type of square equation\n"
                "1) two unique roots\n"
                "2) one root\n"
                "3) zero roots\n"
                "4) two complex roots\n"
                "5) infinite roots\n"
                "6) two similar roots\n");

        if (scanf("%d", &expected_root_int) < 1 or expected_root_int > 6 or expected_root_int < 1)
        {
            failure_color();
            printf("Wrong input, try again");
            basic_color();

            clean_char_buffer();
        } else
        {
            fl = 1;
        }
    }

    convert_roots_type(expected_root_int, expected_root_type);
}

void input_roots(complex *x_1, complex *x_2)
{
    assert(x_1 != NULL);
    assert(x_2 != NULL);

    double x_1_real = 0, x_2_real = 0, x_1_imaginary = 0, x_2_imaginary = 0;
    bool fl = 0;

    while (!fl)
    {
        printf("Enter expected roots as x_1_real x_1_imaginary x_2_real x_2_imaginary\n"
                "If your equation doesn't have enough roots put them as nan nan, inf inf or 0 0\n");

        if (scanf("%lf %lf %lf %lf", &x_1_real, &x_1_imaginary, &x_2_real, &x_2_imaginary) < 4)
        {
            failure_color();
            printf("Wrong input, try again");
            basic_color();
            clean_char_buffer();
        } else
        {
            fl = 1;
        }
    }

    x_1->real = x_1_real;
    x_1->imaginary = x_1_imaginary;
    x_2->real = x_2_real;
    x_2->imaginary = x_2_imaginary;
}

unit_test create_test_from_input()
{

    int number_of_test = 0;

    coefficients coefs = {0, 0, 0};
    square_equation_input(&coefs);

    complex expected_x_1 = {0, 0}, expected_x_2 = {0, 0};
    input_roots(&expected_x_1, &expected_x_2);

    roots_type expected_root_type = NON_ROOT_TYPE;
    input_roots_type(&expected_root_type);

    unit_test test = {number_of_test, coefs, expected_x_1, expected_x_2, expected_root_type};
    return test;
}

int full_test(unit_test data)
{
    complex received_x_1 = {0, 0}, received_x_2 = {0, 0};
    roots_type received_root_type = solve(data.coefs, &received_x_1, &received_x_2);

    sort_complex(&data.expected_x_1, &data.expected_x_2);
    sort_complex(&received_x_1, &received_x_2);

    if (!check_test_correctness(data, received_x_1, received_x_2, received_root_type))
    {
        print_results(data, received_x_1, received_x_2, received_root_type);

        return FAILURE;
    }

    success_color();
    printf("Test %d end with SUCCESS", data.number_of_test);
    basic_color();

    return SUCCESS;
}

bool check_test_correctness(unit_test data,
                            complex received_x_1, complex received_x_2, roots_type received_root_type)
{
    if (data.expected_root_type == received_root_type)
    {
        if (received_root_type == NON_ROOT_TYPE or
            received_root_type == INFINITES or received_root_type == ZERO)
        {
            return true;
        } else if (received_root_type == TWO_SIMILAR or received_root_type == COMPLEX or received_root_type == TWO)
        {
            return (complex_are_similar(data.expected_x_1, received_x_1) and
                    complex_are_similar(data.expected_x_2, received_x_2));
        } else
        {
            return  (complex_are_similar(data.expected_x_1, received_x_1) or
                    complex_are_similar(data.expected_x_2, received_x_2));
        }
    } else
    {
        return false;
    }
}

void print_results(unit_test data, complex received_x_1, complex received_x_2, roots_type received_root_type)
{
    failure_color();
    printf("Test %d with coefs a = %.4lf, b = %.4lf, c = %.4lf\n"
           "Expected values: root_type = %d, x_1 = %.4lf - %.4lf i, x_2 = %.4lf + %.4lf i\n"
           "Received values: root_type = %d, x_1 = %.4lf - %.4lf i, x_2 = %.4lf + %.4lf i",
            data.number_of_test, data.coefs.a, data.coefs.b, data.coefs.c,
            data.expected_root_type, data.expected_x_1.real, abs(data.expected_x_1.imaginary),
            data.expected_x_2.real, data.expected_x_2.imaginary,
            received_root_type, received_x_1.real, abs(received_x_1.imaginary),
            received_x_2.real, received_x_2.imaginary);
    basic_color();
}

int run_all_tests()
{
    int fl = 0;

    test_bufer all_tests = read_file();

    for (int i = 0; i < all_tests.size; ++i)
    {
        fl += full_test(all_tests.tests[i]) == FAILURE ? FAILURE : SUCCESS;
    }
    if (fl == 0)
    {
        success_color();
    } else
    {
        failure_color();
    }
    printf("Tests ended with %d failure(s)", fl);
    basic_color();
    return fl;
}
