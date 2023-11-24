/**
 * @ Author: Antoine Deligny
 * @ Create Time: 2022-06-11 07:26:58
 * @ Description:
 */

#include "../include/bsq.h"

bool init_datas(bsq_data_t *bsq, char **map, char *filepath)
{
    struct stat st;

    bsq->save_count.first = 0;
    bsq->save_count.second = 0;
    bsq->save = 0;
    if ((bsq->fd = open(filepath, O_RDONLY)) == -1) return (false);
    if (stat(filepath, &st) == -1) return (false);
    if (st.st_size == 0) return (false);
    bsq->size = st.st_size;
    *map = malloc(sizeof(char) * (bsq->size + 1));
    (*map)[bsq->size] = '\0';
    return (true);
}

bool save_map(bsq_data_t *bsq, char *map)
{
    if (read(bsq->fd, map, bsq->size) == -1) return (false);
    if (map[bsq->size - 1] == 0) return (false);
    return (true);
}