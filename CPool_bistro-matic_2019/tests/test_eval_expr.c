/*
** EPITECH PROJECT, 2019
** test_eval_expr
** File description:
** test function for the eval expr
*/

#include <criterion/criterion.h>
#include "my.h"
#include "eval.h"
#include "bistromatic.h"

Test(eval_add, test_additions)
{
    cr_assert_str_eq(eval_expr("1234567890+9876543210"), "11111111100");
}

Test(eval_sub, test_subtractions)
{
    cr_assert_str_eq(eval_expr("1234567890-9876543210"), "-8641975320");
}

Test(eval_mul, does_the_multiplication_work_properly_eval)
{
    cr_assert_str_eq(eval_expr("1234567890*21"), "25925925690");
}

Test(eval_div, does_the_division_work_properly_eval)
{
    cr_assert_str_eq(eval_expr("144/12"), "12");
}

Test(eval_expr_hard, does_the_hard_operations_work_properly_eval)
{
    cr_assert_str_eq(eval_expr("2*(57+210)-123456789/9"), "-13716887");
}

Test(eval_parenthesis, counting_parenthesis_eval)
{
    cr_assert_str_eq(eval_expr("2*(54+45*(56+5/5)*(45%2))"), "5238");
}

Test(eval_parenthesis_error, counting_parenthesis_with_error_eval)
{
    char *expr = "2*(54+45*(56+(5/5)*(45%2))";
    char *res = "5238";

    cr_assert_str_eq(eval_expr(expr), res);
}

Test(eval_utils_exception, unary_operator)
{
    char *expr = "+2+-4*2-4";
    char *res = "-10";

    cr_assert_str_eq(eval_expr(expr), res);
}

Test(eval_get_end_index, hard_calcul)
{
        char *expr = "-(12*(13+15/5*(6/(12+14%(30%5+(10*25)-46)+16)\
        -20)/43)*20)*(-(12-98*42)*(16+63-50/3))";
        char *res = "-744629760";

        cr_assert_str_eq(eval_expr(expr), res);
}
