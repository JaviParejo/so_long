/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jparejo- <jparejo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 12:49:40 by jparejo-          #+#    #+#             */
/*   Updated: 2022/04/13 15:21:33 by jparejo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_esc(int keycode, t_mlx *vars)
{
	if (keycode == 53)
		destroy(vars);
	return (0);
}

int	close_cross(t_mlx *vars)
{
	destroy(vars);
	return (0);
}

int	main(int argc, char **argv)
{
	t_mlx	vars;

	vars.mlx = NULL;
	vars.win = NULL;
	vars.num = 0;
	vars.key = '0';
	vars.map = NULL;
	vars.img = NULL;
	vars.p = 0;
	vars.c = 0;
	vars.e = 0;
	vars.h = 0;
	vars.w = 0;
	read_map(argc, argv, &vars);
	mlx_hook(vars.win, 2, 1L << 0, close_esc, &vars);
	mlx_hook(vars.win, 17, 0, close_cross, &vars);
	mlx_key_hook(vars.win, moves, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
