/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jparejo- <jparejo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 16:33:36 by jparejo-          #+#    #+#             */
/*   Updated: 2022/03/24 16:49:07 by jparejo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>

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
