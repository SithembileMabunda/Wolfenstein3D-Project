# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smabunda <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/05 11:37:15 by smabunda          #+#    #+#              #
#    Updated: 2018/08/26 11:34:27 by smabunda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc -c

CFLAGS = -Wall -Wextra -Werror -I include

OBJ = *.o

SRC = *.c

$(NAME):
	$(CC) $(SRC) $(CFLAGS)
	ar rcs $(NAME) $(OBJ)
	ranlib $(NAME)

all: $(NAME)

fclean:
	rm -f $(OBJ) $(NAME)

clean:
	rm -f $(OBJ)

re: fclean all
