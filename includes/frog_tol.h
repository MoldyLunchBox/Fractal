/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frog_tol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amya <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 07:43:37 by amya              #+#    #+#             */
/*   Updated: 2020/01/07 07:43:40 by amya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FROG_TOL_H
# define FROG_TOL_H
# include <stdio.h>
# include <math.h>
# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include "../libft/libft.h"
# define WIDTH  600
# define HEIGHT 600
# define BPP 3
# define PSIZE (4 - (600 * 3) % 4) % 4
# define FILE_HEADER_SIZE 14
# define INFO_HEADER_SIZE 40

typedef struct	s_mlx
{
	int		i;
	int		j;
	double	min_r;
	double	max_r;
	double	min_i;
	double	max_i;
	int		max_it;
	double	factor;
	int		down;
	void	*ptr;
	void	*win;
	int		***cords;
	void	*img;
	int		*d;
	int		start;
	int		end;
	double	fx;
	double	fy;
	double	old_fx;
	double	old_fy;
	double	up;
	double	ang;
	double	line;
	double	tilt;
	double	twoab;
	double	cx;
	double	cy;
	int		it;
	double	aa;
	double	bb;
	double	px;
	double	py;
	double	in_min;
	double	in_max;
	int		dx;
	int		dy;
	int		sx;
	int		sy;
	int		key;
	int		color;
	int		limit;
	int		origin;
	int		len;
	int		started;
	int		r;
	int		g;
	int		b;
}				t_mlx;
void			switch_screens_rest(t_mlx *mlx, int key);
void			switch_screens(t_mlx *mlx, int key);
int				key_press(int key, t_mlx *mlx);
void			put_tree(t_mlx *mlx);
int				mouse_press(int button, int x, int y, t_mlx *mlx);
void			mouse_press_tree(t_mlx *mlx, int button);
int				mouse_move(int x, int y, t_mlx *mlx);
void			apply_zoom(t_mlx *mlx, double r, double i, double z_f);
void			*square(void *mlx);
void			print_error(char **av, int ac);
int				issierp(int x, int y);
void			*mandel(void *mlx);
void			mandel_norm_bs(t_mlx *mymlx, int x, int y);
int				iterations(t_mlx *mymlx);
void			fracs9_4(t_mlx *mymlx, int *radius);
void			fracs8_5(t_mlx *mymlx, int *radius);
void			fracs10_(t_mlx *mymlx, int *radius);
void			fracs1_(t_mlx *mymlx, int *radius);
void			*julia(void *mlx);
void			do_the_thing(t_mlx **mymlx);
void			while_loop(t_mlx *mymlx);
void			*julia(void *mlx);
void			*make_circle(void *mlx);
void			*spit_a_tree(void *mlx);
double			map(int value, t_mlx *mlx, double out_min, double out_max);
void			tree_rec(t_mlx *mlx, int originy, int originx, double angle);
int				make_color_range(t_mlx *mlx, int start, int end, int limit);
void			init_line_vars(t_mlx *mlx, int y0, int x1, int y1);
void			line(t_mlx *mlx, int y0, int x1, int y1);
void			image_clear(int *d);
void			init_mlx(t_mlx *mlx, int nbr);
void			init_main_stuff(t_mlx *mlx);
void			threading(t_mlx *mlx);
void			create_bitmap_file_h(int padding_s, FILE *imagefile);
void			create_bitmap_info_h(FILE *imagefile);
void			generate_bitmap_image(unsigned char *image, char *imagefname);
void			mouse_press_tree(t_mlx *mlx, int button);
void			init_static_char(unsigned char *str, int len);
void			screen_shot(t_mlx *mlx);
#endif
