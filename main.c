/**
 * @ Author: Antoine Deligny
 * @ Create Time: 2022-06-11 07:26:58
 * @ Description:
 */

#include "include/bsq.h"

int main(int argc, char **argv)
{
    if (argc == 2) return (bsq_algorithm(argv[1]));
    else return (RETURN_EPITECH_ERROR);
}