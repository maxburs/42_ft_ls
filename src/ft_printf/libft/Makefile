NAME = libft.a

SRC_BOOL = \
	ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_isprint.c \

SRC_CONVERT = \
	ft_absolute.c \
	ft_atoi.c \
	ft_itoa.c \
	ft_itoa_base.c \
	ft_tolower.c \
	ft_toupper.c \
	ft_utf_16_32.c \
	ft_utf_16_8.c \
	ft_utf_32_8.c \

SRC_LIST =  \
	lstadd.c \
	lstdel.c \
	lstdelone.c \
	lstiter.c \
	lstmap.c \
	lstnew.c \
	lstprint.c \
	lstpush.c \
	lstreverse.c \
	lstsort.c \

SRC_LSTR = \
	lstr_add.c \
	lstr_finish.c \
	lstr_new.c \
	lstr_print.c \

SRC_MEMORY = \
	ft_bzero.c \
	ft_memalloc.c \
	ft_memccpy.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_memcpy.c \
	ft_memdel.c \
	ft_memdup.c \
	ft_memmove.c \
	ft_memset.c \

SRC_OTHER = \
	ft_numlen.c \
	ft_numlen_un.c \

SRC_PUT = \
	ft_putchar.c \
	ft_putchar_fd.c \
	ft_putendl.c \
	ft_putendl_fd.c \
	ft_putnbr.c \
	ft_putnbr_fd.c \
	ft_putstr.c \
	ft_putstr_fd.c \
	ft_putstrw.c \

SRC_STRING = \
	ft_strcat.c \
	ft_strchr.c \
	ft_strchri.c \
	ft_strclr.c \
	ft_strcmp.c \
	ft_strcpy.c \
	ft_strdel.c \
	ft_strdup.c \
	ft_striter.c \
	ft_striteri.c \
	ft_strjoin.c \
	ft_strlcat.c \
	ft_strlen.c \
	ft_strlenw.c \
	ft_strmap.c \
	ft_strmapi.c \
	ft_strncat.c \
	ft_strnchr.c \
	ft_strncmp.c \
	ft_strncpy.c \
	ft_strndup.c \
	ft_strnew.c \
	ft_strnstr.c \
	ft_strplace.c \
	ft_strrchr.c \
	ft_strsplit.c \
	ft_strstr.c \
	ft_strsub.c \
	ft_strtrim.c \
	ft_wrdcnt.c \

SRC = \
	$(addprefix ./bool/,$(SRC_BOOL)) \
	$(addprefix ./convert/,$(SRC_CONVERT)) \
	$(addprefix ./list/,$(SRC_LIST)) \
	$(addprefix ./listm/,$(SRC_LISTM)) \
	$(addprefix ./lstr/,$(SRC_LSTR)) \
	$(addprefix ./memory/,$(SRC_MEMORY)) \
	$(addprefix ./other/,$(SRC_OTHER)) \
	$(addprefix ./put/,$(SRC_PUT)) \
	$(addprefix ./string/,$(SRC_STRING)) \

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $@ $^
	ranlib $@

%.o: %.c
	gcc $(CFLAGS) -I . -c -o $@ $<

clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re
