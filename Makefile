# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mburson <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/23 19:31:26 by mburson           #+#    #+#              #
#    Updated: 2017/02/23 19:31:28 by mburson          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

LIBFTPRINTF = ./src/ft_printf/libftprintf.a
LIBFTPRINTF_DIR = ./src/ft_printf

SRC = \
	$(addprefix ./src/, \
		free.c \
		graph_order_shim.c \
		helper.c \
		lem_in.c \
		move_ants.c \
		node_distances.c \
		verbose.c \
		$(addprefix build_graph/, \
			add_node_links.c \
			build_graph.c \
			get_raw_graph.c \
			validate_raw_graph.c \
		) \
	)

OBJ = $(SRC:.c=.o)

HEADERS = -I ./src -I $(LIBFTPRINTF_DIR) -I $(LIBFTPRINTF_DIR)/libft

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ) $(LIBFTPRINTF)
	gcc $(CFLAGS) -o $@ $^

%.o: %.c
	gcc $(CFLAGS) $(HEADERS) -c -o $@ $<

$(LIBFTPRINTF): force
	@echo "\e[1mbuilding libftprintf\e[0m"
	cd $(LIBFTPRINTF_DIR) && $(MAKE)

force:
	@true

clean:
	rm -f $(OBJ)
	cd ./$(LIBFTPRINTF_DIR) && $(MAKE) fclean
fclean: clean
	rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re
