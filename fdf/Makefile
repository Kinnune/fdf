#fdf makefile ekinnune
NAME = fdf

CC = gcc

CFLAGS = -c -Wall -Werror -Wextra

FILES = main.c file_save_check.c helpers.c red_blob.c xs_and_ys.c draw.c math_and_hud.c

OFILES = $(FILES:.c=.o)

LIBS = -L ../libft -l ft -L ../minilibx -l mlx -L /usr/X11/lib -l X11 -l Xext

.PHONY: all libft minilibx clean fclean re

all: $(NAME)

$(NAME): $(FILES)
	make $(OFILES)
	make libft
	make minilibx
	$(CC) -o $(NAME) $(OFILES) $(LIBS)

$(OFILES): $(FILES)
	$(CC) $(CFLAGS) $(FILES)

libft:
	make -C ../libft

minilibx:
	make -C ../minilibx

clean:
	rm -fr $(OFILES)
	make clean -C ../libft

fclean: clean
	make clean -C ../minilibx
	rm -fr $(NAME)

re: fclean
	make
