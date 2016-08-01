NAME =	libft.a
CC =	gcc
FLAGS =	-Wall -Wextra -Werror
SRC =		ft_atoi.c			ft_bzero.c			ft_isalnum.c	\
			ft_isalpha.c		ft_isascii.c		ft_isdigit.c	\
			ft_isprint.c		ft_itoa.c			ft_lstadd.c		\
			ft_lstdel.c			ft_lstdelone.c		ft_lstiter.c	\
			ft_lstmap.c			ft_lstnew.c			ft_memalloc.c	\
			ft_memccpy.c		ft_memchr.c			ft_memcmp.c		\
			ft_memcpy.c			ft_memdel.c			ft_memmove.c	\
			ft_memset.c			ft_putchar.c		ft_putchar_fd.c	\
			ft_putendl.c		ft_putendl_fd.c		ft_putnbr.c		\
			ft_putnbr_fd.c		ft_putstr.c			ft_putstr_fd.c	\
			ft_realloc.c		ft_strcat.c			ft_strchr.c		\
			ft_strclr.c			ft_strcmp.c			ft_strcpy.c		\
			ft_strdel.c			ft_strdup.c			ft_strequ.c		\
			ft_striter.c		ft_striteri.c		ft_strjoin.c	\
			ft_strlcat.c		ft_strlen.c			ft_strmap.c		\
			ft_strmapi.c		ft_strncat.c		ft_strncmp.c	\
			ft_strncpy.c		ft_strnequ.c		ft_strnew.c		\
			ft_strnstr.c		ft_strrchr.c		ft_strsplit.c	\
			ft_strstr.c			ft_strsub.c			ft_strtrim.c	\
			ft_tolower.c		ft_toupper.c		ft_arealpha.c	\
			ft_aredigit.c		ft_create_tab.c		ft_expand_tab.c	\
			ft_print_tab.c		ft_freetab.c		ft_find_diff.c	\
			ft_rootnb.c			get_next_line.c		ft_nblen.c		\
			ft_long_putnbr.c	ft_strndup.c		ft_put_color.c	\
			ft_abs.c			ft_cp_tab.c			ft_tblen.c		\
			ft_strclean.c		ft_strnchr.c		ft_delline.c	\
			ft_pow.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)
%.o: %.c
	$(CC) -o $@ -c $< $(FLAGS)
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(OBJ) $(NAME)

re: fclean all
