/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jparejo- <jparejo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 10:38:05 by jparejo-          #+#    #+#             */
/*   Updated: 2021/10/06 10:38:22 by jparejo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_fd(char *str, int fd)
{
	int	contador;
	int	longitud;

	if (!str)
		return ;
	contador = 0;
	while (str[contador] != '\0')
	{
		contador++;
	}
	longitud = contador;
	contador = 0;
	while (contador < longitud)
	{
		write(fd, &str[contador], 1);
		contador++;
	}
}
