

NAME 	=	fractol
CC		= 	gcc
SRC		=	*.c
LIB		= -lmlx -framework OpenGL -framework AppKit
FLAGS	=	-Wall -Wextra -Werror

all : $(NAME)

$(NAME):
	$(CC) -g $(SRC) $(LIB) $(FLAGS) -o $(NAME)

clean :

fclean: clean
	(rm -rf $(NAME))
	rm -rf *.dSYM

re:	fclean all

.PHONY :clean fclean re
