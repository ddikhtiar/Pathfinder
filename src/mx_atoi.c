#include "pathfinder.h"

int mx_atoi(const char *s) {
    int integer = 0;
    int minus = 1;
    int dec = 0;
    const char *p = s;

    if (p[0] == '-') {
        minus = -1;
        p++;
    }
    while (*p) {
        if (!mx_isdigit(*p))
            return 0;
        dec = *p - 48;
        integer = integer * 10 + dec;
        p++;
    }
    integer *= minus;
    return integer;
}
