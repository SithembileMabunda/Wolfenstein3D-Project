# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smabunda <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/16 13:13:44 by smabunda          #+#    #+#              #
#    Updated: 2018/10/16 14:29:52 by smabunda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

Sources = ft_buttons.c \
		  wolf.c \
		  ft_esc.c \
		  ft_drawer.c \
		  ft_reader.c \
		  ft_rc.c \
		  ft_error.c \
		  ft_wolf.c \

Objects = $(Sources:.c=.o)

Includes = wolf.h

CC = gcc

CFLAGS = -Wall -Wextra -Werror 

MLXFLAGS = -L /usr/local/include -lmlx -framework OpenGL -framework AppKit

Libft = -L ./libft -lft

Libft_ = libft/

all : $(NAME)

$(NAME) : $(Objects)
		@make -C $(Libft_)
		$(CC) -o $(NAME) $(Objects) -lm -L $(Libft_) -lft -lmlx -framework OpenGL -framework AppKit

clean :
		/bin/rm -f $(Objects)
		make -C $(Libft_) fclean

fclean : clean
		/bin/rm -f $(Name)
		make -C $(Libft_) fclean

re : fclean all
