#include "pathfinder.h"

void mx_push_path_back(t_list_p **list_path, t_path *road) {
    t_list_p *jump = *list_path;

    if (*list_path == NULL) {
        *list_path = mx_create_path(road);
        return;
    }
    else {
        while (jump->next_path != NULL) {
            jump = jump->next_path;
        }
        jump->next_path = mx_create_path(road);
    }
}
