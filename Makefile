# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/07 14:50:03 by fgabler           #+#    #+#              #
#    Updated: 2023/07/15 07:30:42 by fgabler          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := so_long
CFLAGS = -Wall -Wextra -Werror
CC = cc
MLXFLAGS = -framework Cocoa -framework OpenGL -framework IOKit -Iinclude -lglfw -L"/opt/homebrew/Cellar/glfw/3.3.8/lib/"

SRC = so_long.c

OBJS = $(SRCS:.c=.o)

all: MLX42 $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) -C ./libs
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) ./libs/libs.a ./MLX42/build/libmlx42.a $(MLXFLAGS)

MLX42:
	@if [ ! -d "MLX42" ]; then git clone https://github.com/codam-coding-college/MLX42.git; fi
	@cd MLX42 && cmake -B build && cmake --build build -j4

clean:
	@rm -rf MLX42
	@cd libs && make fclean
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all
