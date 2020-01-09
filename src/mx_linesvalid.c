#include "pathfinder.h"

int mx_linesvalid(const char *str) {
    int line_num = 2;
    char *sub = (char *) str;

    for (;*sub != '\n'; sub++);
    sub++;
    while (*sub) {
        if (mx_lar(sub)) {
            for (;*sub != '\n'; sub++);
            line_num++;
            sub++;
        }
        else
            return line_num;
    }
    return 0;
}
