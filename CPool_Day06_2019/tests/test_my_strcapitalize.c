/*
** EPITECH PROJECT, 2019
** test_my_strcapitalize
** File description:
** test for the my_capitalize function
*/

#include <criterion/criterion.h>

char *my_strcapitalize(char *str);

Test(my_strcapitalize, test_simple_capitalizer_sentence)
{
    char got[60] = "bonjour je suis un TEST,+JE-DOIT-tester diffente";
    my_strcapitalize(got);
    char expected[60] = "Bonjour Je Suis Un Test,+Je-Doit-Tester Diffente";

    cr_assert_str_eq(got, expected);
}
