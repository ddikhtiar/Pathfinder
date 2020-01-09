#include "pathfinder.h"

static char *first_line_str(const char *string);

bool mx_islandsvalid(const char *str) {
    char **isl_arr = mx_unique(str);
    char *first_str = first_line_str(str);
    int isl_fl = 0;
    int isl_fact = 0;

    isl_fl = mx_atoi(first_str);                  // Заявленное кол-во ост-в
    mx_strdel(&first_str);
    for (; isl_arr[isl_fact] != NULL; isl_fact++);// Фактическое кол-во ост-в
    mx_del_strarr(&isl_arr);
    if (isl_fact == isl_fl)
        return true;
    else {
        mx_printerr("error: invalid number of islands\n");
        return false;
    }
}

static char *first_line_str(const char *string) {
    int len = 0;
    char *fls = NULL;

    for (; string[len] != '\n'; len++);
    fls = mx_strndup(string, len);
    return fls;
}
