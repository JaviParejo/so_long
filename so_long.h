/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jparejo- <jparejo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 18:59:25 by jparejo-          #+#    #+#             */
/*   Updated: 2022/04/13 15:42:59 by jparejo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include "mlx/mlx.h"
# include "libft/libft.h"

typedef struct mlx {
	void	*mlx;
	void	*win;
	char	**map;
	int		num;
	char	key;
	void	*img;
	int		p;
	int		c;
	int		e;
	int		h;
	int		w;
}	t_mlx;

int		close_esc(int keycode, t_mlx *vars);

int		close_cross(t_mlx *vars);

void	print_error(int error, t_mlx *vars);

void	check_read(int argc, char **argv, t_mlx *vars);

void	check_map_letter(int width, int height, t_mlx *vars);

void	check_map_elements(int y, int x, t_mlx *vars);

void	check_map(t_mlx *vars);

void	check_map_emptylines(char *str, t_mlx *vars);

void	read_map(int argc, char **argv, t_mlx *vars);

char	*image_exit(t_mlx *vars);

char	*image_rocket(t_mlx *vars);

char	*select_images(char c, void *img, t_mlx *vars);

void	print_images(t_mlx *vars);

int		map_with(t_mlx *vars);

int		map_height(t_mlx *vars);

void	init(t_mlx *vars);

int		moves(int keycode, t_mlx *vars);

void	search_player(t_mlx *vars);

void	make_move(char move, int y, int x, t_mlx *vars);

void	final_move(t_mlx *vars);

void	move_up(int y, int x, t_mlx *vars);

void	move_left(int y, int x, t_mlx *vars);

void	move_down(int y, int x, t_mlx *vars);

void	move_right(int y, int x, t_mlx *vars);

void	destroy(t_mlx *vars);

void	leak(void);

#endif
