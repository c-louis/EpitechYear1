/*
** EPITECH PROJECT, 2019
** test_my_str_isalpha
** File description:
** test to now if isalpha return 0 or 1
*/

#include <criterion/criterion.h>

int my_str_isalpha(char const *str);

Test(my_str_isalpha, test_if_string_contain_other_than_alpha)
{
    char str[25] = "JE NE SUIS PAS QUE ALPHA";

    int got = my_str_isalpha(str);
    int expected = 0;

    cr_assert_eq(got, expected);
}

Test(my_str_isalpha, test_if_string_contrain_only_alpha)
{
    char str[10] = "AzErTyUiOp";

    int got = my_str_isalpha(str);
    int expected = 1;

    cr_assert_eq(got, expected);
}
