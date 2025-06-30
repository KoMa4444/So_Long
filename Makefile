NAME		=	so_long

CC			=	cc
C_FLAGS	=	-Wall -Wextra -Werror -g

SRC			=	src/main.c src/error_management.c src/map_parse/map_validate.c \
					src/map_parse/matrix_management.c src/display/display_from_matrix.c \
					src/map_parse/map_checking.c

OBJ			=	$(SRC:.c=.o)
HEADER	=	-Iinc

LIBFT		=	lib/libft
MLX42		= ./lib/MLX42

LIBS		=	-L$(LIBFT) -lft -L$(MLX42) -lmlx42 -lglfw -lm

all: ${NAME}

%.o: %.c
	$(CC) ${C_FLAGS} $(HEADER) -c $< -o $@

libft:
	@make -C $(LIBFT)
	@echo "\033[33mLIBLIBFT COMPILED SUCCESSFULY!! ;)"

mlx:
	@cmake -S $(MLX42) -B $(MLX42)
	@make -C $(MLX42)
	@echo "\033[33mMLX42 COMPILED SUCCESSFULLY!! ;)"

${NAME}: libft mlx ${OBJ}
	$(CC) ${C_FLAGS} $(OBJ) $(LIBS) -o $(NAME)

clean:
	@rm -f $(OBJ)
	@make clean -C $(LIBFT)
	@make clean -C $(MLX42)
	@echo "\033[31mObject files removed!! ;)"

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT)
	@echo "\033[31mExecutable removed!! ;)"

re: fclean all

display_test: libft mlx
	$(CC) $(C_FLAGS) display_testing.c $(LIBS) -o display_testing


test: all
	./$(NAME) maps/base_map.ber