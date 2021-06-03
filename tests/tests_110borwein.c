/*
** EPITECH PROJECT, 2021
** 108trigo
** File description:
** test units
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"

void  redirect_all_std(void)
{
    cr_redirect_stdout();
}

Test(check_number, letter)
{
    char str[] = "aaa";
    int error = check_number(str);

    cr_assert_eq(error, 84);
}

Test(check_number, number)
{
    char str[] = "12";
    int error = check_number(str);

    cr_assert_eq(error, 0);
}

Test(check_number, bad_number)
{
    char str[] = "-10";
    int error = check_number(str);

    cr_assert_eq(error, 84);
}

Test(midpoint_rule, mid_point, .init = redirect_all_std)
{
    int i = 10;

    midpoint_rule(i);
    fflush(stdout);
    cr_assert_stdout_eq_str("Midpoint:\nI10 = 1.5707958915\ndiff = 0.0000004353\n");
}

Test(simpson_rule, simpson, .init = redirect_all_std)
{
    int i = 10;

    simpson_rule(i);
    fflush(stdout);
    cr_assert_stdout_eq_str("\nSimpson:\nI10 = 1.5707958915\ndiff = 0.0000004353\n");
}

Test(trapezoidal_rule, trapez, .init = redirect_all_std)
{
    int i = 10;

    trapezoidal_rule(i);
    fflush(stdout);
    cr_assert_stdout_eq_str("\nTrapezoidal:\nI10 = 1.5707958915\ndiff = 0.0000004353\n");
}

Test(display_usage, display_help, .init = redirect_all_std)
{
    char *argv[] = {"./110borwein", "-h"};
    int ret = 0;

    ret = display_usage(2, argv);
    cr_assert_stdout_eq_str("USAGE.\n    /110borwein n\n\nDESCRIPTION\n    n  constant defining the integral to be computed\n");
    cr_assert_eq(ret, 0);
}

Test(display_usage, display_error, .init = redirect_all_std)
{
    char *argv[] = {"./110borwein", "-h"};
    int ret = 0;

    ret = display_usage(1, argv);
    cr_assert_eq(ret, 84);
}

Test(display_usage, display_error_arg_number, .init = redirect_all_std)
{
    char *argv[] = {"./110borwein", "100"};
    int ret = 0;

    ret = display_usage(2, argv);
    cr_assert_eq(ret, 84);
}

Test(display_usage, display_error_arg, .init = redirect_all_std)
{
    char *argv[] = {"./110borwein", "10"};
    int ret = 0;

    ret = display_usage(2, argv);
    cr_assert_eq(ret, 84);
}