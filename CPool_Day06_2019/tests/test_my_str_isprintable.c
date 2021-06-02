/*
** EPITECH PROJECT, 2019
** test_my_str_isprintable
** File description:
** check if all the character are printable character
*/

#include <criterion/criterion.h>

int my_str_isprintable(char const *str);

Test(my_str_isprintable, check_if_return_the_0_when_contain_forbid_char)
{
    char str[10] = "azer\vazeae";

    int got = my_str_isprintable(str);
    int expected = 0;

    cr_assert_eq(got, expected);
}

Test(my_str_isprintable, check_if_return_1_when_contain_only_printable)
{
    char str[10] = "azertyuiop";

    int got = my_str_isprintable(str);
    int expected = 1;

    cr_assert_eq(got, expected);
}
