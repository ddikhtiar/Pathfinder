#include "pathfinder.h"

char **mx_arr_islands(const char *str) {
    char *s_dup = mx_strdup(str);
    char *s = s_dup;
    char **arr_isl = NULL;

    while (*s) {
        if (!mx_isalpha(*s))
            *s = ' ';
        s++;
    }
    arr_isl = mx_strsplit(s_dup, ' ');
    mx_strdel(&s_dup);
    return arr_isl; //Возвращаем массив всех островов (с повторениями)
}
