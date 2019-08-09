cmake_minimum_required(VERSION 3.13)

project(lem_in)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "-Wall -Wextra")

FILE(GLOB ft_printf ./libft/ft_printf/*.c)
FILE(GLOB str_func ./libft/str_funcs/*.c)
FILE(GLOB digit_func ./libft/digit_funcs/*.c)
FILE(GLOB char_func ./libft/char_funcs/*.c)
FILE(GLOB useful_func ./libft/useful_funcs/*.c)
FILE(GLOB lst_func ./libft/lst_funcs/*.c)
FILE(GLOB int_vec_func ./libft/vec_funcs/int_vec/*.c)
FILE(GLOB ptr_vec_func ./libft/vec_funcs/ptr_vec/*.c)
FILE(GLOB memes_func ./libft/mem_funcs/*.c)
FILE(GLOB char_vec ./libft/vec_funcs/char_vec/*.c)
FILE(GLOB hashtable ./libft/hashtable/*.c)

include_directories( ./libft/includes)

add_executable(lem_in  main.c parse.c ${useful_func} ${ptr_vec_func} ${int_vec_func} ${str_func} ${hashtable} ${lst_func} dinic.c flow.c let_the_flow_go.c insert_node.c enlarge_table.c find_node.c reading_data.c delete_hashtable.c)

target_link_libraries(lem_in ~/lem_in/libft/libft.a)
