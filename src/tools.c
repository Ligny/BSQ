/**
 * @ Author: Antoine Deligny
 * @ Create Time: 2022-06-11 07:26:58
 * @ Description:
 */

#include "../include/bsq.h"

bool map_error(char *map)
{
    int save_i = 0;
    int n = 0;

    for (int i = 0; map[i] != '\n' && map[i] != '\0'; i++)
        save_i = i + 1;
    for (int i = 0; map[i] != '\0'; i++) {
        if (map[i] == '\n' && ((i - n) % save_i) != 0)
            return (false);
        if (map[i] == '\n')
            n++;
        if (map[i] != '\n' && map[i] != '.' && map[i] != 'o')
            return (false);
    }
    return (true);
}

int my_custom_atoi(char **str)
{
    int i;
    int nb = 0;

    for (i = 0; (*str)[i] != '\n' && (*str)[i] != '\0'; i++) {
        if ((*str)[i] >= '0' && (*str)[i] <= '9')
            nb = (nb * 10) + ((*str)[i] - '0');
        else
            exit (84);
    }
    i++;
    (*str) += i;
    return (nb);
}

int count_char(char *str)
{
    int i = 0;

    for (; str[i] != '\n' && str[i] != '\0'; i++);
    return (i);
}

unsigned short **my_memset(char **map, bsq_data_t *bsq)
{
    int fbline = 0;
    unsigned short **tab;
    int i = 0;

    if ((fbline = my_custom_atoi(map)) < 0) exit (84);
    bsq->line_size = count_char(*map);
    tab = malloc(sizeof(unsigned short *) * (fbline + 2));
    for (i = 0; i != (fbline + 1); i++) {
        tab[i] = malloc(sizeof(short *) * (bsq->line_size + 1));
        for (int j = 0; j != (bsq->line_size + 1); j++) {
            tab[i][j] = 0;
        }
    }
    tab[i] = NULL;
    return (tab);

}