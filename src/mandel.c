/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amya <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 02:08:54 by amya              #+#    #+#             */
/*   Updated: 2020/01/07 02:09:04 by amya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/frog_tol.h"

void		fracs1_(t_mlx *mymlx, int *radius)
{
	if (mymlx->key == 1)
	{
		mymlx->aa = mymlx->cx * mymlx->cx - mymlx->cy * mymlx->cy + mymlx->px;
		mymlx->bb = 2 * mymlx->cx * mymlx->cy + mymlx->py;
		*radius = 30;
	}
	if (mymlx->key == 6)
	{
		mymlx->aa = mymlx->cx * mymlx->cx * mymlx->cx - 3
		* mymlx->cx * mymlx->cy * mymlx->cy + mymlx->px;
		mymlx->bb = 3 * mymlx->cx * mymlx->cx * mymlx->cy -
		mymlx->cy * mymlx->cy * mymlx->cy + mymlx->py;
		*radius = 4;
	}
	if (mymlx->key == 7)
	{
		mymlx->aa = mymlx->cx * mymlx->cx * mymlx->cx - 3 *
		mymlx->cx * mymlx->cy * mymlx->cy + mymlx->px;
		mymlx->bb = 3 * mymlx->cx * mymlx->cx * mymlx->cy -
		mymlx->cy * mymlx->cy * mymlx->cy + mymlx->py;
		*radius = 4;
	}
}

void		fracs10_(t_mlx *mymlx, int *radius)
{
	if (mymlx->key == 10)
	{
		mymlx->aa = mymlx->cx * mymlx->cx * mymlx->cx * mymlx->cx * mymlx->cx *
		mymlx->cx * mymlx->cx * mymlx->cx * mymlx->cx - 36 * mymlx->cx *
		mymlx->cx * mymlx->cx * mymlx->cx * mymlx->cx * mymlx->cx * mymlx->cx *
		mymlx->cy * mymlx->cy + 126 * mymlx->cx * mymlx->cx * mymlx->cx *
		mymlx->cx * mymlx->cx * mymlx->cy * mymlx->cy * mymlx->cy * mymlx->cy -
		84 * mymlx->cx * mymlx->cx * mymlx->cx * mymlx->cy * mymlx->cy *
		mymlx->cy * mymlx->cy * mymlx->cy * mymlx->cy + 9 * mymlx->cx *
		mymlx->cy * mymlx->cy * mymlx->cy * mymlx->cy * mymlx->cy * mymlx->cy *
		mymlx->cy * mymlx->cy + mymlx->cx + mymlx->px;
		mymlx->bb = 9 * mymlx->cx * mymlx->cx * mymlx->cx * mymlx->cx *
		mymlx->cx * mymlx->cx * mymlx->cx * mymlx->cx * mymlx->cy - 84 *
		mymlx->cx * mymlx->cx * mymlx->cx * mymlx->cx * mymlx->cx * mymlx->cx *
		mymlx->cy * mymlx->cy * mymlx->cy + 126 * mymlx->cx * mymlx->cx *
		mymlx->cx * mymlx->cx * mymlx->cy * mymlx->cy * mymlx->cy * mymlx->cy *
		mymlx->cy - 36 * mymlx->cy * mymlx->cy * mymlx->cy * mymlx->cy *
		mymlx->cy * mymlx->cy * mymlx->cy * mymlx->cx * mymlx->cx + mymlx->cy *
		mymlx->cy * mymlx->cy * mymlx->cy * mymlx->cy * mymlx->cy * mymlx->cy *
		mymlx->cy * mymlx->cy + mymlx->cy + mymlx->py;
		*radius = 4;
	}
}

void		fracs8_5(t_mlx *mymlx, int *radius)
{
	if (mymlx->key == 8)
	{
		mymlx->aa = mymlx->cx * mymlx->cx * mymlx->cx * mymlx->cx - 6 *
		mymlx->cx * mymlx->cx * mymlx->cy * mymlx->cy + mymlx->cy * mymlx->cy *
		mymlx->cy * mymlx->cy + mymlx->px;
		mymlx->bb = 4 * (mymlx->cx * mymlx->cx * mymlx->cx * mymlx->cy -
		mymlx->cx * mymlx->cy * mymlx->cy * mymlx->cy) + mymlx->py;
		*radius = 4;
	}
	if (mymlx->key == 5)
	{
		mymlx->aa = (cos(mymlx->cy) * exp(mymlx->cx) - cos(mymlx->cy) *
		exp(-mymlx->cx)) / 2 + mymlx->px / (mymlx->px * mymlx->px +
		mymlx->py * mymlx->py);
		mymlx->bb = (sin(mymlx->cy) * exp(mymlx->cx) + sin(mymlx->cy) *
		exp(-mymlx->cx)) / 2 - mymlx->py / (mymlx->px * mymlx->px +
		mymlx->py * mymlx->py);
		*radius = 100;
	}
}

void		fracs9_4(t_mlx *mymlx, int *radius)
{
	if (mymlx->key == 9)
	{
		mymlx->aa = mymlx->cx * mymlx->cx - mymlx->cy * mymlx->cy +
		mymlx->px;
		mymlx->bb = -2 * mymlx->cx * mymlx->cy + mymlx->py;
		*radius = 30;
	}
	if (mymlx->key == 4)
	{
		mymlx->aa = mymlx->cx * mymlx->cx * mymlx->cx - 3
		* mymlx->cx * mymlx->cy * mymlx->cy + mymlx->cx * mymlx->cx -
		mymlx->cy * mymlx->cy + mymlx->px;
		mymlx->bb = 3 * mymlx->cx * mymlx->cx * mymlx->cy -
		mymlx->cy * mymlx->cy * mymlx->cy + 2 * mymlx->cx
		* mymlx->cy + mymlx->py;
		*radius = 4;
	}
}

void		*mandel(void *mlx)
{
	t_mlx	*mymlx;
	int		x;
	int		y;

	mymlx = (t_mlx *)mlx;
	x = mymlx->start;
	while (x < mymlx->end)
	{
		y = 0;
		while (y < WIDTH)
		{
			mandel_norm_bs(mymlx, x, y);
			mymlx->it = iterations(mymlx);
			if (mymlx->it == mymlx->max_it)
				mymlx->d[y * WIDTH + x] = 0x000000;
			else
				mymlx->d[y * WIDTH + x] = ((mymlx->it * 10) << 16) |
				((mymlx->it * 3) << 8) | mymlx->it;
			y++;
		}
		x++;
	}
	return (NULL);
}
