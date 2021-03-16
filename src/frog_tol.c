/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frog_tol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amya <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 21:40:38 by amya              #+#    #+#             */
/*   Updated: 2019/12/31 18:26:13 by amya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/frog_tol.h"

void		threading(t_mlx *mlx)
{
	pthread_t	thread_id[4];
	t_mlx		mlxx[4];
	int			i;

	i = 0;
	while (i < 4)
	{
		ft_memcpy((void *)&mlxx[i], (void *)mlx, sizeof(t_mlx));
		mlx->start = WIDTH / 4 * i;
		mlx->end = WIDTH / 4 * i + (WIDTH / 4);
		if (mlx->key > 3 || mlx->key == 1)
			pthread_create(&thread_id[i], NULL, mandel, &mlxx[i]);
		if (mlx->key == 2)
			pthread_create(&thread_id[i], NULL, julia, &mlxx[i]);
		if (mlx->key == 0)
			pthread_create(&thread_id[i], NULL, square, &mlxx[i]);
		pthread_join(thread_id[i], NULL);
		i++;
	}
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img, 0, 0);
	if (mlx->started)
	{
		mlx->started = 0;
		threading(mlx);
	}
}

double		map(int value, t_mlx *mlx, double out_min, double out_max)
{
	return ((value - mlx->in_min) * (out_max - out_min)
	/ (mlx->in_max - mlx->in_min) + out_min);
}

double		interpolate(double start, double end, double interpolation)
{
	return (start + ((end - start) * interpolation));
}

void		apply_zoom(t_mlx *mlx, double r, double i, double z_f)
{
	double interpolation;

	interpolation = 1.0 / z_f;
	mlx->min_r = interpolate(r, mlx->min_r, interpolation);
	mlx->min_i = interpolate(i, mlx->min_i, interpolation);
	mlx->max_r = interpolate(r, mlx->max_r, interpolation);
	mlx->max_i = interpolate(i, mlx->max_i, interpolation);
}

int			main(int argc, char **arg)
{
	t_mlx	*mlx;
	int		bpp;

	print_error(arg, argc);
	mlx = (t_mlx *)malloc(sizeof(t_mlx));
	mlx->ptr = mlx_init();
	mlx->win = mlx_new_window(mlx->ptr, WIDTH, HEIGHT, "ok");
	mlx->img = mlx_new_image(mlx->ptr, WIDTH, HEIGHT);
	mlx->d = (int *)mlx_get_data_addr(mlx->img, &bpp, &bpp, &bpp);
	init_mlx(mlx, atoi(arg[1]));
	init_main_stuff(mlx);
	if (mlx->key == 3)
	{
		image_clear(mlx->d);
		tree_rec(mlx, HEIGHT, WIDTH / 2, 0);
	}
	if (mlx->key == 1 || mlx->key == 2 || mlx->key > 3 || mlx->key == 0)
		threading(mlx);
	mlx_hook(mlx->win, 2, 0, key_press, mlx);
	mlx_hook(mlx->win, 6, 0, mouse_move, mlx);
	mlx_mouse_hook(mlx->win, mouse_press, mlx);
	mlx_loop(mlx->ptr);
	return (0);
}
