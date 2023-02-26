/*
** EPITECH PROJECT, 2021
** delivery
** File description:
** map
*/
#include "sokoban.h"

void open_map(char *map, skb_t *sk)
{
    int m;
    struct stat inf;

    m = open(map, O_RDONLY);
    if (m == -1) {
        exit (84);
    }
    else {
        stat(map, &inf);
        if (inf.st_size == 0) {
            exit (84);
        }
        sk->map = malloc(sizeof(char) * (inf.st_size + 1));
        read(m, sk->map, inf.st_size);
        sk->map[inf.st_size] = '\0';
    }
    close(m);
}

int colum(skb_t *sk)
{
    int i = 0;

    for (int z  = 0, r = 0; sk->map[z] != 0; z++) {
        for (r = 0 ;sk->map[z] != '\n' && sk->map[z] != 0; r++, z++);
        if (r > i)
            i = r;
    }
    sk->colm = i + 1;
    return (i + 1);
}

int line(skb_t *sk)
{
    int j = 0;

    for (int i = 0; sk->map[i] != '\0'; i++) {
        if (sk->map[i] == '\n')
            j++;
    }
    sk->lines = j;
    return (j);
}

void mapt(skb_t *sk)
{
    int j = 0;
    int lines = line(sk);

    colum(sk);
    sk->tab = malloc(sizeof(char *) * (lines + 1));
    for (int i = 0, index = 0; sk->map[i] != '\0'; i++) {
        if (index == 0)
            sk->tab[j] = malloc(sizeof(char) * my_strlen(sk->map) + 1);
        if (sk->map[i] == '\n') {
            sk->tab[j][index] = sk->map[i];
            sk->tab[j][index + 1] = '\0';
            index = 0;
            j++;
        }
        else {
            sk->tab[j][index] = sk->map[i];
            index++;
        }
    }
    sk->tab[j] = NULL;
}