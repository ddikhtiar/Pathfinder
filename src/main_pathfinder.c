#include "pathfinder.h"

int main (int argc, char *argv[]) {
    char *file_data_str = NULL;

    if (argc != 2) {
        mx_printerr(ERR_USAGE);
        exit(0);
    }
    file_data_str = mx_file_to_str(argv[1]);
    if (!mx_check_errors(file_data_str, argv[1]))
        exit(1);
    else
        mx_last_punch(file_data_str);
//  system("leaks pathfinder");
    exit(0);
}
