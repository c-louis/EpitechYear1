/*
** EPITECH PROJECT, 2019
** bistro
** File description:
** test error functions
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdio.h>
#include "error.h"
#include "my.h"
#include "bistromatic.h"

void par_num(char *num, char *op, int size);

int find_char(char op, char *num, char *sign);

int find_db_char(char *str);

Test(argc_nb, wrong_arg_nb, .exit_code = 84, .init = cr_redirect_stderr)
{
    argc_nb(3);
    cr_assert_stderr_eq_str(SYNTAX_ERROR_MSG);
}

Test(sign_follow, two_sign_following, .exit_code = 84,
    .init = cr_redirect_stderr)
{
    sign_follow("2**(57+210)-123456789/9", "0123456789", "()+-*/%",
        my_strlen("2**(57+210)-123456789/9"));
    cr_assert_stderr_eq_str(SYNTAX_ERROR_MSG);
}

Test(check_ops, wrong_operators, .exit_code = 84, .init = cr_redirect_stderr)
{
    check_ops("7");
    cr_assert_stderr_eq_str(SYNTAX_ERROR_MSG);
}

Test(check_base, wrong_base, .exit_code = 84, .init = cr_redirect_stderr)
{
    check_base("(");
    cr_assert_stderr_eq_str(SYNTAX_ERROR_MSG);
}

Test(check_par, unmatched_par_1, .exit_code = 84, .init = cr_redirect_stderr)
{
    check_par(")2*(57+210)-123456789/9", "()+-/*%",
    my_strlen(")2*(57+210)-123456789/9"));
    cr_assert_stderr_eq_str(SYNTAX_ERROR_MSG);
}

Test(check_par, unmatched_par_2, .exit_code = 84, .init = cr_redirect_stderr)
{
    check_par("2*((57+210)-123456789/9", "()+-/*%",
    my_strlen("2*((57+210)-123456789/9"));
    cr_assert_stderr_eq_str(SYNTAX_ERROR_MSG);
}

Test(argc_nb, correct_arg_nb, .exit_code = 0)
{
    argc_nb(4);
}

Test(sign_follow, no_following_signs, .exit_code = 0)
{
    sign_follow("2*(57+210)-123456789/9", "0123456789", "()+-*/%",
        my_strlen("2*(57+210)-123456789/9"));
}

Test(check_ops, correct_operators, .exit_code = 0)
{
    check_ops("()+-*/%");
}

Test(check_base, correct_base, .exit_code = 0)
{
    check_base("0123456789");
}

Test(check_par, matching_parenthesis, .exit_code = 0)
{
    check_par("2*(57+210)-123456789/9", "()+-/*%",
        my_strlen("2*(57+210)-123456789/9"));
}

Test(find_num, matching_num, .exit_code = 0)
{
    char *str = "456";
    int res = find_num('4', str);
    cr_assert_eq(res, 0);
}

Test(find_num, not_matching_num, .exit_code = 0)
{
    char *str = "456";
    int res = find_num('9', str);
    cr_assert_eq(res, 84);
}

Test(find_char, find_num)
{
    int res = find_char('3', "0123456789", "()+-/*%");
    cr_assert_eq(res, 0);
}

Test(find_char, find_op)
{
    int res = find_char('+', "0123456789", "()+-/*%");
    cr_assert_eq(res, 0);
}

Test(find_char, find_nothing)
{
    int res = find_char('P', "0123456789", "()+-/*%");
    cr_assert_eq(res, 84);
}

Test(find_db_char, positive_double_char)
{
    char *str = "()++/*%";
    int res = find_db_char(str);
    cr_assert_eq(res, 84);
}

Test(find_db_char, negative_double_char)
{
    char *str = "()+-/*%";
    int res = find_db_char(str);
    cr_assert_eq(res, 0);
}

Test(base_check, check_base_and_num, .exit_code = 84,
    .init = cr_redirect_stderr)
{
    char *num = "0123456789";
    char *sign = "()3-/*%";
    base_check(num, sign);
    cr_assert_stderr_eq_str(SYNTAX_ERROR_MSG);
}

Test(base_check, check_num, .exit_code = 84, .init = cr_redirect_stderr)
{
    char *num = "0323456789";
    char *sign = "()+-/*%";
    base_check(num, sign);
    cr_assert_stderr_eq_str(SYNTAX_ERROR_MSG);
}

Test(base_check, check_sign, .exit_code = 84, .init = cr_redirect_stderr)
{
    char *num = "0123456789";
    char *sign = "()++/*%";
    base_check(num, sign);
    cr_assert_stderr_eq_str(SYNTAX_ERROR_MSG);
}
