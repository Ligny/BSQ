/**
 * @ Author: Antoine Deligny
 * @ Create Time: 2022-06-16 12:34:33
 * @ Description:
 */

#pragma once

#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdbool.h>

#include "struct.h"

#define RETURN_EPITECH_ERROR 84
#define RETURN_SUCCESS 0

#define BONUS true

bool init_datas(bsq_data_t *bsq, char **map, char *filepath);
bool save_map(bsq_data_t *bsq, char *map);

unsigned short **my_memset(char **map, bsq_data_t *bsq);
int count_char(char *str);
int my_custom_atoi(char **str);
bool map_error(char *map);

int bsq_algorithm(char *filepath);
unsigned short **map_checking(unsigned short **tab, bsq_data_t *bsq, char *map);
void save_values(int x, int y, bsq_data_t *bsq, unsigned short **tab);
unsigned short **find_the_minim(unsigned short **tab, int i, int j);

char *fill_map(unsigned short **tab, char *map, bsq_data_t *bsq);
char *put_cross(bsq_data_t *bsq, char **map, unsigned short **tab);
void print_map(char *map);
void print_color(char *map);

int my_putchar(char c);
int my_putchar_color(char *color, char c);
int my_putstr(char const *str);