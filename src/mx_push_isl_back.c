#include "pathfinder.h"

void mx_push_isl_back(t_path **path, char *isl, int reb) {
    t_path *jump = *path;

    if (*path == NULL) {
        *path = mx_create_island(isl, reb);
    	return;
    }
    else {
        while (jump->next_isl != NULL) {
            jump = jump->next_isl;
        }
        jump->next_isl = mx_create_island(isl, reb);
    }
}
