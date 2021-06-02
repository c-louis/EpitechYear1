/*
** EPITECH PROJECT, 2019
** my_showmem
** File description:
** print memory dump
*/

void my_putchar(char c);

int get_display_length_mem(int nbr, char const *base)
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

int call_one_mem(int *nbr, int *i, char *mem, char const *base)
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

int my_putnbr_base_mem(int nbr, char const *base, int wanted_len)
{
    int len = 0;
    int i = 0;
    int checker;
    int disp_len = get_display_length_mem(nbr, base);
    char mem_display[disp_len + 1];

    if (nbr < 0)
        my_putchar('-');
    for (; base[len] != '\0'; len++);
    while (nbr >= len || nbr <= -len){
        call_one_mem(&nbr, &i, mem_display, base);
    }
    call_one_mem(&nbr, &i, mem_display, base);
    for (;disp_len + 1 < wanted_len; wanted_len--)
        my_putchar('0');
    for (int j = disp_len; j != -1; j--)
        my_putchar(mem_display[j]);
}

int my_showmem_part(int *i, char const *str)
{
    if (*i % 16 == 0 && *i != 0){
        my_putchar(' ');
        for (int j = *i - 16; j < *i; j++){
            if (str[j] >= 32 && str[j] <= 127)
                my_putchar(str[j]);
            else
                my_putchar('.');
        }
        my_putchar('\n');
    }
    if (*i % 16 == 0){
        my_putnbr_base_mem(*i, "0123456789abcdef", 8);
        my_putchar(':');
        my_putchar(' ');
        my_putchar(' ');
    }
    my_putnbr_base_mem(str[*i], "0123456789abcdef", 2);
    if (*i % 2 && *i % 16 != 0)
        my_putchar(' ');
}

int my_showmem(char const *str, int size)
{
    int hex_counter = 0;
    int i = 0;
    for (; str[i] != '\0' && i < size; i++){
        my_showmem_part(&i, str);
    }
    for (; i % 16 != 0; i++){
        my_putchar(' ');
        my_putchar(' ');
        if (i % 2 && i % 16 != 0)
            my_putchar(' ');
    }
    my_putchar(' ');
    for (i -= 16; str[i] != '\0' && i < size; i++)
        if (str[i] >= 32 && str[i] <= 127)
            my_putchar(str[i]);
        else
            my_putchar('.');
    my_putchar('\n');
    return (0);
}
