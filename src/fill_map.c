/**
 * @ Author: Antoine Deligny
 * @ Create Time: 2022-06-11 07:26:58
 * @ Description:
 */

#include "../include/bsq.h"

void print_color(char *map)
{
    for (int i = 0; map[i] != '\0'; i++) {
        if (map[i] == 'x')
            my_putchar_color("\033[1;31m", map[i]);
        else if (map[i] == 'o')
            my_putchar_color("\033[1;32m", map[i]);
        else
            my_putchar(map[i]);
    }
}

void print_map(char *map)
{
    if (BONUS == true)
        print_color(map);
    else
        my_putstr(map);
}

char *put_cross(bsq_data_t *bsq, char **map, unsigned short **tab)
{
    int n = 0;
    int x = 0;

    for (int nb_y = bsq->save; nb_y > 0; nb_y--) {
        n = 0;
        for (int nb_x = bsq->save; nb_x > 0; nb_x--) {
            x = (bsq->line_size + 1) * (bsq->save_count.first - 1) + bsq->save_count.second - n - 1;
            (*map)[x] = 'x';
            n++;
        }
        bsq->save_count.first -= 1;
    }
    return (*map);
}

char *fill_map(unsigned short **tab, char *map, bsq_data_t *bsq)
{
    if (bsq->save >= 1)
        map = put_cross(bsq, &map, tab);
    return map;
}