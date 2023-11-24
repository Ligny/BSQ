/**
 * @ Author: Antoine Deligny
 * @ Create Time: 2022-11-22 09:46:22
 * @ Description:
 */

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return (i);
}