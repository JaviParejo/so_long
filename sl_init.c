/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jparejo- <jparejo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 11:24:02 by jparejo-          #+#    #+#             */
/*   Updated: 2022/04/13 15:51:17 by jparejo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy(t_mlx *vars)
{
	int	i;

	i = 0;
	if (vars->map)
	{
		while (vars->map[i])
		{
			free(vars->map[i]);
			i++;
		}
		free(vars->map);
	}
	if (vars->mlx)
	{
		mlx_destroy_image(vars->mlx, vars->img);
		mlx_clear_window(vars->mlx, vars->win);
		mlx_destroy_window(vars->mlx, vars->win);
	}
	// exit (0);
}

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
