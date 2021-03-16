/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amya <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 02:09:10 by amya              #+#    #+#             */
/*   Updated: 2020/01/07 02:22:11 by amya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/frog_tol.h"

void	screen_shot(t_mlx *mlx)
{
	unsigned char	image[HEIGHT][WIDTH][BPP];
	char			*imagefilename;
	int				i;
	int				j;

	imagefilename = "bitmapImage.bmp";
	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			mlx->r = (mlx->d[(HEIGHT * WIDTH - (i * WIDTH)) + j] >> 16) & 0xFF;
			mlx->g = (mlx->d[(HEIGHT * WIDTH - (i * WIDTH)) + j] >> 8) & 0xFF;
			mlx->b = (mlx->d[(HEIGHT * WIDTH - (i * WIDTH)) + j] >> 0) & 0xFF;
			image[i][j][2] = (unsigned char)mlx->r;
			image[i][j][1] = (unsigned char)mlx->g;
			image[i][j][0] = (unsigned char)mlx->b;
			j++;
		}
		i++;
	}
	generate_bitmap_image((unsigned char *)image, imagefilename);
	ft_putstr("\nscreenshot generated omg!!");
}

void	init_static_char(unsigned char *str, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		str[i] = 0;
		i++;
	}
}

void	generate_bitmap_image(unsigned char *image, char *imagefilename)
{
	unsigned char	padding[3];
	int				padding_s;
	FILE			*imagefile;
	int				i;

	padding_s = (4 - (WIDTH * BPP) % 4) % 4;
	imagefile = fopen(imagefilename, "w+");
	create_bitmap_file_h(padding_s, imagefile);
	create_bitmap_info_h(imagefile);
	init_static_char(padding, 3);
	i = 0;
	while (i < HEIGHT)
	{
		fwrite(image + (i * WIDTH * BPP), BPP, WIDTH, imagefile);
		fwrite(padding, 1, PSIZE, imagefile);
		i++;
	}
	fclose(imagefile);
}

void	create_bitmap_file_h(int padding_s, FILE *imagefile)
{
	int				file_size;
	unsigned char	file_header[14];

	file_size = FILE_HEADER_SIZE + INFO_HEADER_SIZE
	+ (BPP * WIDTH + padding_s) * HEIGHT;
	init_static_char(file_header, 14);
	file_header[0] = (unsigned char)('B');
	file_header[1] = (unsigned char)('M');
	file_header[2] = (unsigned char)(file_size);
	file_header[3] = (unsigned char)(file_size >> 8);
	file_header[4] = (unsigned char)(file_size >> 16);
	file_header[5] = (unsigned char)(file_size >> 24);
	file_header[10] = (unsigned char)(FILE_HEADER_SIZE + INFO_HEADER_SIZE);
	fwrite(file_header, 1, FILE_HEADER_SIZE, imagefile);
}

void	create_bitmap_info_h(FILE *imagefile)
{
	unsigned char	info_header[40];

	init_static_char(info_header, 40);
	info_header[0] = (unsigned char)(INFO_HEADER_SIZE);
	info_header[4] = (unsigned char)(WIDTH);
	info_header[5] = (unsigned char)(WIDTH >> 8);
	info_header[6] = (unsigned char)(WIDTH >> 16);
	info_header[7] = (unsigned char)(WIDTH >> 24);
	info_header[8] = (unsigned char)(HEIGHT);
	info_header[9] = (unsigned char)(HEIGHT >> 8);
	info_header[10] = (unsigned char)(HEIGHT >> 16);
	info_header[11] = (unsigned char)(HEIGHT >> 24);
	info_header[12] = (unsigned char)(1);
	info_header[14] = (unsigned char)(BPP * 8);
	fwrite(info_header, 1, INFO_HEADER_SIZE, imagefile);
}
