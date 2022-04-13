/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jparejo- <jparejo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:54:33 by jparejo-          #+#    #+#             */
/*   Updated: 2022/04/13 11:56:43 by jparejo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	make_move(char move, int y, int x, t_mlx *vars)
{
	if (move == 'u')
		move_up(y, x, vars);
	else if (move == 'l')
		move_left(y, x, vars);
	else if (move == 'd')
		move_down(y, x, vars);
	else if (move == 'r')
		move_right(y, x, vars);
}

void	search_player(t_mlx *vars)
{
	int	y;
	int	x;
	int	player;

	y = 0;
	x = 0;
	player = 0;
	while (vars->map[y])
	{
		while (vars->map[y][x])
		{
			if (vars->map[y][x] == 'P')
			{
				player = 1;
				break ;
			}
			x++;
		}
		if (player == 1)
			break ;
		x = 0;
		y++;
	}
	make_move(vars->key, y, x, vars);
}

int	moves(int keycode, t_mlx *vars)
{
	if (keycode == 13)
	{
		vars->key = 'u';
		search_player(vars);
	}
	else if (keycode == 0)
	{
		vars->key = 'l';
		search_player(vars);
	}
	else if (keycode == 1)
	{
		vars->key = 'd';
		search_player(vars);
	}
	else if (keycode == 2)
	{
		vars->key = 'r';
		search_player(vars);
	}
	return (0);
}
