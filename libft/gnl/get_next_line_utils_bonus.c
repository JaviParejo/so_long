/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jparejo- <jparejo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 16:26:05 by jparejo-          #+#    #+#             */
/*   Updated: 2022/03/24 16:26:07 by jparejo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	int		count;
	char	*str;

	count = ft_strlen(s1);
	str = (char *)malloc((count + 1) * sizeof(char));
	if (!str)
		return (NULL);
	count = 0;
	while (s1[count])
	{
		str[count] = s1[count];
		count++;
	}
	str[count] = '\0';
	return (str);
}

void	*ft_memcpy(void *str1, const void *str2, size_t n)
{
	unsigned char	*temp1;
	unsigned char	*temp2;
	size_t			count;

	temp1 = (unsigned char *)str1;
	temp2 = (unsigned char *)str2;
	count = 0;
	if (str1 == NULL && str2 == NULL)
		return (NULL);
	while (count < n)
	{	
		temp1[count] = temp2[count];
		count++;
	}
	return (str1);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*aux;
	size_t		count;
	size_t		i;
	size_t		len;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	aux = (char *)malloc(len + 1 * sizeof(char));
	if (!aux)
		return (NULL);
	count = 0;
	i = 0;
	while (count < len && s1[count])
	{
		aux[count] = s1[count];
		count++;
	}
	while (count < len && s2[i])
		aux[count++] = s2[i++];
	aux[count] = '\0';
	free((char *) s1);
	return (aux);
}
