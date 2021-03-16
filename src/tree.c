/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amya <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 02:09:19 by amya              #+#    #+#             */
/*   Updated: 2020/01/07 02:09:20 by amya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/frog_tol.h"

int			make_color_range(t_mlx *mlx, int start, int end, int limit)
{
	int		x;
	int		r;
	int		g;
	int		b;
	double	percent;

	x = 100;
	while (x <= limit)
	{
		percent = (double)(100 - x) / (double)(100 - 400);
		r = ((start >> 16 & 255) * (1.0 - percent))
		+ ((end >> 16 & 255) * percent);
		g = ((start >> 8 & 255) * (1.0 - percent))
		+ ((end >> 8 & 255) * percent);
		b = ((start & 255) * (1.0 - percent)) + ((end & 255)
		* percent);
		mlx->color = (r << 16) + (g << 8) + b;
		x++;
	}
	return (mlx->color);
}

void		init_line_vars(t_mlx *mlx, int y0, int x1, int y1)
{
	mlx->dx = abs(x1 - mlx->origin);
	mlx->sx = mlx->origin < x1 ? 1 : -1;
	mlx->dy = abs(y1 - y0);
	mlx->sy = y0 < y1 ? 1 : -1;
}

void		line(t_mlx *mlx, int y0, int x1, int y1)
{
	int err;
	int e2;
	int color;

	init_line_vars(mlx, y0, x1, y1);
	err = (mlx->dx > mlx->dy ? mlx->dx : -mlx->dy) / 2;
	color = make_color_range(mlx, 0x8B4513, 0x00FF00, mlx->limit);
	while (1)
	{
		if (y0 >= 0 && mlx->origin >= 0 && y0 < HEIGHT && mlx->origin < WIDTH)
			mlx->d[y0 * WIDTH + mlx->origin] = color;
		if (mlx->origin == x1 && y0 == y1)
			break ;
		e2 = err;
		if (e2 > -mlx->dx)
		{
			err -= mlx->dy;
			mlx->origin += mlx->sx;
		}
		if (e2 < mlx->dy)
		{
			err += mlx->dx;
			y0 += mlx->sy;
		}
	}
}

void		tree_rec(t_mlx *mlx, int originy, int originx, double angle)
{
	int yy;
	int y;
	int l;
	int ok;

	l = mlx->limit;
	ok = mlx->len;
	if (ok > 1)
	{
		y = originy - mlx->len;
		yy = y - originy;
		mlx->origin = originx;
		line(mlx, originy, -yy * sin(angle) +
		originx, yy * cos(angle) + originy);
		mlx->limit = l + 10;
		mlx->len = ok * 0.7;
		tree_rec(mlx, yy * cos(angle) + originy,
		-yy * sin(angle) + originx, mlx->tilt *
		(angle + mlx->ang));
		tree_rec(mlx, yy * cos(angle) + originy,
		-yy * sin(angle) + originx, angle - mlx->ang);
	}
	mlx->limit = l;
	mlx->len = ok;
}

void		put_tree(t_mlx *mlx)
{
	image_clear(mlx->d);
	mlx->limit = 100;
	mlx->len = HEIGHT * mlx->line;
	tree_rec(mlx, HEIGHT, WIDTH / 2, 0);
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img, 0, 0);
}
