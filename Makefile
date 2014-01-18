#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/13 17:20:17 by gpetrov           #+#    #+#              #
#    Updated: 2014/01/18 15:41:58 by gpetrov          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME	= wolf3d
FILES	= main.c get_data.c ft_mlx.c draw.c tools.c move.c
SRCS	= $(addprefix src/, $(FILES))
OBJS	= $(SRCS:src/%.c=.obj/%.o)
INC		= -I includes -I libft/includes
FLAGS	= -Wall -Wextra -Werror
LIB		= -L libft -lft

all: $(NAME)

$(NAME): $(OBJS)
	make -C libft
	cc $(FLAGS) $(SRCS) -o $(NAME) $(INC) $(LIB) \
	-L /usr/X11/lib -lmlx -lXext -lX11
.obj/%.o: src/%.c
	mkdir -p .obj
	cc -c $< -o $@ $(FLAGS) $(INC)
gdb:
	make -C libft
	cc -g $(FLAGS) $(SRCS) -o $(NAME) $(INC) $(LIB) \
	-L /usr/X11/lib -lmlx -lXext -lX11
	gdb $(NAME)
clean:
	rm -rf .obj
fclean: clean
	rm -f $(NAME)
re: fclean all
