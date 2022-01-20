# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbenkhat <mbenkhat@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/02 19:24:53 by mbenkhat          #+#    #+#              #
#    Updated: 2022/01/08 17:01:00 by mbenkhat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

HEADER = so_long.h

FLAGS = -Wall -Wextra -Werror

MLX = -lmlx -framework OpenGL -framework AppKit

LIBFT = -Llibft -lft

SRCS = so_long.c get_map.c check_map.c extanded_func.c

B_SRCS = b_srcs/so_long_bonus.c b_srcs/get_map_bonus.c b_srcs/check_map_bonus.c b_srcs/extanded_func_bonus.c b_srcs/animy_bonus.c

all : $(NAME)

$(NAME) : library $(SRCS) $(HEADER)
	@gcc $(FLAGS) $(MLX) $(LIBFT) $(SRCS) -o $(NAME)

library :
	make -C libft

clean :
	make clean -C libft
	rm -f $(NAME)

fclean : clean
	make fclean -C libft

re : fclean all

bonus : library $(B_SRCS)
	@gcc $(FLAGS) $(MLX) $(LIBFT) $(B_SRCS) -o $(NAME)
