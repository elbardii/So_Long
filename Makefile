NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror -Iinclude -I/usr/include/minilibx-linux -Ilibs/libft -Ilibs/get_next_line

SRC_DIR = src
OBJ_DIR = obj

SRC_FILES = main.c map.c validate_map.c flood_fill.c freedom.c render.c player_movement.c ft_printf.c name_check.c
GNL_FILES = get_next_line.c get_next_line_utils.c

SRCS = $(SRC_DIR)/main.c $(SRC_DIR)/map.c $(SRC_DIR)/validate_map.c $(SRC_DIR)/flood_fill.c \
       $(SRC_DIR)/freedom.c $(SRC_DIR)/render.c $(SRC_DIR)/player_movement.c \
       $(SRC_DIR)/ft_printf.c $(SRC_DIR)/name_check.c
GNL_SRCS = libs/get_next_line/get_next_line.c libs/get_next_line/get_next_line_utils.c
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
GNL_OBJS = $(GNL_SRCS:libs/get_next_line/%.c=$(OBJ_DIR)/gnl/%.o)

MLX_DIR = /usr/include/minilibx-linux
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

LIBFT_DIR = libs/libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)
	mkdir -p $(OBJ_DIR)/gnl

$(NAME): $(OBJS) $(GNL_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(GNL_OBJS) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/gnl/%.o: libs/get_next_line/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	rm -rf $(OBJ_DIR)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re