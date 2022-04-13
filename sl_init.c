/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jparejo- <jparejo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 11:24:02 by jparejo-          #+#    #+#             */
/*   Updated: 2022/04/08 18:15:01 by jparejo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_with(t_mlx *vars)
{
	int		width;
	int		height;

	width = 0;
	height = 0;
	while (vars->map[height])
	{
		while (vars->map[height][width])
			width++;
		height++;
	}
	return (width);
}

int	map_height(t_mlx *vars)
{
	int		width;
	int		height;

	width = 0;
	height = 0;
	while (vars->map[height])
	{
		while (vars->map[height][width])
			width++;
		height++;
	}
	return (height);
}

void	init(t_mlx *vars)
{
	int	height;
	int	width;

	width = map_with(vars) * 64;
	height = map_height(vars) * 64;
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, width, height, "SO_LONG");
	print_images(vars);
}
