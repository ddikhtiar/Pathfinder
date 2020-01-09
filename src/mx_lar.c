#include "pathfinder.h"

static bool sx_check_char(char c, int *minus, int *koma, int count);

bool mx_lar(char *sub) {
    int minus = 1;
    int koma = 1;
    int i = 0;
    int count = 0;

    while (sub[i] != '\n') {
        if ((sub[i] == '-' && sub[i + 1] == ',')
            || (sub[i] == ',' && sub[i + 1] == '\n'))
            return false;
        if (sx_check_char(sub[i], &minus, &koma, count)) {
            i++;
            count++;
        }
        else
            return false;
    }
    if (count == 0 || minus == 1 || koma == 1)
        return false;
    else
        return true;
}

static bool sx_check_char(char c, int *minus, int *koma, int count) {
    if (mx_isalpha(c) && *koma == 1)
        return true;
    else if (c == '-' && *minus == 1 && count != 0) {
        *minus = 0;
        return true;
    }
    else if (c == ',' && *koma == 1 && *minus == 0) {
        *koma = 0;
        return true;
    }
    else if (mx_isdigit(c) && *koma == 0)
        return true;
    return false;
}
