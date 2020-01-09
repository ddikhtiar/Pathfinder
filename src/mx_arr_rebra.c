#include "pathfinder.h"

char **mx_arr_rebra(const char *str) {
    char *str_dup = mx_strdup(str);
    char *s = str_dup;
    char **arr_reb = NULL;

    while (*s) {
        if (!mx_isdigit(*s))
            *s = ' ';
        s++;
    }
    arr_reb = mx_strsplit(str_dup, ' ');
    mx_strdel(&str_dup);
    return arr_reb; //Возвращаем массив ребер в строковом виде
                    //+ кол-во уникальных островов в нулевой ячейке
}
