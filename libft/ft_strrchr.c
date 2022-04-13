/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jparejo- <jparejo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 10:10:31 by jparejo-          #+#    #+#             */
/*   Updated: 2021/10/07 13:42:11 by jparejo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	count;

	count = ft_strlen(str);
	while (count >= 0)
	{
		if (str[count] == (unsigned char)c)
			return ((char *)str + (count));
		count--;
	}
	return (0);
}
