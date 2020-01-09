#include "pathfinder.h"

int mx_num_rebers(const char *str) {
    int r = 0;
    char **reb = mx_arr_rebra(str);

    for (; reb[r] != NULL; r++);
    r--;                             //Вычитаем первую строку (не ребро)
    mx_del_strarr(&reb);
    return r;                        //Возвращаем количество ребер
}
