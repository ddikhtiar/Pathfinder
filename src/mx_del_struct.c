#include "pathfinder.h"

void mx_del_struct(t_data **data) {
    t_data *D = *data;
    char **arr_uniq = D->AU;
    int **matrix = D->MI;

    mx_del_strarr(&arr_uniq);
    mx_del_intarr(&matrix, D->n_i);
    free(*data);
    *data = NULL;
}
