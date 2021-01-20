# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: imgwang-yeol <imgwang-yeol@student.42.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/20 12:42:32 by imgwang-yeo       #+#    #+#              #
#    Updated: 2021/01/20 13:23:21 by imgwang-yeo      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror 
RM = rm -f
LIBS = -Lmlx -lmlx -framework OpenGL -framework AppKit -lm

MLX = libmlx.dylib

NAME = cub3D

SRCS = main.c \
		gnl/get_next_line.c \
		libft/ft_isalnum.c libft/ft_isalpha.c libft/ft_isascii.c \
		libft/ft_isdigit.c libft/ft_isprint.c libft/ft_tolower.c \
		libft/ft_toupper.c libft/ft_strlen.c libft/ft_strlcpy.c \
		libft/ft_strlcat.c libft/ft_memset.c libft/ft_memcpy.c \
		libft/ft_memccpy.c libft/ft_memcmp.c libft/ft_memchr.c \
		libft/ft_memmove.c libft/ft_bzero.c libft/ft_strchr.c \
		libft/ft_strrchr.c libft/ft_strnstr.c libft/ft_strncmp.c \
		libft/ft_atoi.c libft/ft_strdup.c libft/ft_calloc.c \
		libft/ft_substr.c libft/ft_strjoin.c libft/ft_strtrim.c \
		libft/ft_split.c libft/ft_itoa.c libft/ft_strmapi.c \
		libft/ft_putchar_fd.c libft/ft_putstr_fd.c libft/ft_putendl_fd.c \
		libft/ft_putnbr_fd.c

OBJS = $(SRCS:c=o)

all: $(NAME)

$(NAME): $(MLX) $(OBJS)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS)

test:
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS)
		./$(NAME)

$(MLX):
		make -C mlx
		cp mlx/$(MLX) .

clean:
		make -C mlx clean
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME) $(MLX)

re: fclean $(NAME)

.PHONY: all clean fclean re