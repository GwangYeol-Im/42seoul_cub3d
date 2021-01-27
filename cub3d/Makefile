# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gim <gim@student.42seoul.kr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/20 12:42:32 by imgwang-yeo       #+#    #+#              #
#    Updated: 2021/01/26 21:56:43 by gim              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror 
RM = rm -f
LIBS = -Lmlx -lmlx -framework OpenGL -framework AppKit -lm

MLX = libmlx.dylib

NAME = cub3D

SRCS = main.c game.c \
		config/config.c config/util.c config/parse_params.c \
		config/parse_texture.c config/map.c config/map_check.c \
		gnl/get_next_line.c \
		libft/ft_isalnum.c libft/ft_isalpha.c libft/ft_isascii.c \
		libft/ft_isdigit.c libft/ft_isprint.c libft/ft_tolower.c \
		libft/ft_toupper.c libft/ft_strlen.c libft/ft_strlcpy.c \
		libft/ft_strlcat.c libft/ft_memset.c libft/ft_memcpy.c \
		libft/ft_memccpy.c libft/ft_memcmp.c libft/ft_memchr.c \
		libft/ft_memmove.c libft/ft_bzero.c libft/ft_strchr.c \
		libft/ft_strrchr.c libft/ft_strnstr.c libft/ft_strcmp.c \
		libft/ft_atoi.c libft/ft_strdup.c libft/ft_calloc.c \
		libft/ft_substr.c libft/ft_strjoin.c libft/ft_strtrim.c \
		libft/ft_split.c libft/ft_itoa.c libft/ft_strmapi.c \
		libft/ft_putchar_fd.c libft/ft_putstr_fd.c libft/ft_putendl_fd.c \
		libft/ft_putnbr_fd.c libft/ft_lstadd_back.c libft/ft_lstadd_front.c \
		libft/ft_lstclear.c libft/ft_lstdelone.c libft/ft_lstiter.c \
		libft/ft_lstlast.c libft/ft_lstnew.c libft/ft_lstsize.c \
		libft/str.c

OBJS = $(SRCS:c=o)

all: $(NAME)

$(NAME): $(MLX) $(OBJS)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS)

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