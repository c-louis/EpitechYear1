/*
** EPITECH PROJECT, 2019
** test_my_revstr
** File description:
** test for reverse string
*/

#include <criterion/criterion.h>

char *my_revstr(char *str);

Test(my_revstr, reverse_all_a_string)
{
    char str[6] = "Hello";

    my_revstr(str);
    cr_assert_str_eq(str, "olleH");
}
