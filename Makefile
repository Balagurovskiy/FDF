NAME = fdf

SRC =	fdf.c\
		action_listener.c\
		actions.c\
		reader.c\
		render_line.c\
		render_window.c\
		rotate.c\
		scale.c\
		views.c\
		vortex3d.c\
		vortex_group.c\
		menu.c\
		move.c\
		colors.c

INCLUDE = fdf.h

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):  $(OBJ)
	make -C ./libft/
	gcc -Wextra -Wall $(OBJ) -lmlx -framework OpenGL -framework AppKit ./libft/libft.a -o $(NAME)
	
%.o: %.c
	gcc -c -Wextra -Wall -o $@ $<

clean:
	make -C libft/ clean
	rm -f $(OBJ)
	
fclean : clean
	rm -f $(NAME)
	
re: fclean all
