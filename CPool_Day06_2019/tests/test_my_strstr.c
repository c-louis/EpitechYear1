/*
** EPITECH PROJECT, 2019
** test for my_strstr
** File description:
** test strstr with comparaison with the real strstr
*/

#include <criterion/criterion.h>
#include <string.h>

char *my_strstr(char *str, char const *to_find);

Test(my_strstr, test_strstr_with_to_find_empty)
{
    char str[100] = "marvin_is_back";

    cr_assert_str_eq(my_strstr(str, ""), strstr(str, ""));
}

Test(my_strstr, test_strstr_with_null_return)
{
    char str[100] = "Hello Wow Comment va tu jeune enfant ?";

    cr_assert_eq(my_strstr(str, "AHAH"), strstr(str, "AHAH"));
}

Test(my_strstr, test_strstr_with_working_thing)
{
    char str[100] = "HelloCoucouSaMarcheOuPas";

    cr_assert_eq(my_strstr(str, "Coucou"), strstr(str, "Coucou"));
}
