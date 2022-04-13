/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jparejo- <jparejo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 10:29:24 by jparejo-          #+#    #+#             */
/*   Updated: 2021/10/06 10:29:32 by jparejo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	size_t	len;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	ret = (char *)malloc((len + 1) * sizeof(char));
	if (ret == NULL)
		return (NULL);
	ft_strlcpy(ret, s1, ft_strlen((char *)s1) + 1);
	ft_strlcat(ret, s2, len + 1);
	return (ret);
}
