/**
 * @ Author: Antoine Deligny
 * @ Create Time: 2022-11-22 12:02:44
 * @ Description:
 */

#include "../../include/bsq.h"

int my_putchar(char c)
{
    if (write(1, &c, 1) == -1)
        return (RETURN_EPITECH_ERROR);
    return (1);
}

int my_putchar_color(char *color, char c)
{
    if (color == NULL)
        return (RETURN_EPITECH_ERROR);
    if (write(1, color, my_strlen(color)) == -1)
        return (RETURN_EPITECH_ERROR);
    if (write(1, &c, 1) == -1)
        return (RETURN_EPITECH_ERROR);
    if (write(1, "\033[0m", 4) == -1)
        return (RETURN_EPITECH_ERROR);
    return (1);
}