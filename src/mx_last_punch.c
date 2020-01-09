#include "pathfinder.h"

void mx_last_punch(const char *str) {
    t_data *data = mx_create_data(str);
    t_list_p *list_full = mx_list_of_lists(data);
    t_list_p *list_short = NULL;

    mx_list_of_short(&list_short, list_full, data);
	mx_list_sort(list_short, data->AU);
    mx_print_paths(list_short);
    mx_del_list(&list_full);
    mx_del_list(&list_short);
    mx_del_struct(&data);
}
