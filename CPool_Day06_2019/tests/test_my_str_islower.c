/*
** EPITECH PROJECT, 2019
** test_my_str_islower
** File description:
** test if contain or not only lower case caracter
*/

#include <criterion/criterion.h>

int my_str_islower(char const *str);

Test(my_str_islower, check_if_return_0_if_not_only_lower)
{
    char str[10] = "azeRtyuiop";

    int got = my_str_islower(str);
    int expected = 0;

    cr_assert_eq(got, expected);
}

Test(my_str_islower, check_if_return_1_if_only_lowercase)
{
    char str[10] = "azertyuiop";

    int got = my_str_islower(str);
    int expected = 1;

    cr_assert_eq(got, expected);
}
