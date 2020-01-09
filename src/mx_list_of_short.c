#include "pathfinder.h"

static int sum_minimal(t_list_p *list, char *s1, char *s);
static int sum_current(t_path **path); //Данная функция получает указатель
                                       //на текущий путь (его первый элемент),
                                       //вычисляет длину пути 
                                       //и переводит полученный указатель
                                       //в конец пути (на последний элемент))

void mx_list_of_short(t_list_p **shrt, t_list_p *list, t_data *data) {
    for (int i = 0; i < data->n_i; i++) {
        for (int j = i + 1; j < data->n_i; j++) {
            t_list_p *fl = list;
            int min = sum_minimal(list, data->AU[i], data->AU[j]);

            while (fl) {
                t_path *end = fl->link;
                int sum = sum_current(&end);

                if (mx_strcmp(fl->link->isl_name, data->AU[i]) == 0
                    && mx_strcmp(end->isl_name, data->AU[j]) == 0
                    && sum == min && mx_only_one(shrt, fl->link))
                    mx_push_path_back(shrt, mx_duplicate_path(fl->link));
                fl = fl->next_path;
            }
        }
    }
}

static int sum_minimal(t_list_p *list, char *s1, char *s2) {
    t_list_p *lp = list;   //Указатель на список путей
    t_path *last = NULL;   //Указатель на последний лист пути
    int sum = 0;           //Сумма длин всех ребер (полный путь)
    int min = 2147483647;  //Указатель на минимальную длину пути

    while (lp) {
        last = lp->link;
        sum = sum_current(&last);
        if (mx_strcmp(lp->link->isl_name, s1) == 0
            && mx_strcmp(last->isl_name, s2) == 0
            && sum < min)
            min = sum;
        lp = lp->next_path;
    }
    return min;
}

static int sum_current(t_path **path) {
    t_path *last = *path;
    int sum_current = 0;

    while (last->next_isl != NULL) {
    	last = last->next_isl;
    	sum_current += last->rebro;
    }
    *path = last;       //Переводим исходный указатель из начала в конец пути
    return sum_current; //Возвращаем длинну текущего пути
}
