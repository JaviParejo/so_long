/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jparejo- <jparejo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 10:27:55 by jparejo-          #+#    #+#             */
/*   Updated: 2021/10/13 12:34:15 by jparejo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*aux;
	unsigned int	count;

	if (!s)
		return (NULL);
	if (len > ft_strlen(s))
		aux = (char *)malloc((ft_strlen(s)) * sizeof(char));
	else
		aux = (char *)malloc((len + 1) * sizeof(char));
	count = 0;
	if (!aux)
		return (NULL);
	if (start >= ft_strlen(s))
		start = ft_strlen(s);
	i = start;
	while (count < (unsigned int)len && s[i])
	{
		aux[count] = s[i];
		count++;
		i++;
	}
	aux[count] = '\0';
	return (aux);
}
