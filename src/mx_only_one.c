#include "pathfinder.h"

static bool sx_check(t_path *path, t_path *sample);

bool mx_only_one(t_list_p **list, t_path *path) {
    t_list_p *pl = *list;
    t_path *sample;
    t_path *start;

    while (pl) {
        start = pl->link;
        sample = path;
        if (sx_check(start, sample))
            pl = pl->next_path;
        else
            return false;
    }
    return true;
}

static bool sx_check(t_path *path, t_path *sample) {
    while (path) {
        if (mx_strcmp(path->isl_name, sample->isl_name) != 0)
            break;
        if (path->next_isl == NULL && sample->next_isl != NULL)
            break;
        if (path->next_isl != NULL && sample->next_isl == NULL)
            break;
        if (path->next_isl == NULL && sample->next_isl == NULL)
            return false;
        path = path->next_isl;
        sample = sample->next_isl;
    }
    return true;
}
