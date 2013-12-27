# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/04 14:47:38 by wbeets            #+#    #+#              #
#    Updated: 2013/12/26 20:27:05 by wbeets           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: clean fclean re

SRC = main.c\

LIB = libft/libft.a
NAME = minishell1
DEB = deb
FLAGS =  -Wall -Werror -Wextra
GITFILES = main.c\
			Makefile\
			libft\
			header.h
INC = libft/includes


all:
	gcc $(FLAGS) $(SRC) -L. $(LIB) -I $(INC) -o $(NAME)

gdb:
	cc -g $(SRC) -L. $(LIB) -I $(INC) -o $(DEB)
	gdb $(DEB)

gps:
	git add $(GITFILES); git commit -m"auto"; git push

gpl:
	git pull;

clean:
	rm -f $(NAME)

fclean: clean
	rm -f $(DEB)

re: fclean all 

