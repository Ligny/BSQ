/**
 * @ Author: Antoine Deligny
 * @ Create Time: 2022-06-11 07:26:58
 * @ Description:
 */

#include "../include/bsq.h"

unsigned short **find_the_minim(unsigned short **tab, int i, int j)
{
    int save_min = tab[i][j - 1];

    if (tab[i - 1][j] < save_min)
        save_min = tab[i - 1][j];
    if (tab[i - 1][j - 1] < save_min)
        save_min = tab[i - 1][j - 1];
    tab[i][j] = save_min + 1;
    return (tab);
}

void save_values(int x, int y, bsq_data_t *bsq, unsigned short **tab)
{
    if (tab[y][x] > bsq->save) {
        bsq->save = tab[y][x];
        bsq->save_count.first = y;
        bsq->save_count.second = x;
    }
}

unsigned short **map_checking(unsigned short **tab, bsq_data_t *bsq, char *map)
{
    int x = 1;
    int y = 1;

    for (int k = 0; map[k] != '\0'; k++) {
        if (map[k] == '.') {
            find_the_minim(tab, y, x);
            save_values(x, y, bsq, tab);
        } else if (map[k] == '\n') {
            y++;
            x = 0;
        } else {
            tab[y][x] == 0;
        }
        x++;
    }
    return (tab);
}

void free_memory(bsq_data_t *bsq, char **map, unsigned short ***tab)
{
    int i;

    free(*map);
    for (int i = 0; (*tab)[i] != NULL; i++)
        free((*tab)[i]);
    free(*tab);
    close(bsq->fd);
    free(bsq);
}

int bsq_algorithm(char *filepath)
{
    bsq_data_t bsq;
    char *map = NULL;
    unsigned short **tab = NULL;

    if (init_datas(&bsq, &map, filepath) == false) return (RETURN_EPITECH_ERROR);
    if (save_map(&bsq, map) == false) return (RETURN_EPITECH_ERROR);
    tab = map_checking(my_memset(&map, &bsq), &bsq, map);
    map = fill_map(tab, map, &bsq);
    print_color(map);
    print_map(map);
    free_memory(&bsq, &map, &tab);
    return (RETURN_SUCCESS);
}
