NAME = libftprintf.a

SRCS = \
	conv.c \
	format.c \
	format_cont.c \
	ft_printf.c \
	inference.c \
	$(addprefix parse/,\
		parse.c \
		parse_char.c \
		parse_char_wide.c \
		parse_int.c \
		parse_ptr.c \
		parse_str.c \
		parse_str_wide.c \
	) \

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra
ifndef WNOERROR
	CFLAGS += -Werror
endif

all: $(NAME)

$(NAME): $(OBJS) ./libft/libft.a
	cp ./libft/libft.a $@
	ar -rc $@ $(OBJS)
	ranlib $@

%.o: %.c
	gcc $(CFLAGS) -c -I . -I ./libft -o $@ $<

./libft/libft.a: force
	cd libft && $(MAKE)

force:
	@true

clean:
	rm -f $(OBJS)
	cd libft && $(MAKE) fclean
fclean: clean
	rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re
