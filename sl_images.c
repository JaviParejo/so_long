/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_images.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jparejo- <jparejo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 13:47:22 by jparejo-          #+#    #+#             */
/*   Updated: 2022/04/13 14:54:51 by jparejo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*image_exit(t_mlx *vars)
{
	char	*img;

	if (vars->c == 0)
		img = "images/exit.xpm";
	else
		img = "images/exit_init.xpm";
	return (img);
}

char	*image_rocket(t_mlx *vars)
{
	char	*img;

	if (vars->key == 'u')
		img = "images/rocket_up.xpm";
	else if (vars->key == 'l')
		img = "images/rocket_left.xpm";
	else if (vars->key == 'd')
		img = "images/rocket_down.xpm";
	else
		img = "images/rocket_right.xpm";
	return (img);
}

char	*select_images(char c, void *img, t_mlx *vars)
{
	char	*sky;
	char	*wall;
	char	*rocket;
	char	*planet;
	char	*exit;

	sky = "images/space.xpm";
	wall = "images/rock.xpm";
	rocket = image_rocket(vars);
	planet = "images/planeta.xpm";
	exit = image_exit(vars);
	if (c == '1')
		img = mlx_xpm_file_to_image(vars->mlx, wall, &vars->h, &vars->w);
	else if (c == 'P')
		img = mlx_xpm_file_to_image(vars->mlx, rocket, &vars->h, &vars->w);
	else if (c == 'E')
		img = mlx_xpm_file_to_image(vars->mlx, exit, &vars->h, &vars->w);
	else if (c == 'C')
		img = mlx_xpm_file_to_image(vars->mlx, planet, &vars->h, &vars->w);
	else
		img = mlx_xpm_file_to_image(vars->mlx, sky, &vars->h, &vars->w);
	return (img);
}

void	print_images(t_mlx *vars)
{
	int		w;
	int		h;
	int		y;
	int		x;

	h = 0;
	w = 0;
	y = 0;
	x = 0;
	while (vars->map[h])
	{
		while (vars->map[h][w])
		{
			vars->img = select_images(vars->map[h][w], vars->img, vars);
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img, x, y);
			x = x + 64;
			w++;
		}
		h++;
		w = 0;
		y = y + 64;
		x = 0;
	}
}
