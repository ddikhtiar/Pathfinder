#include "pathfinder.h"

bool mx_check_errors(const char *string, const char *filename) {
    if (string == NULL) {
        mx_error_file("open", filename);
        return false;
    }
    if (string[0] == '\0') {
        mx_error_file("empty", filename);
        return false;
    }
    else if (!mx_fl_valid(string))
        return false;
    else if (mx_linesvalid(string) != 0) {
        mx_error_line(mx_linesvalid(string));
        return false;
    }
    if (!mx_islandsvalid(string))
        return false;
    return true;
}
