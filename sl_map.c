/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jparejo- <jparejo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 02:12:35 by javierparej       #+#    #+#             */
/*   Updated: 2022/04/13 12:07:41 by jparejo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map_elements(int y, int x, t_mlx *vars)
{
	if (vars->map[y][x] == 'P')
		vars->p++;
	else if (vars->map[y][x] == 'C')
		vars->c++;
	else if (vars->map[y][x] == 'E')
		vars->e++;
}

void	check_map_letter(int width, int height, t_mlx *vars)
{	
	int	y;
	int	x;

	y = 0;
	while (vars->map[y])
	{
		x = 0;
		while (vars->map[y][x])
		{	
			if (vars->map[y][x] != '1' && vars->map[y][x] != '0'
				&& vars->map[y][x] != 'C' && vars->map[y][x] != 'E'
				&& vars->map[y][x] != 'P')
				print_error(6);
			else if ((x == 0 || x == width - 1 || y == 0 || y == height - 1)
				&& vars->map[y][x] != '1')
				print_error(7);
			else
				check_map_elements(y, x, vars);
			x++;
		}
		y++;
	}
	if (vars->p != 1 || vars->c < 1 || vars->e != 1)
		print_error(9);
}

void	check_map(t_mlx *vars)
{	
	int		width;
	int		height;
	int		size;

	width = 0;
	height = 0;
	size = 0;
	while (vars->map[height])
	{
		while (vars->map[height][size])
		{
			if (height == 0)
				width++;
			size++;
		}
		if (size != width)
			print_error(5);
		height++;
		size = 0;
	}
	if (width <= height)
		print_error(4);
	check_map_letter(width, height, vars);
}
