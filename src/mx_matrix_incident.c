#include "pathfinder.h"

static void sx_push(int **matrix, int reb, int isl, char **rebra);

int **mx_matrix_incident(const char *str) {
    int **matrix = NULL;
    int rebra = mx_num_rebers(str);
    char **REB = mx_arr_rebra(str);
    int islands = mx_atoi(REB[0]);

    matrix = (int **) malloc(sizeof(int *) * (islands + 1));
	sx_push(matrix, rebra, islands, REB);
    mx_mi_custom(matrix, str, islands, rebra);
    mx_del_strarr(&REB);
    return matrix;
}

static void sx_push(int **matrix, int reb, int isl, char **rebra) {
	for (int i = 0; i <= isl; i++) {
		matrix[i] = (int *) malloc(sizeof(int) * reb);
		for (int r = 0; r < reb; r++)
			matrix[i][r] = -1;
	}
	for (int j = 0; j < reb; j++)
		matrix[0][j] = mx_atoi(rebra[j + 1]);
}
