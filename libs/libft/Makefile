# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: isel-bar <isel-bar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/17 02:58:04 by isel-bar          #+#    #+#              #
#    Updated: 2024/11/17 03:43:54 by isel-bar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

      SOURCES = ft_isalpha.c             \
                ft_isdigit.c             \
                ft_isalnum.c             \
                ft_isascii.c             \
                ft_isprint.c             \
                ft_strlen.c              \
                ft_memset.c              \
                ft_bzero.c               \
                ft_memcpy.c              \
                ft_memmove.c             \
                ft_strlcpy.c             \
                ft_strlcat.c             \
                ft_toupper.c             \
                ft_tolower.c             \
                ft_strchr.c              \
                ft_strrchr.c             \
                ft_strncmp.c             \
                ft_memchr.c              \
                ft_memcmp.c              \
                ft_strnstr.c             \
                ft_atoi.c                \
                ft_calloc.c              \
                ft_strdup.c              \
                ft_substr.c              \
                ft_strjoin.c             \
                ft_strtrim.c             \
                ft_split.c               \
                ft_itoa.c                \
                ft_strmapi.c             \
                ft_striteri.c            \
                ft_putchar_fd.c          \
                ft_putstr_fd.c           \
                ft_putendl_fd.c          \
                ft_putnbr_fd.c
OBJS := $(SOURCES:.c=.o)

NAME = libft.a 

CC = cc

CFLAGS = -Wall -Wextra -Werror 

RM = rm -fr

ARCHNAME = ar rcs $(NAME)

all: $(NAME)

$(NAME): $(OBJS)
	$(ARCHNAME)	$(OBJS) 

%.o: %.c libft.h
	$(CC)	$(CFLAGS) -c $< -o $@

clean:
	$(RM)	$(OBJS)

fclean: clean
	$(RM)	$(NAME)

re: fclean all

.PHONY: all clean fclean re 