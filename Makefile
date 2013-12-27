# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/04 14:47:38 by wbeets            #+#    #+#              #
#    Updated: 2013/12/27 11:42:28 by wbeets           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: clean fclean re

SRC = main.c\
	  functions.c
LIB = libft/ -lft
NAME = minishell1
DEB = deb
FLAGS =  -Wall -Werror -Wextra
GITFILES = main.c\
			Makefile\
			libft\
			header.h\
			functions.c
INC = libft/includes
OBJ = $(SRC:.c=.o)


all: $(NAME)

$(NAME): $(OBJ)
	make re -C libft/
	gcc $(FLAGS) $(OBJ) -L $(LIB) -o $@

%.o: %.c
	gcc -o $@ -c $< $(FLAGS) -I $(INC) -L $(LIB)

gdb:
	cc -g $(SRC) -L. $(LIB) -I $(INC) -o $(DEB)
	gdb $(DEB)

gps:
	git add $(GITFILES); git commit -m"auto"; git push

gpl:
	git pull;

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(DEB) $(NAME)

re: fclean all

