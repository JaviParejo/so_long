/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jparejo- <jparejo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 10:31:28 by jparejo-          #+#    #+#             */
/*   Updated: 2021/10/15 12:19:23 by jparejo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_contar(char const *s, char c)
{
	int		wlen;
	int		i;
	size_t	w;

	i = 0;
	wlen = 0;
	w = 0;
	while (s[i])
	{
		if (!wlen && s[i] != c)
			w++;
		if (s[i] == c)
			wlen = 0;
		else
			wlen = 1;
		i++;
	}
	return (w);
}

static	int	ft_lenword(char const *s, char c)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (s[i] == c)
		i++;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
		len++;
	}
	return (len);
}

char	**ft_fill(char const *s, char **des, char c)
{
	int		i;
	int		j;
	int		k;

	i = -1;
	j = 0;
	while (++i < ft_contar(s, c))
	{
		k = 0;
		des[i] = malloc(sizeof(*s) * (ft_lenword(&s[j], c) + 1));
		if (!(des[i]))
			des[i] = NULL;
		while (s[j] == c)
			j++;
		while (s[j] != c && s[j])
		{
			des[i][k] = s[j];
			k++;
			j++;
		}
		des[i][k] = '\0';
	}
	des[i] = 0;
	return (des);
}

char	**ft_split(const char *s, char c)
{
	char	**str;

	if (!s)
		return (NULL);
	str = (char **)malloc(sizeof(*str) * (ft_contar(s, c) + 1));
	if (!(str))
		return (NULL);
	str = ft_fill(s, str, c);
	return (str);
}
