/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jparejo- <jparejo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 10:12:48 by jparejo-          #+#    #+#             */
/*   Updated: 2021/10/06 10:12:59 by jparejo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*s1_t;
	unsigned char	*s2_t;
	size_t			count;

	count = 0;
	s1_t = (unsigned char *)s1;
	s2_t = (unsigned char *)s2;
	while (count < n && s1_t[count] && s2_t[count])
	{
		if (s1_t[count] != s2_t[count])
			return (s1_t[count] - s2_t[count]);
		count++;
	}
	if (count < n)
		return (s1_t[count] - s2_t[count]);
	return (0);
}
