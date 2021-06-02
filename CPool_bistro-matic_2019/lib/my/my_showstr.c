/*
** EPITECH PROJECT, 2019
** my_showstr
** File description:
** Print the printable characters,
** and non-printable under hexadecimal values
*/

void my_putchar(char c);

int get_display_length_show(int nbr, char const *base)
{
    int i = 0;
    int len = 0;

    for (; base[len] != '\0'; len++);
    while (nbr >= len || nbr <= -len){
        nbr /= len;
        i++;
    }
    return (i);
}

int call_one_show(int *nbr, int *i, char *mem, char const *base)
{
    int len = 0;
    int checker;

    for (; base[len] != '\0'; len++);
    checker = *nbr % len;
    if (checker < 0)
        checker *= -1;
    *nbr /= len;
    mem[*i] = base[checker];
    *i = *i + 1;
}

int my_putnbr_base_show(int nbr, char const *base)
{
    int len = 0;
    int i = 0;
    int checker;
    int disp_len = get_display_length_show(nbr, base);
    char mem_display[disp_len + 1];

    if (nbr < 0)
        my_putchar('-');
    for (; base[len] != '\0'; len++);
    while (nbr >= len || nbr <= -len){
        call_one_show(&nbr, &i, mem_display, base);
    }
    call_one_show(&nbr, &i, mem_display, base);
    if (disp_len < 2)
        my_putchar('0');
    for (int j = disp_len; j != -1; j--)
        my_putchar(mem_display[j]);
}

int my_isprintable(char c)
{
    if (!(c >= 32 && c <= 127))
        return (0);
    return (1);
}

int my_showstr(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++){
        if (my_isprintable(str[i]) == 1){
            my_putchar(str[i]);
        }else{
            my_putchar('\\');
            my_putnbr_base_show(str[i], "0123456789abcdef");
        }
    }
    return (0);
}
