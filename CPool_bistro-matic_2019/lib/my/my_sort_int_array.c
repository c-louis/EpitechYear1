/*
** EPITECH PROJECT, 2019
** my_sort_int_array
** File description:
** Sort an array of ints in ascending order
*/

void swap_sort(int *a, int *b)
{
    int c = *a;
    *a = *b;
    *b = c;
}

void my_sort_int_array(int *array, int size)
{
    int smallest;
    int dex_memory;

    for (int i = 0; i < size; i++) {
        smallest = array[i];
        for (int j = i; j < size; j++) {
            if (array[j] <= smallest) {
                smallest = array[j];
                dex_memory = j;
                swap_sort(&array[i], &array[j]);
            }
        }
    }
}
