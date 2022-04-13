/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jparejo- <jparejo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 10:20:35 by jparejo-          #+#    #+#             */
/*   Updated: 2021/10/06 10:20:52 by jparejo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			count;

	if (dst == NULL && src == NULL)
		return (NULL);
	count = 0;
	if (dst <= src)
	{
		while (count < len)
		{
			(((unsigned char *)dst)[count] = ((unsigned char *)src)[count]);
			count++;
		}
	}
	else
	{
		while (len > 0)
		{
			(((unsigned char *)dst)[len - 1] = ((unsigned char *)src)[len - 1]);
			len--;
		}
	}
	return (dst);
}
