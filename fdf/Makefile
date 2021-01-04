
NAME = fdf

FILES = main.c file_save_check.c helpers.c red_blob.c xs_and_ys.c \
		draw.c hud.c

OFILES = $(FILES:.c=.o)

FLAGS = -Wall -Werror -Wextra -o

LIBS = ../libft/libft.a libmlx.dylib

$(NAME): all

all:
	make -C ../libft
	make -C ../minilibx_mms_20191025_beta
	mv ../minilibx_mms_20191025_beta/libmlx.dylib .
	gcc $(FLAGS) $(NAME) $(FILES) $(LIBS)

relink:
	gcc $(FILES) $(LIBS)

libft:
	make -C ../libft

minilibx:
	make -C ../minilibx_mms_20191025_beta

clean:
	make clean -C ../libft
	make clean -C ../minilibx_mms_20191025_beta

fclean: clean
	make fclean -C ../libft
	rm -fr libmlx.dylib
	rm -fr $(NAME)

re: fclean
	make all
