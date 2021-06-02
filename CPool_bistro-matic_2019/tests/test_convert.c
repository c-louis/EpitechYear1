/*
** EPITECH PROJECT, 2019
** test_convert
** File description:
** test all the convert_base function
*/

#include <criterion/criterion.h>

int get_base(char c, char const *base);

char *replace_operator(char c, char const *op);

char *convert_bistro(char const *src, char const *base, char const *op);

char *get_index(char const *base, char c);

void mod_end(char c, char **end);

char *my_getnbr_base(char const *str, char const *base);

Test(get_base, test_base_exist)
{
    char c = '+';
    char *base = "()+-/*%";

    cr_assert_eq(get_base(c, base), 2);
}

Test(get_base, test_base_dont_exist)
{
    char c = '$';
    char *base = "()+-/*%";

    cr_assert_eq(get_base(c, base), -1);
}

Test(convert_bistro, test_all_case)
{
    char *op = "azertyu";
    char *base = "qsdfghjklm";

    cr_assert_str_eq(convert_bistro("qsdfghjklmazertyub",
                                    base, op), "123456789()+-*/%?");
}

Test(get_index, test_return_false)
{
    char *res = get_index("()/*%", 'i');
    cr_assert_str_eq(res, "-1");
}

Test(mod_end, test_char_eq_plus)
{
    char *test = "+";
    mod_end('+', &test);
    cr_assert_str_eq(test, "1");
}
