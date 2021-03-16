/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_n_square.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amya <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 02:08:33 by amya              #+#    #+#             */
/*   Updated: 2020/01/07 02:08:34 by amya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/frog_tol.h"

void		init_mlx(t_mlx *mlx, int nbr)
{
	mlx->min_r = -2.0;
	mlx->max_r = 2.0;
	mlx->min_i = -2.0;
	mlx->max_i = 2.0;
	mlx->max_it = 30;
	mlx->factor = 1.0;
	mlx->up = 0;
	mlx->tilt = 1;
	mlx->key = nbr;
	mlx->in_min = 0;
	mlx->in_max = WIDTH;
	mlx->fx = map(WIDTH / 2, mlx, mlx->min_r, mlx->max_r);
	mlx->in_max = HEIGHT;
	mlx->fy = map(HEIGHT / 2, mlx, mlx->min_i, mlx->max_i);
	if (mlx->key == 0)
	{
		mlx->min_r = 10000300;
		mlx->max_r = 10000400;
		mlx->min_i = 10001300;
		mlx->max_i = 10001400;
	}
}

void		init_main_stuff(t_mlx *mlx)
{
	mlx->limit = 100;
	mlx->started = 1;
	mlx->len = HEIGHT * mlx->line;
}

int			issierp(int x, int y)
{
	while (x > 0 || y > 0)
	{
		if (x % 3 == 1 && y % 3 == 1)
			return (0);
		x /= 3;
		y /= 3;
	}
	return (1);
}

void		*square(void *mlx)
{
	int		x;
	int		y;
	t_mlx	*mymlx;

	mymlx = (t_mlx *)mlx;
	x = mymlx->start;
	while (x < mymlx->end)
	{
		y = 0;
		while (y < WIDTH)
		{
			mymlx->in_min = 0;
			mymlx->in_max = WIDTH;
			mymlx->cx = map(x, mymlx, mymlx->min_r, mymlx->max_r);
			mymlx->in_max = HEIGHT;
			mymlx->cy = map(y, mymlx, mymlx->min_i, mymlx->max_i);
			if (issierp(mymlx->cx, mymlx->cy))
				mymlx->d[y * WIDTH + x] = 0xff0000;
			else
				mymlx->d[y * WIDTH + x] = 0x00ff00;
			y++;
		}
		x++;
	}
	return (NULL);
}

void		switch_screens_rest(t_mlx *mlx, int key)
{
	double	p;

	if (key == 86)
		mlx->key = 4;
	if (key == 87)
		mlx->key = 5;
	if (key == 88)
		mlx->key = 6;
	if (key == 89)
		mlx->key = 7;
	if (key == 91)
		mlx->key = 8;
	if (key == 92)
		mlx->key = 9;
	if (key == 82)
		mlx->key = 0;
	if (key == 65)
		mlx->key = 10;
	if (key == 125 || key == 126)
	{
		p = (mlx->max_i - mlx->min_i) / 10;
		mlx->max_i += key == 126 ? p : -p;
		mlx->min_i += key == 126 ? p : -p;
	}
}
