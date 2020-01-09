#include "pathfinder.h"

void mx_del_path(t_path **path) {
    t_path *p = *path;
    t_path *q = NULL;

    if (p == NULL)
        return;
    else if (p->next_isl == NULL) {
        p->isl_name = NULL;
        free(p);
        p = NULL;
    }
    else {
        q = p->next_isl;
        p->isl_name = NULL;
        p->next_isl = NULL;
        free(p);
        mx_del_path(&q);
    }
}
