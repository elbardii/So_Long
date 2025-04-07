NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -Lmlx -lmlx -lXext -lX11

SRC = src/main.c \
      src/game.c \
      src/map_parser.c \
      src/mlx_utils.c \
      src/utils.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(MLX_FLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

test: all
	./$(NAME) maps/test1.ber
	./$(NAME) maps/test2.ber

.PHONY: all clean fclean re test 