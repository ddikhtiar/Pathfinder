#include "pathfinder.h"

static void sx_plus(t_data *D, t_list_p *list);

t_list_p *mx_list_of_lists(t_data *D) {
    t_list_p *list = NULL;
    t_path *new = NULL;

    for (int t = 1; t < D->n_i; t++) {
        for (int j = 0; j < D->n_r; j++) {
            if (D->MI[t][j] == 1) {
                new = mx_create_island(D->AU[t - 1], 0);
                for (int k = 1; k <= D->n_i; k++) {
                    if (D->MI[k][j] == 1 && k != t) {
                        mx_push_isl_back(&new, D->AU[k - 1], D->MI[0][j]);
                        mx_push_path_back(&list, new);
                    }
                }
            }
        }
    }
    sx_plus(D, list);
    sx_plus(D, list);
    sx_plus(D, list);
    return list; //Возвращаем список всех существующих путей
}

static void sx_plus(t_data *D, t_list_p *list) {
    for (int i = 1; i <= D->n_i; i++)
        mx_plus_next_island(D, list, i);
}
