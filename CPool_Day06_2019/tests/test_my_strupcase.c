/*
** EPITECH PROJECT, 2019
** test_my_strupcase
** File description:
** test for the uppercase string
*/

#include <criterion/criterion.h>

char *my_strupcase(char *str);

Test(my_strupcase, test_single_word_to_uppercase)
{
    char str1[6] = "Hello";
    char str2[6] = "HELLO";

    cr_assert_str_eq(my_strupcase(str1), str2);
}

Test(my_strupcase, test_sentence_to_uppercase)
{
    char str1[20] = "Hello I'm a Test";
    char str2[20] = "HELLO I'M A TEST";

    cr_assert_str_eq(my_strupcase(str1), str2);
}
