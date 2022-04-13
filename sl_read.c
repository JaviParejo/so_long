/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javierparejo <javierparejo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 17:21:31 by jparejo-          #+#    #+#             */
/*   Updated: 2022/04/08 05:53:28 by javierparej      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_error(int error)
{
	if (error == 1)
		ft_printf("%s", "[ERROR] No se ha podido leer el mapa.\n");
	else if (error == 2)
		ft_printf("%s", "[ERROR] Número de argumenos inválido.\n");
	else if (error == 3)
		ft_printf("%s", "[ERROR] Extensión de archivo inválida.\n");
	else if (error == 4)
		ft_printf("%s", "[ERROR] Tamaño de mapa inválido.\n");
	else if (error == 5)
		ft_printf("%s", "[ERROR] Filas con distinto tamaño.\n");
	else if (error == 6)
		ft_printf("%s", "[ERROR] Caracter inválido en el mapa.\n");
	else if (error == 7)
		ft_printf("%s", "[ERROR] Límites del mapa inválidos.\n");
	else if (error == 8)
		ft_printf("%s", "[ERROR] Hay una línea vacía en el mapa.\n");
	else if (error == 9)
		ft_printf("%s", "[ERROR] Número inválido de elementos en el mapa.\n");
	exit (0);
}

void	check_map_emptylines(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\n')
	{
		free(str);
		print_error(8);
	}
	while (str[i] != '\0')
	{
		if (str[i] == '\n' && (str[i + 1] == '\n' || str[i + 1] == '\0'))
		{
			free(str);
			print_error(8);
		}
		i++;
	}
}

void	check_read(int argc, char **argv)
{
	int	i;

	if (argc != 2)
		print_error(2);
	if (!ft_strchr(argv[1], '.'))
		print_error(3);
	i = ft_strlen(argv[1]) - 4;
	if (ft_strncmp(&argv[1][i], ".ber", 4))
		print_error(3);
}

void	read_map(int argc, char **argv, t_mlx *vars)
{
	int		file;
	char	*line;
	char	*str;
	char	**map;

	file = open(argv[1], O_RDONLY);
	str = ft_strdup("");
	line = get_next_line(file);
	while (line)
	{
		str = ft_strjoin(str, line);
		free(line);
		line = get_next_line(file);
	}
	free(line);
	check_map_emptylines(str);
	map = ft_split(str, '\n');
	free(str);
	check_read(argc, argv);
	if (!*map)
		print_error(1);
	vars->map = map;
	check_map(vars);
	init(vars);
}
