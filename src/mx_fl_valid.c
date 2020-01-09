#include "pathfinder.h"

bool mx_fl_valid(const char *str) {

    if (str[0] == '\n') {
        mx_printerr("error: line 1 is not valid\n");
        return false;
    }
    for (int i = 0; str[i] != '\n'; i++) {
        if (!mx_isdigit(str[i])) {
            mx_printerr("error: line 1 is not valid\n");
            return false;
        }
    }
    return true;
}
