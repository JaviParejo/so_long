/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jparejo- <jparejo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 10:13:54 by jparejo-          #+#    #+#             */
/*   Updated: 2021/10/06 10:14:10 by jparejo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memchr(const void *str, int ch, size_t n)
{
	size_t			i;
	unsigned char	*origen;

	origen = (unsigned char *)str;
	i = 0;
	while (i < n)
	{
		if (origen[i] == (unsigned char)ch)
			return ((void *)(str + i));
		i++;
	}
	return (NULL);
}
