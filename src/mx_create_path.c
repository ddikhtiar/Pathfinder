#include "pathfinder.h"

t_list_p *mx_create_path(t_path *road) {
    t_list_p *path = (t_list_p *) malloc(sizeof(t_list_p));

    if (path == NULL)
        return NULL;
    path->link = road;
    path->next_path = NULL;
    return path;
}
