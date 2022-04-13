/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jparejo- <jparejo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 10:22:11 by jparejo-          #+#    #+#             */
/*   Updated: 2021/10/13 12:28:00 by jparejo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	unsigned int	count;

	if (dstsize == 0)
		return (ft_strlen(src));
	count = 0;
	while (dstsize > 1 && *src)
	{
		*dst = *src;
		++dst;
		++src;
		--dstsize;
		++count;
	}
	*dst = '\0';
	while (*dst || *src)
	{
		if (*src)
		{
			++src;
			++count;
		}
	}
	return (count);
}
