# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: javierparejo <javierparejo@student.42.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/08 13:14:05 by jparejo-          #+#    #+#              #
#    Updated: 2022/04/08 02:14:57 by javierparej      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			=	so_long.c sl_read.c sl_init.c sl_map.c \
				  	sl_images.c sl_moves.c sl_controls.c

OBJS			= $(SRCS:.c=.o)

CC				= gcc
RM				= rm -rf
CFLAGS			= -Wall -Wextra -Werror
MAKE			= make
LIBFT			= libft
NAME			= so_long
MLX				= mlx

all:			$(NAME)

$(NAME):		$(OBJS)
				$(MAKE) all -C $(MLX)
				$(MAKE) all -C $(LIBFT)
				$(CC) $(CFLAGS) $(OBJS) libft/libft.a -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
				$(MAKE) clean -C $(MLX)
				$(MAKE) clean -C $(LIBFT)
				$(RM) $(OBJS)

fclean:			clean
				$(MAKE) fclean -C $(LIBFT)
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re