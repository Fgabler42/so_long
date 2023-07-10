NAME := libs

#--------------------------- gnl ---------------------------------------#

GNLSRCS = ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c

#--------------------------------------------------------------------------#

MAKE_LIBFT = cd libft && make

all: $(NAME)

$(NAME):
	@$(MAKE) -C ./ft_printf
	@$(MAKE) -C ./libft

clean:
	@$(MAKE) -C ./libft clean
	@$(MAKE) -C ./ft_printf clean

fclean: clean
	@$(MAKE) -C ./ft_printf fclean
	@$(MAKE) -C ./libft fclean
