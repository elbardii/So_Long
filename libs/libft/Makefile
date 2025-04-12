# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: isel-bar <isel-bar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/11 06:47:00 by isel-bar          #+#    #+#              #
#    Updated: 2025/04/12 05:25:42 by isel-bar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_bzero.c \
       ft_calloc.c \
       ft_itoa.c \
       ft_memcpy.c \
       ft_memmove.c \
       ft_memset.c \
       ft_strdup.c \
       ft_strjoin.c \
       ft_strjoin_free.c \
       ft_strlcpy.c \
       ft_strlcat.c \
       ft_strlen.c

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

# Command aliases
RM = rm -rf
AR = ar -rcs

all: $(NAME)

# Create the static library from object files
$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re