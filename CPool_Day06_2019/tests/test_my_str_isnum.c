/*
** EPITECH PROJECT, 2019
** test_my_str_isnum
** File description:
** test if contain or not only digits caracter
*/

#include <criterion/criterion.h>

int my_str_isnum(char const *str);

Test(my_str_isnum, check_if_return_0_if_not_only_digits)
{
    char str[10] = "11112aze";

    int got = my_str_isnum(str);
    int expected = 0;

    cr_assert_eq(got, expected);
}

Test(my_str_isnum, check_if_return_1_if_only_num)
{
    char str[10] = "8437291";

    int got = my_str_isnum(str);
    int expected = 1;

    cr_assert_eq(got, expected);
}
