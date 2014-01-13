#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/03 17:21:43 by gpetrov           #+#    #+#              #
#    Updated: 2014/01/13 15:08:25 by gpetrov          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME	= wolf3d
FILES	= main.c
SRCS	= $(addprefix src/, $(FILES))
OBJS	= $(SRCS:src/%.c=.obj/%.o)
INC		= -I includes -I libft/includes
FLAGS	= -Wall -Wextra -Werror
LIB		= -L libft -lft

all: $(NAME)

$(NAME): $(OBJS)
	make -C libft
	cc $(FLAGS) $(SRCS) -o $(NAME) $(INC) $(LIB)
.obj/%.o: src/%.c
	mkdir -p .obj
	cc -c $< -o $@ $(FLAGS) $(INC)
gdb:
	make -C libft
	cc -g $(FLAGS) $(SRCS) -o $(NAME) $(INC) $(LIB)
	gdb $(NAME)
clean:
	rm -rf .obj
fclean: clean
	rm -f $(NAME)
re: fclean all
