/*
** EPITECH PROJECT, 2019
** test_my_strlowcase
** File description:
** test for the lowercase string
*/

#include <criterion/criterion.h>

char *my_strlowcase(char *str);

Test(my_strlowcase, test_single_word_to_lowercase)
{
    char str1[6] = "HELLO";
    char str2[6] = "hello";

    cr_assert_str_eq(my_strlowcase(str1), str2);
}

Test(my_strlowcase, test_sentence_to_uppercase)
{
    char str1[20] = "HELLO I'M A TEST";
    char str2[20] = "hello i'm a test";

    cr_assert_str_eq(my_strlowcase(str1), str2);
}
