# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chfederi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/07 19:20:42 by chfederi          #+#    #+#              #
#    Updated: 2022/04/07 19:20:44 by chfederi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = so_long

LIST = main.c  move.c parse_map.c utils.c utils1.c ft_split.c\
	get_next_line.c get_next_line_utils.c mapdata.c image.c\
	tornado.c utils3.c utilsf.c\

OBJ =  $(patsubst %.c,%.o,$(LIST))

.PHONY : all clean fclean re

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o : %.c so_long.h
	$(CC)  -Imlx -c $< -o $@

clean :
	@rm -f $(OBJ)

fclean : clean
	@rm -f $(NAME)

re : fclean all