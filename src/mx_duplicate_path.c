#include "pathfinder.h"

t_path *mx_duplicate_path(t_path *path) {
    t_path *dup = NULL;
    t_path *ptr = NULL;

    if (path == NULL)
        return NULL;
    ptr = path;
    while(ptr) {
        mx_push_isl_back(&dup, ptr->isl_name, ptr->rebro);
        ptr = ptr->next_isl;
    }
    return dup;
}
