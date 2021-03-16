/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandel_norm_bs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amya <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 02:18:50 by amya              #+#    #+#             */
/*   Updated: 2020/01/07 02:18:52 by amya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/frog_tol.h"

int			iterations(t_mlx *mymlx)
{
	int radius;

	mymlx->it = 0;
	while (mymlx->it < mymlx->max_it)
	{
		fracs1_(mymlx, &radius);
		fracs10_(mymlx, &radius);
		fracs8_5(mymlx, &radius);
		fracs9_4(mymlx, &radius);
		if (mymlx->key == 6)
		{
			mymlx->aa = mymlx->cx * mymlx->cx - mymlx->cy
			* mymlx->cy + mymlx->px;
			mymlx->bb = 2 * fabs(mymlx->cx * mymlx->cy) + mymlx->py;
			radius = 30;
		}
		mymlx->cx = mymlx->aa;
		mymlx->cy = mymlx->bb;
		if (mymlx->aa * mymlx->aa + mymlx->bb * mymlx->bb > radius)
			break ;
		mymlx->it++;
	}
	return (mymlx->it);
}

void		mandel_norm_bs(t_mlx *mymlx, int x, int y)
{
	mymlx->cx = map(x, mymlx, mymlx->min_r, mymlx->max_r);
	mymlx->cy = map(y, mymlx, mymlx->min_i, mymlx->max_i);
	mymlx->px = mymlx->cx;
	mymlx->py = mymlx->cy;
}

void		image_clear(int *d)
{
	int	y;
	int x;

	y = 0;
	while (y < HEIGHT)
	{
		x = -1;
		while (x++ < WIDTH)
			d[y * WIDTH + x] = 0x000000;
		y++;
	}
}
