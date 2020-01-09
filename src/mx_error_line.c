#include "pathfinder.h"

void mx_error_line(int line_number) {
    char *num = mx_itoa(line_number);

    mx_printerr("error: line ");
    mx_printerr(num);
    mx_printerr(" is not valid\n");
}
