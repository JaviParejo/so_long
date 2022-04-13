/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jparejo- <jparejo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 09:56:30 by jparejo-          #+#    #+#             */
/*   Updated: 2021/10/06 09:56:42 by jparejo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	int	*ptr;

	ptr = malloc(num * size);
	if (!(ptr))
		return (0);
	return (ft_memset(ptr, 0, (num * size)));
}
