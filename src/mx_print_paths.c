#include "pathfinder.h"

static void print_path(t_path *path);
static void print_route(t_path *path);
static void print_distance(t_path *path);

void mx_print_paths(t_list_p *list) {
    t_list_p *lst = list;
	
    while (lst) {
        for (int i = 1; i <= 40; i++) {
            mx_printchar('=');
        }
        print_path(lst->link);
        print_route(lst->link);
        print_distance(lst->link);
        mx_printchar('\n');
        for (int i = 1; i <= 40; i++) {
            mx_printchar('=');
        }
        mx_printchar('\n');
        lst = lst->next_path;
    }
}

static void print_path(t_path *path) {
    t_path *p = path;

    mx_printstr("\nPath: ");
    mx_printstr(p->isl_name);
    mx_printstr(" -> ");
    while (p->next_isl != NULL) {
        p = p->next_isl;
    }
    mx_printstr(p->isl_name);
}

static void print_route(t_path *path) {
    t_path *p = path;

    mx_printstr("\nRoute: ");
    while (p) {
        mx_printstr(p->isl_name);
        if (p->next_isl != NULL)
            mx_printstr(" -> ");
        p = p->next_isl;
    }
}

static void print_distance(t_path *path) {
    int sum = 0;
    t_path *p = path;

    mx_printstr("\nDistance: ");
    if (p->next_isl->next_isl == NULL)
        mx_printint(p->next_isl->rebro);
    else {
        p = p->next_isl;
        while (p) {
            mx_printint(p->rebro);
            sum += p->rebro;
            if (p->next_isl != NULL)
                mx_printstr(" + ");
            else {
                mx_printstr(" = ");
                mx_printint(sum);
            }
            p = p->next_isl;
        }
    }
}
