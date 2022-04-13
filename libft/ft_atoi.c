/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jparejo- <jparejo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 09:52:37 by jparejo-          #+#    #+#             */
/*   Updated: 2021/10/13 13:43:25 by jparejo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_return_num(const char *str, int count, int sign)
{
	unsigned long long	num;

	num = str[count] - '0';
	while (str[count + 1] >= '0' && str[count + 1] <= '9')
	{
		num *= 10;
		num += str[count + 1] - '0';
		count++;
	}
	if (sign != '-' && num > 9223372036854775807)
		return (-1);
	if (sign == '-' && num > 9223372036854775807)
		return (0);
	if (sign == '-')
		return (-num);
	return (num);
}

int	ft_atoi(const char *str)
{
	int	count;
	int	sign;

	count = 0;
	while (str[count] == '\t' || str[count] == '\n' || str[count] == '\v'
		|| str[count] == '\f' || str[count] == '\r' || str[count] == ' ')
		count++;
	if (str[count] == '+' || str[count] == '-')
	{
		sign = '+';
		if (str[count] == '-')
			sign = '-';
		count++;
	}
	if (str[count] >= '0' && str[count] <= '9')
		return (ft_return_num(str, count, sign));
	return (0);
}
