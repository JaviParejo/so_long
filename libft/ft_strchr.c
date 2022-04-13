/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jparejo- <jparejo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 10:09:13 by jparejo-          #+#    #+#             */
/*   Updated: 2021/10/07 13:40:44 by jparejo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	unsigned int	count;

	count = 0;
	while (str[count] && str[count] != (unsigned char)c)
		count++;
	if (str[count] == (unsigned char)c)
		return ((char *)str + count);
	return (0);
}
