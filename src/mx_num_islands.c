#include "pathfinder.h"

int mx_num_islands(const char *str) {
    int n = 0;
    char **isl = mx_unique(str);

    for (; isl[n] != NULL; n++);
    mx_del_strarr(&isl);
    return n; //Возвращаем количество уникальных островов
}
