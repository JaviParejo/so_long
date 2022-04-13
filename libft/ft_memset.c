/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jparejo- <jparejo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 10:13:21 by jparejo-          #+#    #+#             */
/*   Updated: 2021/10/06 10:13:32 by jparejo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	*ft_memset(void *str, int c, size_t n)
{
	char	*a;
	size_t	i;

	a = str;
	i = 0;
	while (n > i)
	{
		a[i] = c;
		i++;
	}
	return (str);
}
