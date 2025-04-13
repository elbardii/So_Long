NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror -Iinclude -I$(HOME)/local/include -Ilibs/libft -Ilibs/get_next_line

SRC_DIR = src
OBJ_DIR = obj

SRC_FILES = main.c map.c validate_map.c flood_fill.c freedom.c render.c player_movement.c ft_printf.c name_check.c
GNL_FILES = get_next_line.c get_next_line_utils.c

SRCS = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
GNL_SRCS = $(addprefix libs/get_next_line/, $(GNL_FILES))
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
GNL_OBJS = $(GNL_SRCS:libs/get_next_line/%.c=$(OBJ_DIR)/gnl/%.o)

MLX_DIR = $(HOME)/local/lib
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11

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