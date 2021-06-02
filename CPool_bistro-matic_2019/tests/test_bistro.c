/*
** EPITECH PROJECT, 2019
** Eval_expr
** File description:
** test files
*/

#include <criterion/criterion.h>
#include "inf_utils.h"
#include "my.h"
#include "eval.h"
#include "bistromatic.h"

char *eval_expr(char const *str);

char *convert_bistro(char const *src, char const *base, char const *op);

char *mul_str(char *a, char *b);

char *add_str(char *a, char *b);

char *div_str(char *a, char *b);

Test(add_str, does_the_addition_work_properly)
{
    char *expr_add1 = "5";
    char *expr_add2 = "5";
    char *res_add = "10";

    cr_assert_str_eq(add_str(expr_add1, expr_add2), res_add);
}

Test(sub_str, does_the_subtraction_properly)
{
    char *expr_sub1 = "34";
    char *expr_sub2 = "-445";
    char *res_sub = "-411";

    cr_assert_str_eq(add_str(expr_sub1, expr_sub2), res_sub);
}

Test(mul_str, does_the_multiplication_work_properly)
{
    char *expr_mult1 = "1234567890";
    char *expr_mult2 = "21";
    char *res_mult = "25925925690";

    cr_assert_str_eq(mul_str(expr_mult1, expr_mult2), res_mult);
}

Test(div_str, does_the_division_work_properly)
{
    char *expr_div1 = "144";
    char *expr_div2 = "12";
    char *res_div = "12";

    cr_assert_str_eq(div_str(expr_div1, expr_div2), res_div);
}

Test(bistro_base, does_the_base_conversion_work_properly)
{
    char *given_base_num = "azertyuiop";
    char *given_base_sign = "1234567";
    char *original_base_num = "0123456789";
    char *original_base_sign = "()+-*/%";
    char *given_op = "azertyuiop1234567";
    char *res = "123456789()+-*/%";

    cr_assert_str_eq(convert_bistro(given_op, given_base_num, given_base_sign),
        res);
}

Test(eval_expr_hard, does_the_hard_operations_work_properly)
{
    char *expr_hard = "2*(57+210)-123456789/9";
    char *res_hard = "-13716887";

    cr_assert_str_eq(eval_expr(expr_hard), res_hard);
}

Test(eval_expr_hard, does_the_medium_operations_work_properly)
{
    char *expr_medium = "2*(57+210)";
    char *res_medium = "534";

    cr_assert_str_eq(eval_expr(expr_medium), res_medium);
}

Test(eval_parenthesis, counting_parenthesis)
{
    char *expr = "2*(54+45*(56+5/5)*(45%2))";
    char *res = "5238";

    cr_assert_str_eq(eval_expr(expr), res);
}

Test(eval_parenthesis_error, counting_parenthesis)
{
    char *expr = "2*(54+45*(56+(5/5)*(45%2))";
    char *res = "5238";

    cr_assert_str_eq(eval_expr(expr), res);
}

Test(eval_utils_exception, counting_parenthesis)
{
    char *expr = "+2+-4*2-4";
    char *res = "-10";

    cr_assert_str_eq(eval_expr(expr), res);
}

Test(eval_get_end_index, counting_parenthesis)
{
    char *expr = "-(12*(13+15/5*(6/(12+14%(30%5+(10*25)-46)+16)\
-20)/43)*20)*(-(12-98*42)*(16+63-50/3))";
    char *res = "-744629760";

    cr_assert_str_eq(eval_expr(expr), res);
}

Test(eval_get_end_index, test_eval_and_sub_str)
{
    char *expr = "45-3";
    char *res = "42";

    cr_assert_str_eq(eval_expr(expr), res);
}


Test(bistro_base, does_the_end_conversion_work_properly)
{
    char *given_base_num = "azertyuiop";
    char *given_base_sign = "1234567";
    char *original_base_num = "0123456789";
    char *original_base_sign = "()+-*/%";
    char *given_op = "azertyuiop1234567";
    char *res = "-123456789";

    cr_assert_str_eq(convert_end(res, given_base_num, given_base_sign),
        "4zertyuiop");
}
