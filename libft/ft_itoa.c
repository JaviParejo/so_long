/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javierparejo <javierparejo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 10:34:32 by jparejo-          #+#    #+#             */
/*   Updated: 2022/04/08 03:14:43 by javierparej      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_size(unsigned int un)
{
	unsigned int	size;

	size = 1;
	while (un >= 10)
	{
		un /= 10;
		size++;
	}
	return (size);
}

static char	*allocate_str(int size, int n)
{
	char	*str;
	int		i;

	i = 0;
	if (n < 0)
		i = 1;
	str = (char *)malloc(sizeof(char) * (size + 1 + i));
	if (!str)
		return (NULL);
	return (str);
}

static unsigned int	ft_absolute(int number)
{
	if (number < 0)
		return ((unsigned int)(number * -1));
	return ((unsigned int)number);
}

char	*ft_itoa(int n)
{
	char			*str;
	unsigned int	un;
	unsigned int	i;
	unsigned int	size;

	un = ft_absolute(n);
	size = ft_size(un);
	str = allocate_str(size, n);
	if (!str)
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		size++;
	}
	i = size - 1;
	while (un >= 10)
	{
		str[i--] = (char)(un % 10 + '0');
		un /= 10;
	}
	str[i] = (char)(un % 10 + '0');
	str[size] = 0;
	return (str);
}
