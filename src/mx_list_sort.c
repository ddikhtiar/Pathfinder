#include "pathfinder.h"

static bool sx_fifo(t_path *first, t_path *second, char **arr);
static bool sx_gemini(t_path *first, t_path *second);
static int sx_number(const char *s1, const char *s2, char **arr);

void mx_list_sort(t_list_p *list, char **arr_isl) {
	t_list_p *copy = list;
	t_path *first;
	t_path *second;

	while (copy->next_path != NULL) {
		first = copy->link;
		second = copy->next_path->link;
		if (sx_gemini(first, second) && !sx_fifo(first, second, arr_isl)) {
			copy->link = second;
			copy->next_path->link = first;
		}
		copy = copy->next_path;
	}
}

static bool sx_fifo(t_path *first, t_path *second, char **arr) {
	t_path *f = first;
	t_path *s = second;
	
	while (f && s) {
		if (sx_number(f->isl_name, s->isl_name, arr) > 0)
			return false;
		f = f->next_isl;
		s = s->next_isl;
	}
	return true;
}

static bool sx_gemini(t_path *first, t_path *second) {
	t_path *f_start = first;
	t_path *f_finish = first;
	t_path *s_start = second;
	t_path *s_finish = second;

	while (f_finish->next_isl != NULL)
		f_finish = f_finish->next_isl;
	while (s_finish->next_isl != NULL)
		s_finish = s_finish->next_isl;
	if (mx_strcmp(f_start->isl_name, s_start->isl_name) == 0
		&& mx_strcmp(f_finish->isl_name, s_finish->isl_name) == 0)
		return true;
	else
		return false;
}

static int sx_number(const char *s1, const char *s2, char **arr) {
	char **arr_p = arr;
	int uno = 0;
	int dos = 0;

	while (mx_strcmp(s1, *arr_p) != 0) {
		uno++;
		arr_p++;
	}
	arr_p = arr;
	while (mx_strcmp(s2, *arr_p) != 0) {
		dos++;
		arr_p++;
	}
	return (uno - dos);
}
