# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jparejo- <jparejo-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/06 10:49:56 by jparejo-          #+#    #+#              #
#    Updated: 2022/03/31 12:46:47 by jparejo-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			=	ft_isalnum.c ft_isprint.c ft_memcmp.c ft_strdup.c \
					ft_strlcat.c ft_strncmp.c ft_atoi.c ft_isalpha.c \
					ft_memcpy.c  ft_strchr.c  ft_strlcpy.c ft_strnstr.c \
					ft_tolower.c ft_bzero.c   ft_isascii.c ft_memcpy.c \
					ft_memmove.c ft_strlen.c  ft_strrchr.c ft_calloc.c \
					ft_toupper.c ft_isdigit.c ft_memchr.c  ft_memset.c \
					ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c \
					ft_itoa.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
					ft_putstr_fd.c ft_striteri.c ft_strmapi.c ./gnl/get_next_line.c \
					./gnl/get_next_line_utils.c

OBJS			= $(SRCS:.c=.o)

FT_PRINTF_OBJS	= ./ft_printf/*.o
CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror
NAME			= libft.a
FT_PRINTF		= ft_printf

all:			$(NAME)

$(NAME):		$(OBJS)
				$(MAKE) all -C $(FT_PRINTF)
				ar rcs $(NAME) $(OBJS) $(FT_PRINTF_OBJS)

clean:
				$(RM) $(OBJS)
				$(MAKE) clean -C ./ft_printf/

fclean:			clean
				$(MAKE) fclean -C ./ft_printf/
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re