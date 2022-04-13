/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_controls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jparejo- <jparejo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 20:28:44 by jparejo-          #+#    #+#             */
/*   Updated: 2022/04/13 15:42:54 by jparejo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	final_move(t_mlx *vars)
{
	vars->num++;
	ft_printf("%d\n%s\n", vars->num, "¡Has ganado!");
	destroy(vars);
	atexit(leak);
	exit (0);
}

void	move_up(int y, int x, t_mlx *vars)
{
	char	temp;

	if (vars->map[y - 1][x] != '1' && vars->map[y - 1][x] != 'E')
	{
		vars->num++;
		ft_printf("%d\n", vars->num);
		if (vars->map[y - 1][x] == 'C')
		{
			vars->map[y - 1][x] = vars->map[y][x];
			vars->map[y][x] = '0';
			vars->c--;
		}
		else
		{
			temp = vars->map[y][x];
			vars->map[y][x] = vars->map[y - 1][x];
			vars->map[y - 1][x] = temp;
		}
		print_images(vars);
	}
	if (vars->map[y - 1][x] == 'E' && vars->c == 0)
		final_move(vars);
}

void	move_left(int y, int x, t_mlx *vars)
{
	char	temp;

	if (vars->map[y][x - 1] != '1' && vars->map[y][x - 1] != 'E')
	{
		vars->num++;
		ft_printf("%d\n", vars->num);
		if (vars->map[y][x - 1] == 'C')
		{
			vars->map[y][x - 1] = vars->map[y][x];
			vars->map[y][x] = '0';
			vars->c--;
		}
		else
		{
			temp = vars->map[y][x];
			vars->map[y][x] = vars->map[y][x - 1];
			vars->map[y][x - 1] = temp;
		}
		print_images(vars);
	}
	if (vars->map[y][x - 1] == 'E' && vars->c == 0)
		final_move(vars);
}

void	move_down(int y, int x, t_mlx *vars)
{
	char	temp;

	if (vars->map[y + 1][x] != '1' && vars->map[y + 1][x] != 'E')
	{
		vars->num++;
		ft_printf("%d\n", vars->num);
		if (vars->map[y + 1][x] == 'C')
		{
			vars->map[y + 1][x] = vars->map[y][x];
			vars->map[y][x] = '0';
			vars->c--;
		}
		else
		{
			temp = vars->map[y][x];
			vars->map[y][x] = vars->map[y + 1][x];
			vars->map[y + 1][x] = temp;
		}
		print_images(vars);
	}
	if (vars->map[y + 1][x] == 'E' && vars->c == 0)
		final_move(vars);
}

void	move_right(int y, int x, t_mlx *vars)
{
	char	temp;

	if (vars->map[y][x + 1] != '1' && vars->map[y][x + 1] != 'E')
	{
		vars->num++;
		ft_printf("%d\n", vars->num);
		if (vars->map[y][x + 1] == 'C')
		{
			vars->map[y][x + 1] = vars->map[y][x];
			vars->map[y][x] = '0';
			vars->c--;
		}
		else
		{
			temp = vars->map[y][x];
			vars->map[y][x] = vars->map[y][x + 1];
			vars->map[y][x + 1] = temp;
		}
		print_images(vars);
	}
	if (vars->map[y][x + 1] == 'E' && vars->c == 0)
		final_move(vars);
}
