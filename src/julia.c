/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amya <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 02:08:41 by amya              #+#    #+#             */
/*   Updated: 2020/01/07 02:08:42 by amya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/frog_tol.h"

void		do_the_thing(t_mlx **mymlx)
{
	static double	oldx;
	static double	oldy;

	if (!(*mymlx)->up)
	{
		oldx = (*mymlx)->fx;
		oldy = (*mymlx)->fy;
	}
	else
	{
		(*mymlx)->fx = oldx;
		(*mymlx)->fy = oldy;
	}
}

void		while_loop(t_mlx *mymlx)
{
	mymlx->it = 0;
	while (mymlx->it < mymlx->max_it)
	{
		mymlx->aa = mymlx->cx * mymlx->cx;
		mymlx->bb = mymlx->cy * mymlx->cy;
		mymlx->twoab = 2.0 * mymlx->cx * mymlx->cy;
		mymlx->cx = mymlx->aa - mymlx->bb + mymlx->fx;
		mymlx->cy = mymlx->twoab + mymlx->fy;
		if (mymlx->aa + mymlx->bb > 4.0)
			break ;
		mymlx->it++;
	}
}

void		*julia(void *mlx)
{
	t_mlx	*mymlx;
	int		x;
	int		y;

	mymlx = (t_mlx *)mlx;
	x = mymlx->start;
	do_the_thing(&mymlx);
	while (x < mymlx->end)
	{
		y = 0;
		while (y < WIDTH)
		{
			mymlx->cx = map(x, mymlx, mymlx->min_r, mymlx->max_r);
			mymlx->cy = map(y, mymlx, mymlx->min_i, mymlx->max_i);
			while_loop(mymlx);
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
