/*
** EPITECH PROJECT, 2020
** strl_en
** File description:
** str_len
*/

int my_strlen(char const *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++);
    return (i);
}
