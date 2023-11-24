/**
 * @ Author: Antoine Deligny
 * @ Create Time: 2022-06-16 12:34:33
 * @ Description:
 */

#pragma once
#include <sys/types.h>

typedef struct pair_int {
    int first;
    int second;
} pair_int_t;

typedef struct bsq_data {
    int fd;
    off_t size;
    int line_size;
    pair_int_t save_count;
    int save;
} bsq_data_t;