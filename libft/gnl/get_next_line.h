/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javierparejo <javierparejo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 16:33:36 by jparejo-          #+#    #+#             */
/*   Updated: 2022/04/08 03:22:13 by javierparej      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);

int		endofline(char *memory);

char	*currentline(char *memory);

char	*nextline(char *memory);

char	*readloop(char *memory, int fd, char *buffer, int *error);

size_t	ft_strlen(const char *str);

char	*ft_strdup(const char *s1);

void	*ft_memcpy(void *str1, const void *str2, size_t n);

char	*ft_strjoin(char const *s1, char const *s2);

#endif