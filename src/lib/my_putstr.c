/**
 * @ Author: Antoine Deligny
 * @ Create Time: 2022-11-22 11:02:43
 * @ Description:
 */

#include "../../include/bsq.h"

int my_putstr(char const *str)
{
    int size;

    if (str == NULL)
        return (RETURN_EPITECH_ERROR);
    size = my_strlen(str);
    if (write(1, str, size) == -1)
        return (84);
    return (1);
}