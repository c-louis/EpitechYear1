/*
** EPITECH PROJECT, 2019
** my_strstr
** File description:
** Cut the str input in the first occurence of the str to find
*/

int get_len_strstr(char *str)
{
    int len = 0;
    for (; str[len] != '\0'; len++);
    return (len);
}

int get_index_strstr(char *str, char const *to_find)
{
    int first_occur_i = get_len_strstr(str) + 1;
    int to_find_i = 0;
    for (int i = 0; str[i] != '\0'; i++){
        if (str[i] == to_find[to_find_i]){
            first_occur_i = i - to_find_i;
            to_find_i++;
        }else{
            first_occur_i = get_len_strstr(str) + 1;
            to_find_i = 0;
            if (str[i] == to_find[to_find_i]){
                first_occur_i = i - to_find_i;
                to_find_i++;
            }
        }
        if (to_find[to_find_i] == '\0')
            break;
    }
    return (first_occur_i);
}

char *my_strstr(char *str, char const *to_find)
{
    int len = get_len_strstr(str);
    int index = get_index_strstr(str, to_find);
    char copy[len + 1];

    if (index > len)
        return (0);
    return str + index;
}
