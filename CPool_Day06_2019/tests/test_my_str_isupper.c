/*
** EPITECH PROJECT, 2019
** test_my_str_isupper
** File description:
** test if contain or not only upper case caracter
*/

#include <criterion/criterion.h>

int my_str_isupper(char const *str);

Test(my_str_isupper, check_if_return_0_if_not_only_upper)
{
    char str[10] = "azeRtyuiop";

    int got = my_str_isupper(str);
    int expected = 0;

    cr_assert_eq(got, expected);
}

Test(my_str_isupper, check_if_return_1_if_only_uppercase)
{
    char str[10] = "AZERTYUIOP";

    int got = my_str_isupper(str);
    int expected = 1;

    cr_assert_eq(got, expected);
}
