#include "pathfinder.h"

t_path *mx_create_island(char *isl, int reb) {
    t_path *island = (t_path *) malloc(sizeof(t_path));

    if (island == NULL)
        return NULL;
    island->rebro = reb;
    island->isl_name = isl;
    island->next_isl = NULL;
    return island;
}
