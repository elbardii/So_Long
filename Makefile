NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror -Iinclude -I$(HOME)/local/include -Ilibs/libft -Ilibs/get_next_line

SRCS = src/main.c src/map.c src/validate_map.c src/flood_fill.c src/freedom.c src/render.c src/player_movement.c src/ft_printf.c \
		src/name_check.c \
		libs/get_next_line/get_next_line.c libs/get_next_line/get_next_line_utils.c
OBJS = $(SRCS:.c=.o)

MLX_DIR = $(HOME)/local/lib
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11

LIBFT_DIR = libs/libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	rm -f $(OBJS)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re