#include "pathfinder.h"

static int arr_size(char **arr);
static void make_unique(char **unique, char **array, int size_u);

char **mx_unique(const char *str) {
    char **arr = mx_arr_islands(str);
    int size = arr_size(arr);
    char **uniq = NULL;

    uniq = (char **) malloc(sizeof(char *) * (size + 1));
    make_unique(uniq, arr, size);
    uniq[size] = NULL;
    mx_del_strarr(&arr);
    return uniq;
}

static void make_unique(char **unique, char **array, int size_u) {
    int shift = 0;

    for (int i = 0; i < size_u; i++) {
        for (int k = shift; array[k] != NULL;) {
            int off = 0;

            for (int j = k - 1; j >= 0 && off == 0; j--) {
                if (mx_strcmp(array[k], array[j]) == 0) {
                    k++;
                    off = 1;
                }
            }
            if (off == 0) {
                shift = k;
                break;
            }
        }
        unique[i] = mx_strdup(array[shift]);
        shift++;
    }
}

static int arr_size(char **arr) {
    int s = 0;

    for (; arr[s] != NULL; s++);
    for (int i = 0; arr[i] != NULL; i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (mx_strcmp(arr[i], arr[j]) == 0) {
                s--;
                break;
            }
        }
    }
    return s;
}
