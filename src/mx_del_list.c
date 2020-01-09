#include "pathfinder.h"

void mx_del_list(t_list_p **list) {
    t_list_p *p_l_s = *list;
    t_list_p *p_l_f = NULL;

    if (p_l_s == NULL)
        return;
    else if (p_l_s->next_path == NULL) {
        mx_del_path(&(p_l_s->link));
        free(*list);
        *list = NULL;
    }
    else {
        p_l_f = p_l_s->next_path;
        p_l_s->next_path = NULL;
        mx_del_path(&(p_l_s->link));
        free(p_l_s);
        mx_del_list(&p_l_f);
    }
}
