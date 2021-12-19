# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: czak </var/mail/czak>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/19 14:20:54 by czak              #+#    #+#              #
#    Updated: 2021/12/19 19:57:33 by czak             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


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
