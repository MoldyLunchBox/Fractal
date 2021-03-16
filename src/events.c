/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amya <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 02:08:17 by amya              #+#    #+#             */
/*   Updated: 2020/01/07 02:08:21 by amya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/frog_tol.h"

void	switch_screens(t_mlx *mlx, int key)
{
	if (key == 83)
		mlx->key = 1;
	if (key == 1 && mlx->key != 0)
		screen_shot(mlx);
	if (key == 84)
		mlx->key = 2;
	if (key == 85)
	{
		mlx->key = 3;
		put_tree(mlx);
	}
	switch_screens_rest(mlx, key);
	if ((key >= 82 && key <= 89) || key == 91 || key == 92 || key == 65)
		init_mlx(mlx, mlx->key);
}

int		key_press(int key, t_mlx *mlx)
{
	double	p;

	switch_screens(mlx, key);
	if (key == 35)
		mlx->up = 1;
	if (key == 31)
		mlx->up = 0;
	if (key == 34)
		init_mlx(mlx, mlx->key);
	if (key == 124 || key == 123)
	{
		p = (mlx->max_r - mlx->min_r) / 10;
		mlx->max_r += key == 123 ? p : -p;
		mlx->min_r += key == 123 ? p : -p;
	}
	if (key == 53)
		exit(0);
	if (mlx->key != 3)
		threading(mlx);
	return (0);
}

int		mouse_move(int x, int y, t_mlx *mlx)
{
	if (mlx->key == 1 || mlx->key == 2 || mlx->key > 3 || mlx->key == 0)
	{
		mlx->in_min = 0;
		mlx->in_max = WIDTH;
		mlx->fx = map(x, mlx, mlx->min_r, mlx->max_r);
		mlx->in_max = HEIGHT;
		mlx->fy = map(y, mlx, mlx->min_i, mlx->max_i);
		threading(mlx);
	}
	if (mlx->key == 3)
	{
		mlx->in_min = 0;
		mlx->in_max = WIDTH;
		mlx->ang = map(x, mlx, 0, 10);
		mlx->line = map(y, mlx, 0, 1);
		image_clear(mlx->d);
		mlx->limit = 100;
		mlx->len = HEIGHT * mlx->line;
		tree_rec(mlx, HEIGHT, WIDTH / 2, 0);
		mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img, 0, 0);
	}
	return (0);
}

void	mouse_press_tree(t_mlx *mlx, int button)
{
	if (mlx->key == 3)
	{
		mlx->tilt += button == 4 ? 1 : -1;
		image_clear(mlx->d);
		mlx->limit = 100;
		mlx->len = HEIGHT * mlx->line;
		tree_rec(mlx, HEIGHT, WIDTH / 2, 0);
		mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img, 0, 0);
	}
}

int		mouse_press(int button, int x, int y, t_mlx *mlx)
{
	double	mouse_i;
	double	mouse_r;

	if (button == 4 || button == 5)
	{
		if (mlx->key == 1 || mlx->key == 2 || mlx->key > 3 || mlx->key == 0)
		{
			mlx->max_it += button == 4 ? 1 : -1;
			mlx->in_min = 0;
			mlx->in_max = WIDTH;
			mouse_i = map(y, mlx, mlx->min_i, mlx->max_i);
			mlx->in_max = HEIGHT;
			mouse_r = map(x, mlx, mlx->min_r, mlx->max_r);
			apply_zoom(mlx, mouse_r, mouse_i, button == 4 ? 1.1 : 1.0 / 1.1);
			threading(mlx);
		}
		mouse_press_tree(mlx, button);
	}
	return (0);
}
