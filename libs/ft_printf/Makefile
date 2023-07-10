# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgabler <fgabler@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/12 08:39:49 by fritzgabler       #+#    #+#              #
#    Updated: 2023/07/05 09:33:27 by fgabler          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := ft_printf.a
CFLAGS ?= -Wall -Wextra -Werror

SRCS := ft_print_hex.c ft_print_num.c ft_print_ptr.c \
ft_print_uns.c ft_printf.c put_char_mod.c ft_print_str.c

OBJS := $(SRCS:.c=.o)
RM   := rm -rf

all:		$(NAME)

$(NAME):	$(OBJS)
		@ar rcs $@ $^

clean:
	@$(RM) $(OBJS)

fclean:	clean
	@$(RM) $(NAME) $(OBJS)

re:			fclean $(NAME)

