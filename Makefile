COMPILER = gcc
CHECK_FLAGS = -Wall -Wextra -Werror
NAME = lem-in
ADD_SRC = ./src/
RESOURCES = check_profit.c creations.c dijkstra.c enlarge_table.c find_node.c free_memory.c free_memory2.c ft_add_path.c ft_nullify.c get_optimal_flow.c insert_node.c let_the_flow_go.c main.c options_parser.c parse.c read_links.c reading_data.c recover_path.c safe_creations.c bin_heap.c sort_flow.c
SRC_S = $(addprefix $(ADD_SRC), $(RESOURCES))
OBJ = $(SRC_S:.c=.o)
ADD_INC = ./includes/
ADD_LIB_H = ./libft/
ADD_LIBFT = ./libft/libft.a

all: $(NAME)

$(NAME):  $(OBJ)
	@make  -C ./libft all
	@$(COMPILER) -o $(NAME) $(CHECK_FLAGS) $(COMPILE_FLAGS) $(OBJ) $(ADD_LIBFT)
	@echo ======[Done]======
%.o : %.c
	@echo "$(NAME) >>> Add/Update $<"
	@$(COMPILER) -c -o $@ -I $(ADD_INC) -I ./libft/includes $(CHECK_FLAGS) $<
clean:
	@rm -f $(ADD_SRC)*.o
	@make  -C ./libft clean
fclean: clean
	@rm -f ./$(NAME)
	@make -C ./libft fclean
re: fclean all
