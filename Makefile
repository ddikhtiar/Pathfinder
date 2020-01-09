NAME = pathfinder

INC = ./inc/pathfinder.h

HEAD = ./pathfinder.h

LIBMX = ./libmx/libmx.a

SRC = \
    ./main_pathfinder.c \
    ./mx_arr_islands.c \
    ./mx_arr_rebra.c \
    ./mx_atoi.c \
    ./mx_check_errors.c \
    ./mx_create_data.c \
    ./mx_create_island.c \
    ./mx_create_path.c \
    ./mx_del_intarr.c \
    ./mx_del_list.c \
    ./mx_del_path.c \
    ./mx_del_struct.c \
    ./mx_duplicate_path.c \
    ./mx_error_file.c \
    ./mx_error_line.c \
    ./mx_fl_valid.c \
    ./mx_isalpha.c \
    ./mx_isdigit.c \
    ./mx_islandsvalid.c \
    ./mx_lar.c \
    ./mx_last_punch.c \
    ./mx_linesvalid.c \
    ./mx_list_of_lists.c \
    ./mx_list_of_short.c \
    ./mx_list_sort.c \
    ./mx_matrix_incident.c \
    ./mx_mi_custom.c \
    ./mx_next_step.c \
    ./mx_num_islands.c \
    ./mx_num_rebers.c \
    ./mx_only_one.c \
    ./mx_plus_next_island.c \
    ./mx_print_paths.c \
    ./mx_printerr.c \
    ./mx_push_isl_back.c \
    ./mx_push_path_back.c \
    ./mx_unique.c \

SRCS = \
    ./src/main_pathfinder.c \
    ./src/mx_arr_islands.c \
    ./src/mx_arr_rebra.c \
    ./src/mx_atoi.c \
    ./src/mx_check_errors.c \
    ./src/mx_create_data.c \
    ./src/mx_create_island.c \
    ./src/mx_create_path.c \
    ./src/mx_del_intarr.c \
    ./src/mx_del_list.c \
    ./src/mx_del_path.c \
    ./src/mx_del_struct.c \
    ./src/mx_duplicate_path.c \
    ./src/mx_error_file.c \
    ./src/mx_error_line.c \
    ./src/mx_fl_valid.c \
    ./src/mx_isalpha.c \
    ./src/mx_isdigit.c \
    ./src/mx_islandsvalid.c \
    ./src/mx_lar.c \
    ./src/mx_last_punch.c \
    ./src/mx_linesvalid.c \
    ./src/mx_list_of_lists.c \
    ./src/mx_list_of_short.c \
    ./src/mx_list_sort.c \
    ./src/mx_matrix_incident.c \
    ./src/mx_mi_custom.c \
    ./src/mx_next_step.c \
    ./src/mx_num_islands.c \
    ./src/mx_num_rebers.c \
    ./src/mx_only_one.c \
    ./src/mx_plus_next_island.c \
    ./src/mx_print_paths.c \
    ./src/mx_printerr.c \
    ./src/mx_push_isl_back.c \
    ./src/mx_push_path_back.c \
    ./src/mx_unique.c \

OBJ = \
    ./main_pathfinder.o \
    ./mx_arr_islands.o \
    ./mx_arr_rebra.o \
    ./mx_atoi.o \
    ./mx_check_errors.o \
    ./mx_create_data.o \
    ./mx_create_island.o \
    ./mx_create_path.o \
    ./mx_del_intarr.o \
    ./mx_del_list.o \
    ./mx_del_path.o \
    ./mx_del_struct.o \
    ./mx_duplicate_path.o \
    ./mx_error_file.o \
    ./mx_error_line.o \
    ./mx_fl_valid.o \
    ./mx_isalpha.o \
    ./mx_isdigit.o \
    ./mx_islandsvalid.o \
    ./mx_lar.o \
    ./mx_last_punch.o \
    ./mx_linesvalid.o \
    ./mx_list_of_lists.o \
    ./mx_list_of_short.o \
    ./mx_list_sort.o \
    ./mx_matrix_incident.o \
    ./mx_mi_custom.o \
    ./mx_next_step.o \
    ./mx_num_islands.o \
    ./mx_num_rebers.o \
    ./mx_only_one.o \
    ./mx_plus_next_island.o \
    ./mx_print_paths.o \
    ./mx_printerr.o \
    ./mx_push_isl_back.o \
    ./mx_push_path_back.o \
    ./mx_unique.o \

OBJO = \
    ./obj/main_pathfinder.o \
    ./obj/mx_arr_islands.o \
    ./obj/mx_arr_rebra.o \
    ./obj/mx_atoi.o \
    ./obj/mx_check_errors.o \
    ./obj/mx_create_data.o \
    ./obj/mx_create_island.o \
    ./obj/mx_create_path.o \
    ./obj/mx_del_intarr.o \
    ./obj/mx_del_list.o \
    ./obj/mx_del_path.o \
    ./obj/mx_del_struct.o \
    ./obj/mx_duplicate_path.o \
    ./obj/mx_error_file.o \
    ./obj/mx_error_line.o \
    ./obj/mx_fl_valid.o \
    ./obj/mx_isalpha.o \
    ./obj/mx_isdigit.o \
    ./obj/mx_islandsvalid.o \
    ./obj/mx_lar.o \
    ./obj/mx_last_punch.o \
    ./obj/mx_linesvalid.o \
    ./obj/mx_list_of_lists.o \
    ./obj/mx_list_of_short.o \
    ./obj/mx_list_sort.o \
    ./obj/mx_matrix_incident.o \
    ./obj/mx_mi_custom.o \
    ./obj/mx_next_step.o \
    ./obj/mx_num_islands.o \
    ./obj/mx_num_rebers.o \
    ./obj/mx_only_one.o \
    ./obj/mx_plus_next_island.o \
    ./obj/mx_print_paths.o \
    ./obj/mx_printerr.o \
    ./obj/mx_push_isl_back.o \
    ./obj/mx_push_path_back.o \
    ./obj/mx_unique.o \

CFLGS = -std=c11 -Wall -Werror -Wextra -Wpedantic

all: install

install:
	@make -C libmx
	@cp $(SRCS) $(INC) .
	@clang $(CFLGS) -c $(SRC) -I $(HEAD)
	@clang $(CFLGS) $(LIBMX) $(OBJ) -o $(NAME)
	@mkdir -p obj
	@mv $(OBJ) ./obj
	@rm -rf $(SRC) $(HEAD)

uninstall:
	@make uninstall -C libmx
	@rm -rf $(OBJ) $(OBJO) $(SRC) $(HEAD)
	@rm -rf	./obj
	@rm -rf $(NAME)

clean:
	@make uninstall -C libmx
	@rm -rf $(OBJ) $(OBJO) $(SRC) $(HEAD)
	@rm -rf ./obj

reinstall: uninstall install

