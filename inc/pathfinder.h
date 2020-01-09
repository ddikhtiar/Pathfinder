#ifndef PATHFINDER_H
#define PATHFINDER_H

#include "libmx/inc/libmx.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <wchar.h>
#include <fcntl.h>

#define ERR_USAGE "usage: ./pathfinder [filename]\n"

//Функции для проверки входящих данных

bool mx_check_errors(const char *string, const char *filename);
void mx_error_file(char *problem, const char *filename);
void mx_error_line(int line_number);
bool mx_fl_valid(const char *str);
bool mx_isalpha(char c);
bool mx_isdigit(char c);
bool mx_islandsvalid(const char *str);
bool mx_lar(char *sub);
int mx_linesvalid(const char *str);
void mx_printerr(const char *s);

//Функции для создания структуры исходных данных под алгоритм

char **mx_arr_islands(const char *str);
char **mx_unique(const char *str);
int mx_atoi(const char *s);
char **mx_arr_rebra(const char *str);
int **mx_matrix_incident(const char *str);
void mx_del_intarr(int ***arr_int, int n_i);
int mx_num_islands(const char *str);
int mx_num_rebers(const char *str);
void mx_mi_custom(int **matrix, const char *str, int n_i, int n_r);

typedef struct s_data {
    int **MI;           //Указатель на матрицу инцидентности
    char **AU;          //Указатель на массив уникальных островов
    int n_i;            //Количество уникальных отстровов
    int n_r;            //Количество ребер
} t_data;

//Функции для построения списка путей

typedef struct s_path {         //Лист струкруты пути
    int rebro;                  //Длинна дороги до предыдущего острова
    char *isl_name;             //Название текущего острова
    struct s_path *next_isl;    //Ссылка на следующий отсров
} t_path;

typedef struct s_list_p {       //Лист структуры списка путей
    struct s_path *link;        //Путь
    struct s_list_p *next_path; //Ссылка на следующий лист
} t_list_p;

t_data *mx_create_data(const char *str);
t_path *mx_create_island(char *isl, int reb);
t_list_p *mx_create_path(t_path *road);
void mx_push_isl_back(t_path **path, char *isl, int reb);
void mx_push_path_back(t_list_p **list_path, t_path *road);
bool mx_next_step(t_path *path, const char *str);
t_path *mx_duplicate_path(t_path *path);
t_list_p *mx_list_of_lists(t_data *D);
void mx_plus_next_island(t_data *data, t_list_p *list, int y);
void mx_print_paths(t_list_p *list);
void mx_del_struct(t_data **data);
void mx_last_punch(const char *str);
void mx_list_of_short(t_list_p **shrt, t_list_p *list, t_data *data);
bool mx_only_one(t_list_p **list, t_path *path);
void mx_del_path(t_path **path);
void mx_del_list(t_list_p **list);
void mx_list_sort(t_list_p *list, char **arr_isl);

#endif
