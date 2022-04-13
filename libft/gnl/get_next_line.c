/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jparejo- <jparejo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 16:08:54 by jparejo-          #+#    #+#             */
/*   Updated: 2022/04/13 13:51:24 by jparejo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	endofline(char *memory)
{
	int	end;
	int	i;

	end = 0;
	i = 0;
	if (!memory)
		return (end);
	while (memory[i] != '\0' && end == 0)
	{
		if (memory[i] == '\n')
			end = 1;
		i++;
	}
	return (end);
}

char	*currentline(char *memory)
{
	char	*line;
	int		size;

	size = 0;
	while (memory[size] && memory[size] != '\n')
	{
		size++;
	}
	if (memory[size] == '\n')
		size++;
	line = malloc(sizeof(char) * (size + 1));
	if (!line)
		return (NULL);
	size = 0;
	while (memory[size] && memory[size] != '\n')
	{
		line[size] = memory[size];
		size++;
	}
	if (memory[size] == '\n')
		line[size++] = '\n';
	line[size] = '\0';
	return (line);
}

char	*nextline(char *memory)
{
	size_t	count;
	int		size;
	char	*buffer;
	int		i;

	count = 0;
	size = ft_strlen(memory);
	i = 0;
	while (memory[count] && memory[count] != '\n')
		count++;
	if (memory[count] == '\n')
		count++;
	buffer = malloc(sizeof(char) * (size + 1));
	if (!buffer)
		return (NULL);
	while (memory[count])
		buffer[i++] = memory[count++];
	buffer[i] = '\0';
	free(memory);
	return (buffer);
}

char	*readloop(char *memory, int fd, char *buffer, int *error)
{
	int	i;

	i = 1;
	while (i > 0 && endofline(memory) == 0)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1)
		{
			*error = 1;
			break ;
		}
		if (i == 0)
		{
			*error = 2;
			break ;
		}
		buffer[i] = '\0';
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
