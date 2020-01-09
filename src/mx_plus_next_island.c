#include "pathfinder.h"

static void plus(t_data *D, t_list_p *list, t_path *p_s, int y);

void mx_plus_next_island(t_data *D, t_list_p *list, int y) {
    t_list_p *l = list;
    t_path *p_s = NULL;
    t_path *p_f = NULL;

    while (l) {
        p_s = l->link;
        p_f = p_s;
        while (p_f->next_isl != NULL)
            p_f = p_f->next_isl;
        if (mx_strcmp(p_f->isl_name, D->AU[y - 1]) == 0) 
            plus(D, list, p_s, y);
        l = l->next_path;
    }
}

static void plus(t_data *D, t_list_p *list, t_path *p_s, int y) {
    t_path *dup = NULL;

    for (int i = 0; i < D->n_r; i++) {
        if (D->MI[y][i] == 1) {
            for (int j = 1; j <= D->n_i; j++) {
                if (D->MI[j][i] == 1 && j != y &&
                    mx_next_step(p_s, D->AU[j - 1])) {
                    dup = mx_duplicate_path(p_s);
                    mx_push_isl_back(&dup, D->AU[j - 1], D->MI[0][i]);
                    mx_push_path_back(&list, dup);
                }
            }
        }
    }
}
