#include "pathfinder.h"

t_data *mx_create_data(const char *str) {
    t_data *DATA = (t_data *) malloc(sizeof(t_data));
    int islands = mx_num_islands(str);
    int rebers = mx_num_rebers(str);
    int **matrix = mx_matrix_incident(str);
    char **arr_uniq = mx_unique(str);

    if (DATA == NULL)
        return NULL;
    DATA->MI = matrix;
    DATA->AU = arr_uniq;
    DATA->n_i = islands;
    DATA->n_r = rebers;
    return DATA;
}
