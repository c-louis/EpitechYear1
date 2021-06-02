/*
** EPITECH PROJECT, 2019
** test_my_strcmp
** File description:
** test for my_strcmp
*/

#include<string.h>
#include <criterion/criterion.h>

int my_strcmp(char const *s1, char const *s2);

Test(my_strcmp, test_if_my_strcmp_return_same_as_strcmp)
{
    char src[12] = "Hello World!";
    char src2[12] = "Hello world";
    int expected = strcmp(src, src2);
    int got = my_strcmp(src, src2);

    cr_assert_eq(got, expected);
}

Test(my_strcmp, test_if_my_strcmp_return_0)
{
    char src[12] = "Hello World!";
    char src2[12] = "Hello World!";
    int expected = strcmp(src, src2);
    int got = my_strcmp(src, src2);

    cr_assert_eq(got, expected);
}
