#include "pathfinder.h"

void mx_mi_custom(int **matrix, const char *str, int n_i, int n_r) {
    char **arr = mx_arr_islands(str);
    char **isl = mx_unique(str);

    for (int i = 0; i < n_r; i++) {
        for (int j = 1; j <= n_i; j++) {
            int y1 = 2 * i;
            int y2 = 2 * i + 1;

            if (mx_strcmp(arr[y1], isl[j - 1]) == 0)
                matrix[j][i] = 1;
            if (mx_strcmp(arr[y2], isl[j - 1]) == 0)
                matrix[j][i] = 1;
        }
    }
    mx_del_strarr(&arr);
    mx_del_strarr(&isl);
}
