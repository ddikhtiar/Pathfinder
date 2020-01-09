#include "pathfinder.h"

void mx_del_intarr(int ***arr_int, int n_i) {
    int **buf = *arr_int;

    for (int y = 0; y <= n_i; y++) {
        free(buf[y]);
    }
    free(*arr_int);
    *arr_int = NULL;
}
