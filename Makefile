# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: isel-bar <isel-bar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/10 12:00:00 by ismail            #+#    #+#              #
#    Updated: 2025/04/11 06:46:07 by isel-bar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program name
NAME = so_long

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Directories
SRC_DIR = srcs
INCLUDES = -Iincludes -I/usr/include -Ilibs/libft
OBJ_DIR = objs

# MinilibX
MLX_PATH = minilibx-linux
MLX_LIB = $(MLX_PATH)/libmlx.a
MLX_FLAGS = -L$(MLX_PATH) -lmlx -lXext -lX11 -lm

# ft_printf
PRINTF_PATH = libs/ft_printf
PRINTF_LIB = $(PRINTF_PATH)/libftprintf.a

# libft
LIBFT_PATH = libs/libft
LIBFT_LIB = $(LIBFT_PATH)/libft.a

# Source files
SRC_FILES = $(SRC_DIR)/main.c \
			$(wildcard $(SRC_DIR)/init/*.c) \
			$(wildcard $(SRC_DIR)/parsing/*.c) \
			$(wildcard $(SRC_DIR)/game/*.c) \
			$(wildcard $(SRC_DIR)/render/*.c) \
			$(wildcard $(SRC_DIR)/utils/*.c)

# Object files
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES))

# Colors
GREEN = \033[0;32m
YELLOW = \033[0;33m
RESET = \033[0m

# Rules
all: $(NAME)

# Create directories if they don't exist
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@echo "$(GREEN)Compiling:$(RESET) $<"

# Install and compile MinilibX if needed
$(MLX_LIB):
	@echo "$(YELLOW)Building MinilibX...$(RESET)"
	@make -C $(MLX_PATH)

# Compile ft_printf
$(PRINTF_LIB):
	@echo "$(YELLOW)Building ft_printf...$(RESET)"
	@make -C $(PRINTF_PATH)
	
# Compile libft
$(LIBFT_LIB):
	@echo "$(YELLOW)Building libft...$(RESET)"
	@make -C $(LIBFT_PATH)

# Link the program
$(NAME): $(MLX_LIB) $(PRINTF_LIB) $(LIBFT_LIB) $(OBJ_FILES)
	@$(CC) $(OBJ_FILES) $(MLX_FLAGS) -L$(PRINTF_PATH) -lftprintf -L$(LIBFT_PATH) -lft -o $(NAME)
	@echo "$(GREEN)$(NAME) successfully compiled!$(RESET)"

clean:
	@rm -rf $(OBJ_DIR)
	@make -C $(PRINTF_PATH) clean
	@make -C $(LIBFT_PATH) clean
	@echo "$(YELLOW)Object files removed.$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@make -C $(PRINTF_PATH) fclean
	@make -C $(LIBFT_PATH) fclean
	@echo "$(YELLOW)$(NAME) removed.$(RESET)"

re: fclean all

.PHONY: all clean fclean re