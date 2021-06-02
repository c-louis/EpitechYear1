/*
** EPITECH PROJECT, 2019
** test_my_strcmp
** File description:
** test for my_strcmp
*/

#include<string.h>
#include <criterion/criterion.h>

int my_strncmp(char const *s1, char const *s2, int n);

Test(my_strncmp, test_if_n_inf_to_zero)
{
    char src[12] = "Hello World!";
    char src2[12] = "Hello world!";
    int expected = strncmp(src, src2, -1);
    int got = my_strncmp(src, src2, -1);

    cr_assert_eq(got, expected);
}

Test(my_strncmp, test_if_strncmp_with_n_null)
{
    char src[12] = "Hello World!";
    char src2[12] = "Hello world!";
    int expected = strncmp(src, src2, 0);
    int got = my_strncmp(src, src2, 0);

    cr_assert_eq(got, expected);
}

Test(my_strncmp, test_if_completely_equals)
{
    char src[12] = "Hello World!";
    char src2[12] = "Hello World!";
    int expected = strncmp(src, src2, 5);
    int got = my_strncmp(src, src2, 5);

    cr_assert_eq(got, expected);
}

Test(my_strncmp, test_if_completely_with_n_larger)
{
    char src[12] = "Hello World!";
    char src2[12] = "Hello World!";
    int expected = strncmp(src, src2, 50);
    int got = my_strncmp(src, src2, 50);

    cr_assert_eq(got, expected);
}

Test(my_strncmp, test_if_backslash_0)
{
    char src[20] = "\0azezer";
    char src2[20] = "\0azeaze";
    int expected = strncmp(src, src2, 20);
    int got = my_strncmp(src, src2, 20);

    cr_assert_eq(got, expected);
}
