/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jparejo- <jparejo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 16:08:54 by jparejo-          #+#    #+#             */
/*   Updated: 2022/03/24 16:27:15 by jparejo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	endofline(char *buff)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	if (!buff)
		return (count);
	while (buff[i] != '\0' && count == 0)
	{
		if (buff[i] == '\n')
			count = 1;
		i++;
	}
	return (count);
}

char	*currentline(char *memory)
{
	char	*line;
	int		len;
	int		i;

	len = 0;
	i = 0;
	while (memory[len] && memory[len] != '\n')
	{
		len++;
	}
	if (memory[len] == '\n')
		len++;
	line = malloc(sizeof(char) * (len + 1));
	if (!line)
		return (NULL);
	len = 0;
	while (memory[len] && memory[len] != '\n')
	{
		line[len] = memory[len];
		len++;
	}
	if (memory[len] == '\n')
		line[len++] = '\n';
	line[len] = '\0';
	return (line);
}

char	*nextline(char *memory)
{
	size_t	count;
	int		len;
	char	*buffer2;
	int		i;

	count = 0;
	len = ft_strlen(memory);
	i = 0;
	while (memory[count] && memory[count] != '\n')
		count++;
	if (memory[count] == '\n')
		count++;
	buffer2 = malloc(sizeof(char) * (len + 1));
	if (!buffer2)
		return (NULL);
	while (memory[count])
		buffer2[i++] = memory[count++];
	buffer2[i] = '\0';
	free(memory);
	return (buffer2);
}

char	*readloop(char *memory, int fd, char *buffer, int *error)
{
	int	num;

	num = 1;
	while (num > 0 && endofline(memory) == 0)
	{
		num = read(fd, buffer, BUFFER_SIZE);
		if (num == -1)
		{
			*error = 1;
			break ;
		}
		if (num == 0)
		{
			*error = 2;
			break ;
		}
		buffer[num] = '\0';
		memory = ft_strjoin(memory, buffer);
	}
	return (memory);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*memory;
	char		*line;
	int			error;

	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	if (!memory)
		memory = ft_strdup("");
	error = 0;
	memory = readloop(memory, fd, buffer, &error);
	free(buffer);
	if (!*memory || !memory || error == 1)
	{
		free(memory);
		memory = NULL;
		return (NULL);
	}
	line = currentline(memory);
	memory = nextline(memory);
	return (line);
}
