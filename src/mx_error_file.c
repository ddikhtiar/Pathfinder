#include "pathfinder.h"

void mx_error_file(char *problem, const char *filename) {
    mx_printerr("error: file ");
    mx_printerr(filename);
    if (mx_strcmp(problem, "open") == 0)
        mx_printerr(" does not exist\n");
    else
        mx_printerr(" is empty\n");
}
