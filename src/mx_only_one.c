#include "pathfinder.h"

bool mx_only_one(t_list_p **list, t_path *path) {
	t_list_p *pl = *list;
	t_path *sample;
	t_path *start;
	
	while (pl) {
		start = pl->link;
		sample = path;
		while (start) {
			if (mx_strcmp(start->isl_name, sample->isl_name) != 0)
				break;
			if (start->next_isl == NULL && sample->next_isl != NULL)
				break;
			if (start->next_isl != NULL && sample->next_isl == NULL)
				break;
			if (start->next_isl == NULL && sample->next_isl == NULL)
				return false;
			start = start->next_isl;
			sample = sample->next_isl;
		}
		pl = pl->next_path;
	}
	return true;
}
