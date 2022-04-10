# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: icheri <icheri@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/14 21:06:52 by icheri            #+#    #+#              #
#    Updated: 2022/04/10 15:53:16 by icheri           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long

SRCS_F	=	get_next_line_utils.c\
			get_next_line.c\
			parsing.c\
			so_long.c\
			valid_map.c\
			render_map.c\
			key_move.c
SRCS_D	=	src/

HEADER	=	includes/get_next_line.h includes/so_long.h

SRCS	=	$(addprefix $(SRCS_D),$(SRCS_F))
OBJ		=	$(SRCS:.c=.o)

CC		=	gcc

FLAGS	=	-Wall -Wextra -Werror

LIBFT	=	./libft

MLX		=	-L . -lmlx -framework OpenGL -framework AppKit

$(NAME)	:	$(OBJ) $(HEADER)
			$(MAKE) -C $(LIBFT)
			$(CC) $(FLAGS) -L./libft -lft $(MLX) $(OBJ) -o $(NAME)

.PHONY	:	all clean fclean re bonus

all		:	$(NAME)

%.o		:	%.c
			$(CC) $(FLAGS) -c $< -o $@

clean	:
			rm -rf $(OBJ)
			$(MAKE) clean -C $(LIBFT)

fclean	:	clean
			rm -rf $(NAME)

re		:	fclean all
