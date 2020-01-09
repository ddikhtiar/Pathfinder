#include "pathfinder.h"

bool mx_next_step(t_path *path, const char *island) {
    t_path *ptr = path;

    if (ptr == NULL)
        return true;
    while (ptr) {
        if (mx_strcmp(ptr->isl_name, island) == 0)
            return false;    //Возвращаем false, если остров уже есть в пути
        ptr = ptr->next_isl;
    }
    return true;			 //Возвращаем true, если острова нет в пути
}
