
NAME = fdf

FILES = main.c file_save_check.c helpers.c red_blob.c xs_and_ys.c draw.c math.c

OFILES = $(FILES:.c=.o)

FLAGS = -Wall -Werror -Wextra

LIBS = -L ../libft -l ft -L ../minilibx -l mlx -L /usr/X11/lib -l X11 -l Xext

.PHONY: all libft minilibx clean fclean re

all: $(NAME)

$(NAME): $(OFILES) libft minilibx
	gcc -o $(NAME) $(OFILES) $(LIBS)

$(OFILES):
	gcc $(FLAGS) -c $(FILES)

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
	make all
