#include "pathfinder.h"

int **mx_matrix_incident(const char *str) {
    int **matrix = NULL;
    int rebra = mx_num_rebers(str);
    char **REB = mx_arr_rebra(str);
    int islands = mx_atoi(REB[0]);

    matrix = (int **) malloc(sizeof(int *) * (islands + 1));
    for (int i = 0; i <= islands; i++) {
        matrix[i] = (int *) malloc(sizeof(int) * (rebra));
        for (int r = 0; r < rebra; r++)
            matrix[i][r] = -1;
    }
    for (int j = 0; j < rebra; j++)
        matrix[0][j] = mx_atoi(REB[j + 1]);
    mx_mi_custom(matrix, str, islands, rebra);
    mx_del_strarr(&REB);
    return matrix;
}
