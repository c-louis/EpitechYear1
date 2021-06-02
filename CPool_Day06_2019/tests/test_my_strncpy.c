/*
** EPITECH PROJECT, 2019
** my_strncpy
** File description:
** test for strncpy
*/

#include <criterion/criterion.h>

char *my_strncpy(char *dest, char const *src, int n);

Test(my_strncpy, copy_five_caracter_in_empty_array_from_larger_array)
{
    char dest[6] = {0};

    my_strncpy(dest, "HelloWorldHowAreYou?", 5);
    cr_assert_str_eq(dest, "Hello");
}

Test(my_strncpy, copy_five_caracter_in_empty_array_from_smallest_array)
{
    char dest[6] = {0};
    my_strncpy(dest, "Hey", 5);
    cr_assert_str_eq(dest, "Hey\0");
}

